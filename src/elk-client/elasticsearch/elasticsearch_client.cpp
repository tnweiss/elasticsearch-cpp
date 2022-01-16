//
// Created by tnwei on 1/8/2022.
//

#include "elasticsearch_client.h"

#include <utility>

#include "elasticsearch/actions/cluster_details.h"
#include "elasticsearch/actions/index.h"


elk::ElasticsearchClient::ElasticsearchClient(): ElasticsearchClient(elk::DEFAULT_ORIGIN) { }

elk::ElasticsearchClient::ElasticsearchClient(const char *origin):
  ElasticsearchClient(origin, elk::ElkAuthentication()) { }

elk::ElasticsearchClient::ElasticsearchClient(const elk::ElkAuthentication& authentication):
  ElasticsearchClient(elk::DEFAULT_ORIGIN, authentication){ }

elk::ElasticsearchClient::ElasticsearchClient(const char *origin, const elk::ElkAuthentication& authentication):
  _origin(origin), _authentication(authentication) { }

elk::ClusterDetails elk::ElasticsearchClient::get_cluster_details() const {
  return get_cluster_details_actions(_origin, _authentication);
}

bool elk::ElasticsearchClient::index_exists(const char *target) const {
  return index_exists_action(_origin, _authentication, target);
}

