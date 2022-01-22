//
// Created by tnwei on 1/16/2022.
//

#include "elk/common/keys.h"
#include "elk/kibana/models/saved_object_attributes.h"

std::string elk::SavedObjectAttributes::title() const {
  return get_string(TITLE);
}

void elk::SavedObjectAttributes::title(std::string &title) const {
  set(TITLE, title);
}
