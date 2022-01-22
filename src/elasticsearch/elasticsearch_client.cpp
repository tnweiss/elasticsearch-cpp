//
// Created by tnwei on 1/8/2022.
//

#include "elk/elasticsearch/elasticsearch_client.h"

#include "elk/elasticsearch/actions/cluster_details.h"
#include "elk/elasticsearch/actions/index.h"


elk::ElasticsearchClient::ElasticsearchClient(): ElasticsearchClient(elk::DEFAULT_ELASTIC_ORIGIN) { }

elk::ElasticsearchClient::ElasticsearchClient(const char *origin):
  ElasticsearchClient(origin, elk::ElkAuthentication()) { }

elk::ElasticsearchClient::ElasticsearchClient(const elk::ElkAuthentication& authentication):
  ElasticsearchClient(elk::DEFAULT_ELASTIC_ORIGIN, authentication){ }

elk::ElasticsearchClient::ElasticsearchClient(const char *origin, const elk::ElkAuthentication& authentication):
  _origin(origin), _authentication(authentication) { }

elk::ClusterDetails elk::ElasticsearchClient::get_cluster_details() const {
  return get_cluster_details_actions(_origin, _authentication);
}

bool elk::ElasticsearchClient::index_exists(const char *target) const {
  return index_exists_action(_origin, _authentication, target);
}

void elk::ElasticsearchClient::create_index(const char *target, elk::CreateIndexBody &request_body) const {
  return create_index_action(_origin, _authentication, target, request_body);
}

void elk::ElasticsearchClient::delete_index(const char* target) const {
  return delete_index_action(_origin, _authentication, target);
}

void elk::ElasticsearchClient::bulk_update_index(const char *target, elk::BulkInsertBody &request_body) const {
  return bulk_update_index_action(_origin, _authentication, target, request_body);
}
