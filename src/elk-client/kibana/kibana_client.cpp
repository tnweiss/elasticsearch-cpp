//
// Created by tnwei on 1/16/2022.
//

#include "kibana_client.h"
#include "kibana/actions/saved_object.h"

elk::KibanaClient::KibanaClient(): KibanaClient(elk::DEFAULT_KIBANA_ORIGIN) { }

elk::KibanaClient::KibanaClient(const char *origin):
    KibanaClient(origin, elk::ElkAuthentication()) { }

elk::KibanaClient::KibanaClient(const elk::ElkAuthentication& authentication):
    KibanaClient(elk::DEFAULT_KIBANA_ORIGIN, authentication){ }

elk::KibanaClient::KibanaClient(const char *origin, const elk::ElkAuthentication& authentication):
    _origin(origin), _authentication(authentication) { }

std::unique_ptr<elk::CreateSavedObjectResponse> elk::KibanaClient::create_saved_object(elk::SavedObjectType type,
                                                                                        const char *id,
                                                                                        const elk::CreateSavedObjectBody &body) const {
  return create_saved_object_action(_origin, _authentication, type, id, body);
}

void elk::KibanaClient::delete_saved_object(elk::SavedObjectType type, const char *id) const {
  return delete_saved_object_action(_origin, _authentication, type, id);
}

bool elk::KibanaClient::saved_object_exists(elk::SavedObjectType type, const char *id) const {
  return saved_object_exists_action(_origin, _authentication, type, id);
}
