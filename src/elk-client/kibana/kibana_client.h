//
// Created by tnwei on 1/16/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_KIBANA_CLIENT_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_KIBANA_CLIENT_H_

#include "string"
#include "common/authentication.h"

namespace elk {

static const char* DEFAULT_KIBANA_ORIGIN = "http://localhost:5601";

class KibanaClient {
 public:
  /**
   * Default constructor, configure for default origin and no auth
   */
  KibanaClient();

  /**
   * Constructor that overrides the origin
   * @param origin origin of the elastic server
   */
  explicit KibanaClient(const char* origin);

  /**
   * Constructor that overrides the authenticaiton
   * @param authentication
   */
  explicit KibanaClient(const elk::ElkAuthentication& authentication);

  /**
   * Initialize the client with an origin and auth
   * @param origin
   * @param authentication
   */
  KibanaClient(const char* origin, const elk::ElkAuthentication&  authentication);

 private:
  const std::string _origin;
  const elk::ElkAuthentication& _authentication;
};

}


#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_KIBANA_CLIENT_H_
