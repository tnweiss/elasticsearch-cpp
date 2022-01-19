//
// Created by tnwei on 1/16/2022.
//

#include "kibana/models/create_saved_object_body.h"
#include "common/keys.h"

elk::SavedObjectAttributes elk::CreateSavedObjectBody::attributes() const {
  return get_object<SavedObjectAttributes>(ATTRIBUTES);
}

void elk::CreateSavedObjectBody::attributes(elk::SavedObjectAttributes &attributes) const {
  set(ATTRIBUTES, attributes);
}
