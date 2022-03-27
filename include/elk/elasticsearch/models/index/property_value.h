//
// Created by tnwei on 1/15/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_INDEX_PROPERTY_VALUE_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_INDEX_PROPERTY_VALUE_H_

#include "elk/common/model.h"

#include "elk/elasticsearch/models/index_types.h"

namespace elk {
//////////////////////////////////////////////////////// KEYS ////////////////////////////////////////////////////////

class PropertyValue: public Model {
 public:
  //////////////////////////////////////////////////// CONSTRUCTORS ////////////////////////////////////////////////////
  explicit PropertyValue(std::string& response): Model(response) {}

  explicit PropertyValue(nlohmann::json& response): Model(response) {}

  explicit PropertyValue(std::shared_ptr<nlohmann::json> json, nlohmann::json::json_pointer basePointer): Model(std::move(json), std::move(basePointer)) {}

  ////////////////////////////////////////////////// SETTERS / GETTERS /////////////////////////////////////////////////
  IndexType type();

  void type(IndexType& type);

  bool index();

  void index(bool index);
};
}


#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_INDEX_PROPERTY_VALUE_H_
