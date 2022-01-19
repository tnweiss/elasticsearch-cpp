//
// Created by tnwei on 1/15/2022.
//

#include "elk/elasticsearch/models/index/index_mapping_properties.h"

elk::PropertyValue elk::IndexMappingProperties::get_property(const char *property) {
  return Model::get_object<PropertyValue>(property);
}

void elk::IndexMappingProperties::set_property(const char *property, elk::PropertyValue value) {
  set(property, value);
}
