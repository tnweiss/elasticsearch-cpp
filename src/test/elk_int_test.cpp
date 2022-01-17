//
// Created by tnwei on 1/8/2022.
//

#define CATCH_CONFIG_MAIN
#include "catch2.hpp"

#include "kibana/models/saved_object_type.h"
#include "common/authentication.h"
#include "elasticsearch/elasticsearch_client.h"
#include "kibana/kibana_client.h"
#include "elasticsearch/models/create_index_body.h"

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


TEST_CASE("ElasticsearchKibanaClientTest") {
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