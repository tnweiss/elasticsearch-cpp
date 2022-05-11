//
// Created by tnwei on 1/16/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_ACTIONS_SAVED_OBJECT_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_ACTIONS_SAVED_OBJECT_H_

#include <memory>

#include "elk/common/authentication.h"

#include "elk/kibana/models/saved_object_type.h"
#include "elk/kibana/models/create_saved_object_response.h"
#include "elk/kibana/models/create_saved_object_body.h"

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

/**
 *
 * @param origin
 * @param authentication
 * @param id
 */
void delete_saved_object_action(const std::string& origin, const elk::ElkAuthentication& authentication,
                                elk::SavedObjectType type, const char* id);

/**
 *
 * @param origin
 * @param authentication
 * @param id
 */
bool saved_object_exists_action(const std::string& origin, const elk::ElkAuthentication& authentication,
                                elk::SavedObjectType type, const char* id);

/**
 *
 * @param origin
 * @param authentication
 * @param object_export_content
 */
void import_object_action(const std::string& origin, const elk::ElkAuthentication& authentication,
                          std::string& object_export_content);

#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_ACTIONS_SAVED_OBJECT_H_
