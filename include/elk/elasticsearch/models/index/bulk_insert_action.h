//
// Created by tnwei on 1/19/2022.
//

#ifndef ELK_CLIENT_INCLUDE_ELK_ELASTICSEARCH_MODELS_INDEX_BULK_INSERT_ACTION_H_
#define ELK_CLIENT_INCLUDE_ELK_ELASTICSEARCH_MODELS_INDEX_BULK_INSERT_ACTION_H_

#include "elk/common/model.h"
#include "elk/common/keys.h"

#include "elk/elasticsearch/models/index/index_actions.h"

namespace elk {

/**
 *
 * @param index_action
 * @param sub_path
 * @return
 */
std::string create_key(IndexAction index_action, const char* sub_path);

class BulkInsertAction: public Model {
 public:
  //////////////////////////////////////////////////// CONSTRUCTORS ////////////////////////////////////////////////////
  explicit BulkInsertAction(IndexAction index_action):
    _index_key(create_key(index_action, INDEX_)),
    _id_key(create_key(index_action, ID_)),
    Model(DEFAULT_JSON) {}

  explicit BulkInsertAction(IndexAction index_action, std::string& response):
    _index_key(create_key(index_action, INDEX_)),
    _id_key(create_key(index_action, ID_)),
    Model(response) {}

  explicit BulkInsertAction(IndexAction index_action, nlohmann::json& response):
    _index_key(create_key(index_action, INDEX_)),
    _id_key(create_key(index_action, ID_)),
    Model(response) {}

  explicit BulkInsertAction(IndexAction index_action, std::shared_ptr<nlohmann::json> json, nlohmann::json::json_pointer basePointer):
    _index_key(create_key(index_action, INDEX_)),
    _id_key(create_key(index_action, ID_)),
    Model(std::move(json), std::move(basePointer)) {}

  ////////////////////////////////////////////////// SETTERS / GETTERS /////////////////////////////////////////////////
  [[nodiscard]] std::string id() const;

  void id(std::string& id) const;

  [[nodiscard]] std::string index() const;

  void index(std::string& index) const;

 private:
  const std::string _id_key;
  const std::string _index_key;
};
}
#endif //ELK_CLIENT_INCLUDE_ELK_ELASTICSEARCH_MODELS_INDEX_BULK_INSERT_ACTION_H_
