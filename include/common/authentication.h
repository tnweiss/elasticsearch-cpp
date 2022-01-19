//
// Created by tnwei on 1/8/2022.
//

#ifndef ELASTICSEARCH_CPP_CLIENT_SRC_ELK_CLIENT_COMMON_AUTHORIZATION_H_
#define ELASTICSEARCH_CPP_CLIENT_SRC_ELK_CLIENT_COMMON_AUTHORIZATION_H_

#include "cpr/cpr.h"

namespace elk {

/**
 * AuthTypes pulled from
 * https://www.elastic.co/guide/en/elasticsearch/reference/current/http-clients.html
 */
enum AuthType {
  NONE = 0,
  BASIC = 1,
  BEARER = 2
};
static const char* AuthTypeStr[] = {"None", "Basic", "Bearer"};


/**
 * Authentication manager
 * https://www.elastic.co/guide/en/elasticsearch/reference/current/http-clients.html
 */
class ElkAuthentication {
 public:
  /**
   * Default constructor, no authentication
   */
  ElkAuthentication();

  /**
   * Basic authentication
   * https://www.elastic.co/guide/en/elasticsearch/reference/current/http-clients.html#http-clients
   * @param username
   * @param password
   */
  ElkAuthentication(const char* username, const char* password);

  /**
   * Bearer Authentication
   * https://www.elastic.co/guide/en/elasticsearch/reference/current/token-authentication-services.html
   * @param bearer
   */
  explicit ElkAuthentication(const char* bearer);

  /**
   * Class Destructor
   */
  ~ElkAuthentication();

  /**
   * Copy constructor
   * @param other
   */
  ElkAuthentication(const ElkAuthentication& other);

  /**
   * Move constructor
   * @param other
   */
  ElkAuthentication(ElkAuthentication&& other) noexcept;

  /**
   * Add the configured authentication to the given request
   * @param session
   */
  void add_authentication(cpr::Session& session) const;

 private:
  const AuthType _auth_type;
  const std::unique_ptr<cpr::Authentication> _basic;
  const std::unique_ptr<cpr::Bearer> _bearer;
};
}


#endif //ELASTICSEARCH_CPP_CLIENT_SRC_ELK_CLIENT_COMMON_AUTHORIZATION_H_
