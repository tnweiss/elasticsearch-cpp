//
// Created by tnwei on 1/9/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_CREATEINDEXBODY_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_CREATEINDEXBODY_H_

#include "elk/common/model.h"

#include "elk/elasticsearch/models/index/index_mappings.h"

namespace elk {
//////////////////////////////////////////////////////// KEYS ////////////////////////////////////////////////////////
static const char* MAPPINGS = "mappings";

class CreateIndexBody: public Model {
  public:
  //////////////////////////////////////////////////// CONSTRUCTORS ////////////////////////////////////////////////////
  explicit CreateIndexBody(std::string& response): Model(response) {}

  explicit CreateIndexBody(nlohmann::json& response): Model(response) {}

  explicit CreateIndexBody(std::shared_ptr<nlohmann::json> json, nlohmann::json::json_pointer basePointer): Model(std::move(json), std::move(basePointer)) {}

  ////////////////////////////////////////////////// SETTERS / GETTERS /////////////////////////////////////////////////
  IndexMappings mappings();

  void mappings(IndexMappings& index_mappings);
};
}


#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_CREATEINDEXBODY_H_
