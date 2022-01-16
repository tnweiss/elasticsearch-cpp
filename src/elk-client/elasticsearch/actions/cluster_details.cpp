//
// Created by tnwei on 1/8/2022.
//

#include "cluster_details.h"

#include "cpr/cpr.h"
#include "common/error_handler.h"


elk::ClusterDetails elk::get_cluster_details_actions(const std::string& origin, const elk::ElkAuthentication& auth) {
  // initialize the session
  cpr::Session session;

  // create the url and add it to the session
  cpr::priv::set_option(session, cpr::Url(origin));

  // add authentication
  auth.add_authentication(session);

  // make the request
  cpr::Response response = session.Get();

  // check for exceptions
  error_handler(response);

  // deserialize the response
  return elk::ClusterDetails(response.text);
}