//
// Created by tnwei on 1/8/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_COMMON_ERROR_HANDLER_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_COMMON_ERROR_HANDLER_H_

#include "cpr/cpr.h"

/**
 * Handle any response errors
 * @param response check the response status code
 */
void error_handler(cpr::Response& response);

#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_COMMON_ERROR_HANDLER_H_
