//
// Created by tnwei on 1/8/2022.
//

#define CATCH_CONFIG_MAIN
#include "catch2.hpp"

#include "common/authentication.h"
#include "elasticsearch/elasticsearch_client.h"
#include "elasticsearch/models/create_index_body.h"

// TEST DATA
static const char* USERNAME = "elastic";
static const char* PASSWORD = "password";
static const char* ORIGIN = "http://192.168.1.69:9200";
static const char* TESTBED_NAME = "testbed";
static const char* INDEX_NAME = "elk-cpp-test-index-";

TEST_CASE("ElasticsearchClientTest") {
  // create the client
  const elk::ElkAuthentication auth(USERNAME, PASSWORD);
  const elk::ElasticsearchClient client(ORIGIN, auth);

  // get the timestamp to append to data
  auto now = std::chrono::system_clock::now().time_since_epoch();
  auto currentSeconds = std::chrono::duration_cast<std::chrono::seconds>(now).count();

  // create the test index
  std::string test_index(INDEX_NAME );
  test_index.append(std::to_string(currentSeconds));

  SECTION("ClusterDetails") {
    REQUIRE(client.get_cluster_details().name() == TESTBED_NAME);
  }

  SECTION("IndexNotExists") {
    REQUIRE(!client.index_exists(test_index.c_str()));
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

  elk::CreateIndexBody postbody(body);

  std::cout << magic_enum::enum_name(postbody.mappings().properties().get_property("age").type()) << std::endl;
}