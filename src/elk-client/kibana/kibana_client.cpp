//
// Created by tnwei on 1/16/2022.
//

#include "kibana_client.h"

elk::KibanaClient::KibanaClient(): KibanaClient(elk::DEFAULT_KIBANA_ORIGIN) { }

elk::KibanaClient::KibanaClient(const char *origin):
    KibanaClient(origin, elk::ElkAuthentication()) { }

elk::KibanaClient::KibanaClient(const elk::ElkAuthentication& authentication):
    KibanaClient(elk::DEFAULT_KIBANA_ORIGIN, authentication){ }

elk::KibanaClient::KibanaClient(const char *origin, const elk::ElkAuthentication& authentication):
    _origin(origin), _authentication(authentication) { }
