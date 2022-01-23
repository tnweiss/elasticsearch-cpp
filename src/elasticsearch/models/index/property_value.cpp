//
// Created by tnwei on 1/15/2022.
//

#include "elk/elasticsearch/models/index/property_value.h"

#include "elk/common/keys.h"


IndexType elk::PropertyValue::type() {
  // get the lowercase string
  std::string str_val = get_string(TYPE);

  // convert it to uppercase
  transform(str_val.begin(), str_val.end(), str_val.begin(), ::toupper);

  // return the value
  return get_enum<IndexType>(str_val);
}

void elk::PropertyValue::type(IndexType &type) {
  // get the string value from the enum
  std::string str_val = std::string(magic_enum::enum_name(type));

  // convert it to lowercase
  transform(str_val.begin(), str_val.end(), str_val.begin(), ::tolower);

  // set the value
  Model::set_enum<IndexType>(TYPE, type);
}

bool elk::PropertyValue::index() {
  return Model::get_bool(INDEX);
}

void elk::PropertyValue::index(bool index) {
  Model::set(INDEX, index);
}
