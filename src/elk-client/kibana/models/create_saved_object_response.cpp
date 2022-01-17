//
// Created by tnwei on 1/16/2022.
//

#include "common/keys.h"
#include "create_saved_object_response.h"

elk::SavedObjectAttributes elk::CreateSavedObjectResponse::attributes() const {
  return get_object<elk::SavedObjectAttributes>(ATTRIBUTES);
}

void elk::CreateSavedObjectResponse::attributes(elk::SavedObjectAttributes &attributes) const {
  set(ATTRIBUTES, attributes);
}

std::string elk::CreateSavedObjectResponse::id() const {
  return get_string(ID);
}

void elk::CreateSavedObjectResponse::id(std::string &id) const {
  set(ID, id);
}
