//
// Created by tnwei on 1/16/2022.
//


#include "elk/kibana/actions/saved_object.h"
#include "elk/common/error_handler.h"

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
  std::string url = origin + "/api/saved_objects/" + type_str + "/" + id;
  cpr::priv::set_option(session, cpr::Url(url));
  spdlog::debug("Create Saved Object URL: {0}", url);

  // add authentication
  authentication.add_authentication(session);

  // set the request body
  cpr::priv::set_option(session, cpr::Body(body.to_string()));
  spdlog::debug("Create Saved Object Body: {0}", body.to_string());

  // set the request body type to json
  cpr::Header headers({
    {"Content-Type", "application/json"},
    {"kbn-xsrf", "true"}
  });
  cpr::priv::set_option(session, headers);

  // make the request
  cpr::Response response = session.Post();

  // check for an error
  elk::check_for_error(response);

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
  std::string url = origin + "/api/saved_objects/" + type_str + "/" + id;
  cpr::priv::set_option(session, cpr::Url(url));
  spdlog::debug("Delete Saved Object URL: {0}", url);

  // add authentication
  authentication.add_authentication(session);

  // set the request body type to json
  cpr::Header headers({
    {"kbn-xsrf", "true"}
  });
  cpr::priv::set_option(session, headers);

  // make the request
  cpr::Response response = session.Delete();

  // check for errors
  elk::check_for_error(response);
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
  std::string url = origin + "/api/saved_objects/" + type_str + "/" + id;
  cpr::priv::set_option(session, cpr::Url(url));
  spdlog::debug("Saved Object Exists URL: {0}", url);

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
  elk::handle_error(response);
}

void import_object_action(const std::string& origin, const elk::ElkAuthentication& authentication,
                          std::string& object_export_content) {
  // initialize the session
  cpr::Session session;

  // create the url and add it to the session
  std::string url = origin + "/api/saved_objects/_import";
  cpr::priv::set_option(session, cpr::Url(url));
  spdlog::debug("Object Import URL: {0}", url);

  // add authentication
  authentication.add_authentication(session);

  // set the request body type to json
  cpr::Header headers({
                          {"kbn-xsrf", "true"}
                      });
  cpr::priv::set_option(session, headers);

  cpr::Multipart multipart{{"file", cpr::Buffer(object_export_content.begin(), object_export_content.end(), "file.ndjson")}};
  cpr::priv::set_option(session, multipart);

  // make the request
  cpr::Response response = session.Post();

  if (response.status_code == 200) return;

  // handle exception
  elk::handle_error(response);
}