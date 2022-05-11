//
// Created by tnwei on 1/8/2022.
//

#ifndef BENCHMARKR_SRC_BENCHMARKR_ELASTIC_RESPONSES_CLUSTER_DETAILS_H_
#define BENCHMARKR_SRC_BENCHMARKR_ELASTIC_RESPONSES_CLUSTER_DETAILS_H_

#include <string>
#include <utility>

#include "elk/external/nlohmann/json.hpp"

#include "elk/common/model.h"

#include "elk/elasticsearch/models/version.h"


namespace elk {

//////////////////////////////////////////////////////// KEYS ////////////////////////////////////////////////////////
static const char* NAME = "name";
static const char* CLUSTER_NAME = "cluster_name";
static const char* CLUSTER_UUID = "cluster_uuid";
static const char* VERSION= "version";
static const char* TAGLINE= "tagline";


class ClusterDetails: public Model {
 public:
  //////////////////////////////////////////////////// CONSTRUCTORS ////////////////////////////////////////////////////
  explicit ClusterDetails(std::string& response): Model(response) {}

  explicit ClusterDetails(nlohmann::json& response): Model(response) {}

  explicit ClusterDetails(std::shared_ptr<nlohmann::json> json, nlohmann::json::json_pointer basePointer): Model(std::move(json), std::move(basePointer)) {}

  ////////////////////////////////////////////////// SETTERS / GETTERS /////////////////////////////////////////////////
  [[nodiscard]] std::string name() const;

  void name(std::string& name) const;

  [[nodiscard]] std::string cluster_name() const;

  void cluster_name(std::string& cluster_name) const;

  [[nodiscard]] std::string cluster_uuid() const;

  void cluster_uuid(std::string& cluster_uuid) const;

  [[nodiscard]] elk::Version version() const;

  void version(elk::Version version) const;

  [[nodiscard]] std::string tagline() const;

  void tagline(std::string& tagline) const;
};
}
#endif //BENCHMARKR_SRC_BENCHMARKR_ELASTIC_RESPONSES_CLUSTER_DETAILS_H_
