//
// Created by tnwei on 1/19/2022.
//

#include "elk/elasticsearch/models/index/bulk_insert_action.h"


std::string elk::create_key(IndexAction index_action, const char* sub_path) {
  // parse the enum into a string
  std::string action_str(magic_enum::enum_name(index_action));

  // convert to lowercase
  transform(action_str.begin(), action_str.end(), action_str.begin(), ::tolower);

  // replace the _action suffix with an empty string
  action_str.replace(action_str.find("_action"), sizeof("_action") - 1, "");

  // create the full path to the resource
  return "/" + action_str + "/" + sub_path;
}

std::string elk::BulkInsertAction::id() const {
  return get_string(_id_key.c_str());
}

void elk::BulkInsertAction::id(std::string &id) const {
  set(_id_key.c_str(), id);
}

std::string elk::BulkInsertAction::index() const {
  return get_string(_index_key.c_str());
}

void elk::BulkInsertAction::index(std::string &index) const {
  set(_index_key.c_str(), index);
}
