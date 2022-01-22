//
// Created by tnwei on 1/8/2022.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "elk/kibana/models/saved_object_type.h"
#include "elk/common/authentication.h"
#include "elk/common/utility.h"
#include "elk/elasticsearch/elasticsearch_client.h"
#include "elk/kibana/kibana_client.h"
#include "elk/elasticsearch/models/create_index_body.h"
#include "elk/elasticsearch/models/index/bulk_insert_body.h"

// TEST DATA
static const char* USERNAME = "elastic";
static const char* PASSWORD = "password";
static const char* ELASTIC_ORIGIN = "http://192.168.1.69:9200";
static const char* KIBANA_ORIGIN = "http://192.168.1.69:5601";
static const char* TESTBED_NAME = "testbed";
static const char* INDEX_NAME = "elk-cpp-test-index-";
static const char* INDEX_REQUEST_BODY = R"(
{
  "settings": {
    "number_of_shards": 1
  },
  "mappings": {
    "properties": {
      "test": { "type": "text" }
    }
  }
}
)";
static const char* INDEX_PATTERN_REQUEST_BODY = R"(
{
  "attributes": {
    "title": "elk-cpp-test-index-*"
  }
}
)";
static const char* INDEX_DATA = R"(
{
  "test": "Hello World"
}
)";

static const elk::ElkAuthentication& authentication() {
  static const elk::ElkAuthentication static_authentication(USERNAME, PASSWORD);
  return static_authentication;
}

static const elk::ElasticsearchClient& elastic_client() {
  static const elk::ElasticsearchClient static_elastic_client(ELASTIC_ORIGIN, authentication());
  return static_elastic_client;
}

static const elk::KibanaClient& kibana_client() {
  static const elk::KibanaClient static_kibana_client(KIBANA_ORIGIN, authentication());
  return static_kibana_client;
}

static const std::string& test_id() {
  // get the timestamp to append to data
  auto now = std::chrono::system_clock::now().time_since_epoch();
  auto currentSeconds = std::chrono::duration_cast<std::chrono::seconds>(now).count();

  static const std::string static_test_id = std::to_string(currentSeconds);
  return static_test_id;
}

static const std::string& test_index() {
  static const std::string static_test_index(INDEX_NAME + test_id());
  return static_test_index;
}

static const std::string& test_index_pattern() {
  static const std::string static_test_index_pattern(INDEX_NAME);
  return static_test_index_pattern;
}

static const elk::BulkInsertData& bulk_insert_data() {
  nlohmann::json d = nlohmann::json::parse(INDEX_DATA);
  static const elk::BulkInsertData static_bulk_insert_data(d);
  return static_bulk_insert_data;
}


TEST_CASE("ElasticsearchKibanaClientTest") {
  SECTION("SetLogLevel") {
    spdlog::set_level(spdlog::level::info);
  }

  SECTION("GetClusterDetails") {
    REQUIRE(elastic_client().get_cluster_details().name() == TESTBED_NAME);
  }

  SECTION("IndexExists") {
    REQUIRE(!elastic_client().index_exists(test_index().c_str()));
  }

  SECTION("IndexPatternExists") {
    REQUIRE(!kibana_client().saved_object_exists(elk::SavedObjectType::INDEX_PATTERN, test_index_pattern().c_str()));
  }

  SECTION("CreateIndex") {
    std::string req_body_str(INDEX_REQUEST_BODY);
    elk::CreateIndexBody req_body(req_body_str);
    elastic_client().create_index(test_index().c_str(), req_body);
    REQUIRE(elastic_client().index_exists(test_index().c_str()));
  }

  SECTION("CreateIndexPattern") {
    std::string create_index_pattern_body_str(INDEX_PATTERN_REQUEST_BODY);
    elk::CreateSavedObjectBody create_index_pattern_body(create_index_pattern_body_str);

    auto resp = kibana_client().create_saved_object(elk::SavedObjectType::INDEX_PATTERN,
                                                    test_index_pattern().c_str(),create_index_pattern_body);
    REQUIRE(kibana_client().saved_object_exists(elk::SavedObjectType::INDEX_PATTERN, test_index_pattern().c_str()));
  }

  SECTION("AddDataToIndex") {
    elk::BulkInsertBody request_body;
    request_body.create(bulk_insert_data());
    request_body.create(bulk_insert_data());
    request_body.create(bulk_insert_data());

    elastic_client().bulk_update_index(test_index().c_str(), request_body);
  }

  SECTION("DeleteIndexPattern") {
    kibana_client().delete_saved_object(elk::SavedObjectType::INDEX_PATTERN, test_index_pattern().c_str());
    REQUIRE(!kibana_client().saved_object_exists(elk::SavedObjectType::INDEX_PATTERN, test_index_pattern().c_str()));
  }

  SECTION("DeleteIndex") {
    elastic_client().delete_index(test_index().c_str());
    REQUIRE(!elastic_client().index_exists(test_index().c_str()));
  }
}

TEST_CASE("PostIndexModel") {
  auto body = nlohmann::json::parse(R"(
{
  "mappings": {
    "properties": {
      "age":    { "type": "integer" },
      "email":  { "type": "keyword"  },
      "name":   { "type": "text"  }
    }
  }
}
)");

  elk::CreateIndexBody post_body(body);

  REQUIRE(post_body.mappings().properties().get_property("age").type() == IndexType::INTEGER);
  REQUIRE(post_body.mappings().properties().get_property("email").type() == IndexType::KEYWORD);
  REQUIRE(post_body.mappings().properties().get_property("name").type() == IndexType::TEXT);
}

TEST_CASE("BulkInsertBody") {
  elk::BulkInsertBody body;
  auto data_json = R"(
{"test": "testVal"}
)"_json;
  elk::BulkInsertData data(data_json);

  body.create("test", "test", data);
  body.create("test", "test1", data);

  //std::cout << body.to_x_ndjson() << std::endl;
}

TEST_CASE("UUID") {
  REQUIRE(!elk::uuid().empty());
}

TEST_CASE("ClusterDetailsModel") {
  auto cluster_details_json = R"(
{
  "name": "test_cluster",
  "cluster_name": "elasticsearch"
}
)"_json;

  elk::ClusterDetails cluster_details(cluster_details_json);

  REQUIRE(cluster_details.name() == "test_cluster");
  REQUIRE(cluster_details.cluster_name() == "elasticsearch");
}

TEST_CASE("BulkInsertBodyModel") {
  auto insert_data = R"(
{
  "test": "test data"
}
)"_json;
  std::string output_json(R"({"create":{"_id":"1234","_index":"test"}}
{"test":"test data"}
)");

  elk::BulkInsertData data(insert_data);

  elk::BulkInsertBody insert_body;

  insert_body.create("test", "1234", data);

  REQUIRE(insert_body.to_x_ndjson() == output_json);
}