//
// Created by tnwei on 1/8/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_COMMON_ERROR_HANDLER_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_COMMON_ERROR_HANDLER_H_

#include "cpr/cpr.h"

namespace elk {

/**
 * Handle any response errors if present
 * @param response check the response status code
 */
void check_for_error(cpr::Response& response);

/**
 * Handles a known error with the response
 * @param response the response object of the request
 */
[[noreturn]] void handle_error(cpr::Response& response);

}


#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_COMMON_ERROR_HANDLER_H_
