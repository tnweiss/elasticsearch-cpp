//
// Created by tnwei on 1/9/2022.
//

#include "elasticsearch/actions/index.h"
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
  throw elk::ELKException("Unhandled exception");
}


void create_index_action(const std::string& origin, const elk::ElkAuthentication& authentication, const char* target,
                         const elk::CreateIndexBody& request_body) {
  // initialize the session
  cpr::Session session;

  // create the url and add it to the session
  cpr::priv::set_option(session, cpr::Url(origin + "/" + target));

  // add authentication
  authentication.add_authentication(session);

  // set the request body
  cpr::priv::set_option(session, cpr::Body(request_body.to_string()));

  // set the request body type to json
  cpr::priv::set_option(session, cpr::Header{{"Content-Type", "application/json"}});

  // make the request
  cpr::Response response = session.Put();

  if (response.status_code != 200) {
    // handle exception
    error_handler(response);

    // should not get to this point
    throw elk::ELKException("Unhandled exception");
  }
}

void delete_index_action(const std::string& origin, const elk::ElkAuthentication& authentication, const char* target) {
  // initialize the session
  cpr::Session session;

  // create the url and add it to the session
  cpr::priv::set_option(session, cpr::Url(origin + "/" + target));

  // add authentication
  authentication.add_authentication(session);

  // make the request
  cpr::Response response = session.Delete();

  if (response.status_code != 200) {
    // handle exception
    error_handler(response);

    // should not get to this point
    throw elk::ELKException("Unhandled exception");
  }
}
