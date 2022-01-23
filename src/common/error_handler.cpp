//
// Created by tnwei on 1/8/2022.
//


#include "elk/common/exceptions.h"
#include "elk/common/error_handler.h"


void elk::check_for_error(cpr::Response& response) {
  // if successfully response code return
  if ((response.status_code / 100) != 2) {
    handle_error(response);
  }
}


void elk::handle_error(cpr::Response& response) {
  // log the request url
  spdlog::debug("Request URL: {0}", response.url.data());

  // log the response code
  spdlog::error("Response Code: {0}", response.status_code);

  // log the response body
  spdlog::error("Response Body: {0}", response.text);

  // throw the exception
  throw elk::ELKException("Error Response, See logs");
}
