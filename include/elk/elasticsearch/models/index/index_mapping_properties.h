//
// Created by tnwei on 1/15/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_INDEX_INDEX_MAPPING_PROPERTIES_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_INDEX_INDEX_MAPPING_PROPERTIES_H_

#include "property_value.h"

namespace elk {

//////////////////////////////////////////////////////// KEYS ////////////////////////////////////////////////////////

class IndexMappingProperties: public Model {
 public:
  //////////////////////////////////////////////////// CONSTRUCTORS ////////////////////////////////////////////////////
  explicit IndexMappingProperties(std::string& response): Model(response) {}

  explicit IndexMappingProperties(nlohmann::json& response): Model(response) {}

  explicit IndexMappingProperties(std::shared_ptr<nlohmann::json> json, nlohmann::json::json_pointer basePointer): Model(std::move(json), std::move(basePointer)) {}

  ////////////////////////////////////////////////// SETTERS / GETTERS /////////////////////////////////////////////////
  elk::PropertyValue get_property(const char* property);

  void set_property(const char* property, PropertyValue value);
};
}


#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_INDEX_INDEX_MAPPING_PROPERTIES_H_
