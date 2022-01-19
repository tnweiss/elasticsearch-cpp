//
// Created by tnwei on 1/8/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_ACTIONS_CLUSTER_DETAILS_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_ACTIONS_CLUSTER_DETAILS_H_

#include "string"
#include "elk/common/authentication.h"
#include "elk/elasticsearch/models/cluster_details.h"

namespace elk {
/**
 * Fetches cluster details
 * @param origin elasticsearch origin
 * @param auth elasticsearch authentication
 * @return
 */
elk::ClusterDetails get_cluster_details_actions(const std::string& origin, const elk::ElkAuthentication& auth);
}


#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_ACTIONS_CLUSTER_DETAILS_H_
