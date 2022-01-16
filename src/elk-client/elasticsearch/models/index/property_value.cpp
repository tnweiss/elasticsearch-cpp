//
// Created by tnwei on 1/15/2022.
//

#include "property_value.h"

IndexTypes elk::PropertyValue::type() {
  return Model::get_enum<IndexTypes>(TYPE);
}

void elk::PropertyValue::type(IndexTypes &type) {
  Model::set_enum<IndexTypes>(TYPE, type);
}

bool elk::PropertyValue::index() {
  return Model::get_bool(INDEX);
}

void elk::PropertyValue::index(bool index) {
  Model::set(INDEX, index);
}
