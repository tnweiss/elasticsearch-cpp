//
// Created by tnwei on 1/8/2022.
//

#include "common/exceptions.h"
#include "common/error_handler.h"
#include "spdlog/spdlog.h"


void error_handler(cpr::Response& response) {
  // if successfully response code return
  if ((response.status_code / 100) == 2) {
    return;
  }

  // log the request url
  spdlog::debug("Request URL: {0}", response.url.data());

  // log the response code
  spdlog::error("Response Code: {0}", response.status_code);

  // log the response body
  spdlog::error("Response Body: {0}", response.text);

  // throw the exception
  throw elk::ELKException("Error Response, See logs");
}