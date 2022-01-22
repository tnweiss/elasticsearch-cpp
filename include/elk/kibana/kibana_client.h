//
// Created by tnwei on 1/16/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_KIBANA_CLIENT_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_KIBANA_CLIENT_H_

#include "string"
#include "elk/common/authentication.h"
#include "elk/kibana/models/create_saved_object_body.h"
#include "elk/kibana/models/create_saved_object_response.h"
#include "elk/kibana/models/saved_object_type.h"

namespace elk {

static const char* DEFAULT_KIBANA_ORIGIN = "http://localhost:5601";

class KibanaClient {
 public:
  /**
   * Default constructor, configure for default origin and no auth
   */
  KibanaClient();

  /**
   * Constructor that overrides the origin
   * @param origin origin of the elastic server
   */
  explicit KibanaClient(const char* origin);

  /**
   * Constructor that overrides the authenticaiton
   * @param authentication
   */
  explicit KibanaClient(const elk::ElkAuthentication& authentication);

  /**
   * Initialize the client with an origin and auth
   * @param origin
   * @param authentication
   */
  KibanaClient(const char* origin, const elk::ElkAuthentication&  authentication);

  /**
   * Create Saved Object
   * @param body
   * @return
   */
  std::unique_ptr<CreateSavedObjectResponse> create_saved_object(SavedObjectType type, const char* id,
                                                                  const CreateSavedObjectBody& body) const;

  /**
   * Delete a Saved Object
   * @param body
   * @return
   */
  void delete_saved_object(SavedObjectType type, const char* id) const;

  /**
   * Returns true if a saved object exists
   * @param body
   * @return
   */
  bool saved_object_exists(SavedObjectType type, const char* id) const;

 private:
  const std::string _origin;
  const elk::ElkAuthentication& _authentication;
};

}


#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_KIBANA_KIBANA_CLIENT_H_
