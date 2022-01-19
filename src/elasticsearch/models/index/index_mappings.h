//
// Created by tnwei on 1/15/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_INDEX_INDEX_MAPPINGS_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_INDEX_INDEX_MAPPINGS_H_

#include "common/model.h"
#include "index_mapping_properties.h"

namespace elk {

//////////////////////////////////////////////////////// KEYS ////////////////////////////////////////////////////////
static const char* PROPERTIES = "properties";

class IndexMappings: public Model {
 public:
  //////////////////////////////////////////////////// CONSTRUCTORS ////////////////////////////////////////////////////
  explicit IndexMappings(std::string& response): Model(response) {}

  explicit IndexMappings(nlohmann::json& response): Model(response) {}

  explicit IndexMappings(std::shared_ptr<nlohmann::json> json, nlohmann::json::json_pointer basePointer): Model(std::move(json), std::move(basePointer)) {}

  ////////////////////////////////////////////////// SETTERS / GETTERS /////////////////////////////////////////////////
  [[nodiscard]] IndexMappingProperties properties() const;

  void properties(IndexMappingProperties& value) const;
};
}


#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_INDEX_INDEX_MAPPINGS_H_
