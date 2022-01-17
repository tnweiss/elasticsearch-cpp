//
// Created by tnwei on 1/8/2022.
//

#define CATCH_CONFIG_MAIN
#include "catch2.hpp"

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

TEST_CASE("ElasticsearchClientTest") {
  // create the clients
  const elk::ElkAuthentication auth(USERNAME, PASSWORD);
  const elk::ElasticsearchClient elastic_client(ELASTIC_ORIGIN, auth);
  const elk::KibanaClient kibana_client(KIBANA_ORIGIN, auth);

  // get the timestamp to append to data
  auto now = std::chrono::system_clock::now().time_since_epoch();
  auto currentSeconds = std::chrono::duration_cast<std::chrono::seconds>(now).count();

  // create the test index
  std::string test_index(INDEX_NAME );
  test_index.append(std::to_string(currentSeconds));

  SECTION("ClusterDetails") {
    REQUIRE(elastic_client.get_cluster_details().name() == TESTBED_NAME);
  }

  SECTION("IndexNotExists") {
    REQUIRE(!elastic_client.index_exists(test_index.c_str()));
  }

  SECTION("CreateIndex") {
    std::string req_body_str(INDEX_REQUEST_BODY);
    elk::CreateIndexBody req_body(req_body_str);
    elastic_client.create_index(test_index.c_str(), req_body);
    REQUIRE(elastic_client.index_exists(test_index.c_str()));
  }

//  SECTION("CreateIndexPattern") {
//
//  }

  SECTION("DeleteIndex") {
    elastic_client.delete_index(test_index.c_str());
    REQUIRE(!elastic_client.index_exists(test_index.c_str()));
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