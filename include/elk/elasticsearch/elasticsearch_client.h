//
// Created by tnwei on 1/8/2022.
//

#ifndef ELASTICSEARCH_CPP_SRC_ELASTICSEARCH_CLIENT_ELASTIC_CLIENT_H_
#define ELASTICSEARCH_CPP_SRC_ELASTICSEARCH_CLIENT_ELASTIC_CLIENT_H_

#include <string>

#include "elk/common/authentication.h"

#include "elk/elasticsearch/models/cluster_details.h"
#include "elk/elasticsearch/models/create_index_body.h"
#include "elk/elasticsearch/models/index/bulk_insert_body.h"

namespace elk {

static const char* DEFAULT_ELASTIC_ORIGIN = "http://localhost:9200";

class ElasticsearchClient {
 public:
  /**
   * Default constructor, configure for default origin and no auth
   */
  ElasticsearchClient();

  /**
   * Constructor that overrides the origin
   * @param origin origin of the elastic server
   */
  explicit ElasticsearchClient(const char* origin);

  /**
   * Constructor that overrides the authenticaiton
   * @param authentication
   */
  explicit ElasticsearchClient(const elk::ElkAuthentication& authentication);

  /**
   * Initialize the client with an origin and auth
   * @param origin
   * @param authentication
   */
  ElasticsearchClient(const char* origin, const elk::ElkAuthentication&  authentication);

  /**
   * Get cluster details
   * @return
   */
  [[nodiscard]] ClusterDetails get_cluster_details() const;

  /**
   * Check to see that the target index exists
   * https://www.elastic.co/guide/en/elasticsearch/reference/current/indices-exists.html
   * @param target the index id
   * @return
   */
  bool index_exists(const char* target) const;

  /**
   * Create an index
   * https://www.elastic.co/guide/en/elasticsearch/reference/current/indices-create-index.html
   * @param target the index id
   * @param request_body index body request body
   */
  void create_index(const char* target, elk::CreateIndexBody& request_body) const;

  /**
   * Delete an index
   * @param target
   */
  void delete_index(const char* target) const;

  /**
   *
   * @param target
   * @param request_body
   */
  void bulk_update_index(const char* target, elk::BulkInsertBody& request_body) const;
 private:
  const std::string _origin;
  const elk::ElkAuthentication& _authentication;
};
}


#endif //ELASTICSEARCH_CPP_SRC_ELASTICSEARCH_CLIENT_ELASTIC_CLIENT_H_
