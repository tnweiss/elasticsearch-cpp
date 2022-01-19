//
// Created by tnwei on 1/16/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_MODELS_CREATE_SAVED_OBJECT_RESPONSE_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_MODELS_CREATE_SAVED_OBJECT_RESPONSE_H_

#include "common/model.h"
#include "saved_object_attributes.h"

namespace elk {
class CreateSavedObjectResponse: public Model {
 public:
  //////////////////////////////////////////////////// CONSTRUCTORS ////////////////////////////////////////////////////
  explicit CreateSavedObjectResponse(std::string& response): Model(response) {}

  explicit CreateSavedObjectResponse(nlohmann::json& response): Model(response) {}

  explicit CreateSavedObjectResponse(std::shared_ptr<nlohmann::json> json, nlohmann::json::json_pointer basePointer): Model(std::move(json), std::move(basePointer)) {}

  ////////////////////////////////////////////////// SETTERS / GETTERS /////////////////////////////////////////////////
  [[nodiscard]] SavedObjectAttributes attributes() const;

  void attributes(SavedObjectAttributes& attributes) const;

  [[nodiscard]] std::string id() const;

  void id(std::string& id) const;
};
}

#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_MODELS_CREATE_SAVED_OBJECT_RESPONSE_H_
