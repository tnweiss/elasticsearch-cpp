//
// Created by tnwei on 1/19/2022.
//

#ifndef ELK_CLIENT_INCLUDE_ELK_ELASTICSEARCH_MODELS_INDEX_BULK_INSERT_DATA_H_
#define ELK_CLIENT_INCLUDE_ELK_ELASTICSEARCH_MODELS_INDEX_BULK_INSERT_DATA_H_

#include "elk/common/model.h"

namespace elk {

class BulkInsertData: public Model {
 public:
  //////////////////////////////////////////////////// CONSTRUCTORS ////////////////////////////////////////////////////
  explicit BulkInsertData(std::string& response): Model(response) {}

  explicit BulkInsertData(nlohmann::json& response): Model(response) {}

  explicit BulkInsertData(std::shared_ptr<nlohmann::json> json, nlohmann::json::json_pointer basePointer): Model(std::move(json), std::move(basePointer)) {}
};

}
#endif //ELK_CLIENT_INCLUDE_ELK_ELASTICSEARCH_MODELS_INDEX_BULK_INSERT_DATA_H_
