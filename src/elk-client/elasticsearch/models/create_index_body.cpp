//
// Created by tnwei on 1/9/2022.
//

#include "create_index_body.h"

elk::IndexMappings elk::CreateIndexBody::mappings() {
  return get_object<IndexMappings>(MAPPINGS);
}

void elk::CreateIndexBody::mappings(elk::IndexMappings &index_mappings) {
  set(MAPPINGS, index_mappings);
}
