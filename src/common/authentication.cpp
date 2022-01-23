//
// Created by tnwei on 1/8/2022.
//


#include "elk/common/authentication.h"
#include "elk/common/exceptions.h"


elk::ElkAuthentication::ElkAuthentication(const char *username, const char *password):
  _auth_type(AuthType::BASIC),
  _basic(std::make_unique<cpr::Authentication>(username, password)),
  _bearer(nullptr) {

  spdlog::debug("Initializing Basic Authentication ({0}, **********)", username);
}

elk::ElkAuthentication::ElkAuthentication(const char *bearer):
  _auth_type(AuthType::BEARER),
  _bearer(std::make_unique<cpr::Bearer>(bearer)),
  _basic(nullptr) {

  spdlog::debug("Initializing Bearer Authenticaiton ({0})", bearer);
}

elk::ElkAuthentication::ElkAuthentication(): _auth_type(AuthType::NONE), _bearer(nullptr), _basic(nullptr) {
  spdlog::debug("Initializing with no authentication");
}

void elk::ElkAuthentication::add_authentication(cpr::Session& session) const {
  switch (_auth_type) {
    case AuthType::BASIC:
      spdlog::debug("Adding Basic Auth to session");
      cpr::priv::set_option(session, *_basic);
      break;
    case AuthType::BEARER:
      spdlog::debug("Adding Bearer Auth to session");
      cpr::priv::set_option(session, *_bearer);
      break;
    case AuthType::NONE:
      spdlog::debug("Skipping authentication");
      break;
    default:
      spdlog::error("Unknown Auth type");
      throw elk::ELKException("Unhandled auth type");
  }

}

elk::ElkAuthentication::~ElkAuthentication() = default;

elk::ElkAuthentication::ElkAuthentication(const elk::ElkAuthentication &other):
  _auth_type(other._auth_type),
  _bearer(std::make_unique<cpr::Bearer>(*other._bearer)),
  _basic(std::make_unique<cpr::Authentication>(*other._basic)) {

}

elk::ElkAuthentication::ElkAuthentication(elk::ElkAuthentication &&other) noexcept:
  _auth_type(other._auth_type),
  _bearer(std::make_unique<cpr::Bearer>(*other._bearer)),
  _basic(std::make_unique<cpr::Authentication>(*other._basic)) {

}
