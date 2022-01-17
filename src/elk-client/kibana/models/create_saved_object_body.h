//
// Created by tnwei on 1/16/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_MODELS_CREATE_SAVED_OBJECT_BODY_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_MODELS_CREATE_SAVED_OBJECT_BODY_H_

#include "common/model.h"
#include "kibana/models/saved_object_attributes.h"

namespace elk {
class CreateSavedObjectBody: public Model {
 public:
  //////////////////////////////////////////////////// CONSTRUCTORS ////////////////////////////////////////////////////
  explicit CreateSavedObjectBody(std::string& response): Model(response) {}

  explicit CreateSavedObjectBody(nlohmann::json& response): Model(response) {}

  explicit CreateSavedObjectBody(std::shared_ptr<nlohmann::json> json, nlohmann::json::json_pointer basePointer): Model(std::move(json), std::move(basePointer)) {}

  ////////////////////////////////////////////////// SETTERS / GETTERS /////////////////////////////////////////////////
  [[nodiscard]] SavedObjectAttributes attributes() const;

  void attributes(SavedObjectAttributes& attributes) const;
};
}


#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_MODELS_CREATE_SAVED_OBJECT_BODY_H_
