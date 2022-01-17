//
// Created by tnwei on 1/16/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_ACTIONS_SAVED_OBJECT_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_ACTIONS_SAVED_OBJECT_H_

#include <memory>
#include "common/authentication.h"
#include "kibana/models/saved_object_type.h"
#include "kibana/models/create_saved_object_response.h"
#include "kibana/models/create_saved_object_body.h"

namespace elk {
/**
 *
 * @param origin
 * @param authentication
 * @param type
 * @param id
 * @param body
 * @return
 */
std::unique_ptr<elk::CreateSavedObjectResponse> create_saved_object_action(const std::string& origin,
                                                     const elk::ElkAuthentication& authentication,
                                                     SavedObjectType type,
                                                     const char* id,
                                                     const CreateSavedObjectBody& body);
}

#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_ACTIONS_SAVED_OBJECT_H_
