//
// Created by tnwei on 1/9/2022.
//

#include "elk/elasticsearch/actions/index.h"
#include "elk/common/error_handler.h"


bool index_exists_action(const std::string& origin, const elk::ElkAuthentication& authentication, const char* target) {
  // initialize the session
  cpr::Session session;

  // create the url and add it to the session
  std::string url = origin + "/" + target;
  cpr::priv::set_option(session, cpr::Url(url));
  spdlog::debug("Index Exists URL: {0}", url);

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
  elk::handle_error(response);
}


void create_index_action(const std::string& origin, const elk::ElkAuthentication& authentication, const char* target,
                         const elk::CreateIndexBody& request_body) {
  // initialize the session
  cpr::Session session;

  // create the url and add it to the session
  std::string url = origin + "/" + target;
  cpr::priv::set_option(session, cpr::Url(url));
  spdlog::debug("Create Index URL: {0}", url);

  // add authentication
  authentication.add_authentication(session);

  // set the request body
  std::string body = request_body.to_string();
  cpr::priv::set_option(session, cpr::Body(body));
  spdlog::debug("Create Index Body: {0}", body);

  // set the request body type to json
  cpr::priv::set_option(session, cpr::Header{{"Content-Type", "application/json"}});

  // make the request
  cpr::Response response = session.Put();

  // check for an error
  elk::check_for_error(response);
}

void delete_index_action(const std::string& origin, const elk::ElkAuthentication& authentication, const char* target) {
  // initialize the session
  cpr::Session session;

  // create the url and add it to the session
  std::string url = origin + "/" + target;
  cpr::priv::set_option(session, cpr::Url(url));
  spdlog::debug("Delete Index URL: {0}", url);

  // add authentication
  authentication.add_authentication(session);

  // make the request
  cpr::Response response = session.Delete();

  // check for an error
  elk::check_for_error(response);
}

void bulk_update_index_action(const std::string& origin, const elk::ElkAuthentication& authentication,
                              const char* target, const elk::BulkInsertBody& request_body) {
  // initialize the session
  cpr::Session session;

  // create the url and add it to the session
  std::string url = origin + "/" + target + "/_bulk";
  cpr::priv::set_option(session, cpr::Url(url));
  spdlog::debug("Bulk Update Index URL: {0}", url);

  // add authentication
  authentication.add_authentication(session);

  // set the request body
  std::string body = request_body.to_x_ndjson();
  cpr::priv::set_option(session, cpr::Body(body));
  spdlog::debug("Bulk Update Index Body: \n{0}", body);

  // set the request body type to json
  cpr::priv::set_option(session, cpr::Header{{"Content-Type", "application/x-ndjson"}});

  // make the request
  cpr::Response response = session.Post();

  // check for errors
  elk::check_for_error(response);

  // log the response body
  spdlog::debug("Bulk Update Response Body: \n{0}", response.text);
}