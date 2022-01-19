//
// Created by tyler on 1/18/22.
//

#include "elk/common/exceptions.h"

elk::ELKException::ELKException(const std::string& msg): _msg(msg) {

}

elk::ELKException::ELKException(const char *msg): _msg(msg) {

}

const char *elk::ELKException::what() const noexcept {
  return _msg.c_str();
}
