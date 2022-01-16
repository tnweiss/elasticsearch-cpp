//
// Created by tnwei on 1/9/2022.
//

#include "index.h"
#include "common/error_handler.h"


bool index_exists_action(const std::string& origin, const elk::ElkAuthentication& authentication, const char* target) {
  // initialize the session
  cpr::Session session;

  // create the url and add it to the session
  cpr::priv::set_option(session, cpr::Url(origin + "/" + target));

  // add authentication
  authentication.add_authentication(session);

  // make the request
  cpr::Response response = session.Head();

  if (response.status_code == 200) {
    return true;
  } else if (response.status_code == 404) {
    return false;
  }

  // handle exception
  error_handler(response);

  // should not get to this point
  throw std::exception("Unhandled exception");
}