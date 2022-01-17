//
// Created by tnwei on 1/9/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_ACTIONS_INDEX_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_ACTIONS_INDEX_H_

#include "string"
#include "common/authentication.h"
#include "elasticsearch/models/create_index_body.h"

/**
 * Returns true if the index exists, false if it does not
 * https://www.elastic.co/guide/en/elasticsearch/reference/current/indices-exists.html
 * @param origin elasticsearch origin
 * @param authentication elasticsearch authentication
 * @param target target index name
 * @return
 */
bool index_exists_action(const std::string& origin, const elk::ElkAuthentication& authentication, const char* target);

/**
 * Creates an index
 * https://www.elastic.co/guide/en/elasticsearch/reference/current/indices-create-index.html
 * @param origin elasticsearch origin
 * @param authentication elasticsearch authentication
 * @param target index name
 * @param request_body request body
 */
void create_index_action(const std::string& origin, const elk::ElkAuthentication& authentication, const char* target,
                         const elk::CreateIndexBody& request_body);

/**
 * Delete an index
 * https://www.elastic.co/guide/en/elasticsearch/reference/current/indices-create-index.html
 * @param origin elasticsearch origin
 * @param authentication elasticsearch authentication
 * @param target index name
 */
void delete_index_action(const std::string& origin, const elk::ElkAuthentication& authentication, const char* target);

#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_ACTIONS_INDEX_H_
