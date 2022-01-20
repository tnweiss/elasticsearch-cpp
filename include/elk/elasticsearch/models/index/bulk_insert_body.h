//
// Created by tnwei on 1/19/2022.
//

#ifndef ELK_CLIENT_INCLUDE_ELK_ELASTICSEARCH_MODELS_INDEX_BULK_INSERT_BODY_H_
#define ELK_CLIENT_INCLUDE_ELK_ELASTICSEARCH_MODELS_INDEX_BULK_INSERT_BODY_H_

#include <memory>
#include <vector>

#include "nlohmann/json.hpp"
#include "elk/common/model.h"
#include "elk/elasticsearch/models/index/bulk_insert_action.h"
#include "elk/elasticsearch/models/index/bulk_insert_data.h"

namespace elk {

class BulkInsertBody {
 public:
  /**
   *
   */
  BulkInsertBody();

  /**
   *
   * @param index
   * @param id
   * @param data
   */
  void create(const char* index, const char* id, elk::BulkInsertData& data) const;

  /**
   *
   * @return
   */
  [[nodiscard]] std::string to_x_ndjson() const;

 private:
  const std::unique_ptr<std::vector<std::unique_ptr<elk::Model>>> _data;
};

}
#endif //ELK_CLIENT_INCLUDE_ELK_ELASTICSEARCH_MODELS_INDEX_BULK_INSERT_BODY_H_
