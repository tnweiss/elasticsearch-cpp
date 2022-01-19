//
// Created by tnwei on 1/14/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_VERSION_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_VERSION_H_

#include <utility>

#include "string"
#include "elk/common/model.h"

namespace elk {

//////////////////////////////////////////////////////// KEYS ////////////////////////////////////////////////////////
static const char* NUMBER = "number";
static const char* BUILD_FLAVOR = "default";
static const char* BUILD_TYPE = "build_type";
static const char* BUILD_HASH = "build_hash";
static const char* BUILD_DATE = "build_date";
static const char* BUILD_SNAPSHOT = "build_snapshot";
static const char* LUCENE_VERSION = "lucene_version";
static const char* MINIMUM_WIRE_COMPATIBILITY_VERSION = "minimum_wire_compatibility_version";
static const char* MINIMUM_INDEX_COMPATIBILITY_VERSION = "minimum_index_compatibility_version";

class Version: public Model {
 public:
  //////////////////////////////////////////////////// CONSTRUCTORS ////////////////////////////////////////////////////
  explicit Version(std::string& response): Model(response) {}

  explicit Version(nlohmann::json& response): Model(response) {}

  Version(std::shared_ptr<nlohmann::json> json, nlohmann::json::json_pointer basePointer): Model(std::move(json), std::move(basePointer)) {}

  ////////////////////////////////////////////////// SETTERS / GETTERS /////////////////////////////////////////////////
  [[nodiscard]] std::string number() const;

  void number(std::string& number) const;

  [[nodiscard]] std::string build_flavor() const;

  void build_flavor(std::string& build_flavor) const;

  [[nodiscard]] std::string build_type() const;

  void build_type(std::string& build_type) const;

  [[nodiscard]] std::string build_hash() const;

  void build_hash(std::string& build_hash) const;

  [[nodiscard]] std::string build_date() const;

  void build_date(std::string& build_date) const;

  [[nodiscard]] bool build_snapshot() const;

  void build_snapshot(bool build_snapshot) const;

  [[nodiscard]] std::string lucene_version() const;

  void lucene_version(std::string& lucene_version) const;

  [[nodiscard]] std::string minimum_wire_compatibility_version() const;

  void minimum_wire_compatibility_version(std::string& minimum_wire_compatibility_version) const;

  [[nodiscard]] std::string minimum_index_compatibility_version() const;

  void minimum_index_compatibility_version(std::string& minimum_index_compatibility_version) const;
};
}


#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_VERSION_H_
