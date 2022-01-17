//
// Created by tnwei on 1/16/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_MODELS_SAVED_OBJECT_ATTRIBUTES_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_MODELS_SAVED_OBJECT_ATTRIBUTES_H_

#include "common/model.h"

namespace elk {
class SavedObjectAttributes: public Model {
 public:
  //////////////////////////////////////////////////// CONSTRUCTORS ////////////////////////////////////////////////////
  explicit SavedObjectAttributes(std::string& response): Model(response) {}

  explicit SavedObjectAttributes(nlohmann::json& response): Model(response) {}

  explicit SavedObjectAttributes(std::shared_ptr<nlohmann::json> json, nlohmann::json::json_pointer basePointer): Model(std::move(json), std::move(basePointer)) {}

  ////////////////////////////////////////////////// SETTERS / GETTERS /////////////////////////////////////////////////
  [[nodiscard]] std::string title() const;

  void title(std::string& title) const;
};
}

#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_MODELS_SAVED_OBJECT_ATTRIBUTES_H_
