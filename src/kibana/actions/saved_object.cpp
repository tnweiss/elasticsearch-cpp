//
// Created by tnwei on 1/16/2022.
//

#include <spdlog/spdlog.h>
#include <memory>

#include "kibana/actions/saved_object.h"
#include "common/error_handler.h"

/**
 * Replace underscores with hyphens
 * @param c
 * @return
 */
static int underscoreToHyphen(int c) {
  return c == '_' ? '-': c;
}

std::unique_ptr<elk::CreateSavedObjectResponse> elk::create_saved_object_action(const std::string& origin,
                                                               const elk::ElkAuthentication& authentication,
                                                               SavedObjectType type,
                                                               const char* id,
                                                               const CreateSavedObjectBody& body) {
  // initialize the session
  cpr::Session session;

  // normalize the type
  std::string type_str(magic_enum::enum_name(type));
  transform(type_str.begin(), type_str.end(), type_str.begin(), ::underscoreToHyphen); // convert '_' to '-'
  transform(type_str.begin(), type_str.end(), type_str.begin(), ::tolower); // convert it to lowercase

  // create the url and add it to the session
  cpr::priv::set_option(session, cpr::Url(origin + "/api/saved_objects/" + type_str + "/" + id));

  // add authentication
  authentication.add_authentication(session);

  // set the request body
  cpr::priv::set_option(session, cpr::Body(body.to_string()));

  // set the request body type to json
  cpr::Header headers({
    {"Content-Type", "application/json"},
    {"kbn-xsrf", "true"}
  });
  cpr::priv::set_option(session, headers);

  // make the request
  cpr::Response response = session.Post();

  if (response.status_code != 200) {
    // handle exception
    error_handler(response);

    // should not get to this point
    throw elk::ELKException("Unhandled exception");
  }

  return std::make_unique<CreateSavedObjectResponse>(response.text);
}

void delete_saved_object_action(const std::string& origin, const elk::ElkAuthentication& authentication,
                                elk::SavedObjectType type, const char* id) {
  // initialize the session
  cpr::Session session;

  // normalize the type
  std::string type_str(magic_enum::enum_name(type));
  transform(type_str.begin(), type_str.end(), type_str.begin(), ::underscoreToHyphen); // convert '_' to '-'
  transform(type_str.begin(), type_str.end(), type_str.begin(), ::tolower); // convert it to lowercase

  // create the url and add it to the session
  cpr::priv::set_option(session, cpr::Url(origin + "/api/saved_objects/" + type_str + "/" + id));

  // add authentication
  authentication.add_authentication(session);

  // set the request body type to json
  cpr::Header headers({
    {"kbn-xsrf", "true"}
  });
  cpr::priv::set_option(session, headers);

  // make the request
  cpr::Response response = session.Delete();

  if (response.status_code != 200) {
    // handle exception
    error_handler(response);

    // should not get to this point
    throw elk::ELKException("Unhandled exception");
  }
}

bool saved_object_exists_action(const std::string& origin, const elk::ElkAuthentication& authentication,
                                elk::SavedObjectType type, const char* id) {
  // initialize the session
  cpr::Session session;

  // normalize the type
  std::string type_str(magic_enum::enum_name(type));
  transform(type_str.begin(), type_str.end(), type_str.begin(), ::underscoreToHyphen); // convert '_' to '-'
  transform(type_str.begin(), type_str.end(), type_str.begin(), ::tolower); // convert it to lowercase

  // create the url and add it to the session
  cpr::priv::set_option(session, cpr::Url(origin + "/api/saved_objects/" + type_str + "/" + id));

  // add authentication
  authentication.add_authentication(session);

  // set the request body type to json
  cpr::Header headers({
                          {"kbn-xsrf", "true"}
                      });
  cpr::priv::set_option(session, headers);

  // make the request
  cpr::Response response = session.Get();

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