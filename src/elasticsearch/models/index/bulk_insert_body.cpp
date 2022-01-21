//
// Created by tnwei on 1/19/2022.
//

#include "elk/elasticsearch/models/index/bulk_insert_body.h"
#include "elk/elasticsearch/models/index/bulk_insert_action.h"
#include "elk/common/utility.h"

elk::BulkInsertBody::BulkInsertBody():
  _data(std::make_unique<std::vector<std::unique_ptr<elk::Model>>>(std::vector<std::unique_ptr<elk::Model>>())) {

}

void elk::BulkInsertBody::create(const char *index, const char *id, const elk::BulkInsertData& data) const {
  elk::BulkInsertAction action(IndexAction::CREATE_ACTION);

  std::string index_str(index);
  action.index(index_str);

  std::string id_str(id);
  action.id(id_str);

  _data->push_back(std::make_unique<elk::BulkInsertAction>(action));
  _data->push_back(std::make_unique<elk::BulkInsertData>(data));
}

std::string elk::BulkInsertBody::to_x_ndjson() const {
  std::string ret_val;

  for (std::unique_ptr<elk::Model>& m: *_data) {
    ret_val += m->to_string();
    ret_val.append("\n");
  }

  return ret_val;
}

void elk::BulkInsertBody::create(const elk::BulkInsertData &data) const {
  elk::BulkInsertAction action(IndexAction::CREATE_ACTION);

  std::string id_str = elk::uuid();
  action.id(id_str);

  _data->push_back(std::make_unique<elk::BulkInsertAction>(action));
  _data->push_back(std::make_unique<elk::BulkInsertData>(data));
}
