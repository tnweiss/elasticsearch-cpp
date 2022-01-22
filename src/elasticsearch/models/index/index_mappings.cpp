//
// Created by tnwei on 1/15/2022.
//

#include "elk/elasticsearch/models/index/index_mappings.h"

elk::IndexMappingProperties elk::IndexMappings::properties() const {
  return get_object<IndexMappingProperties>(PROPERTIES);
}

void elk::IndexMappings::properties(elk::IndexMappingProperties &value) const {
  set(PROPERTIES, value);
}
