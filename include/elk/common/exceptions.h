//
// Created by tyler on 1/18/22.
//

#ifndef ELK_CPP_CLIENT_INCLUDE_COMMON_EXCEPTIONS_H_
#define ELK_CPP_CLIENT_INCLUDE_COMMON_EXCEPTIONS_H_

namespace elk {

class ELKException: public std::exception {
  public:
   explicit ELKException(std::string  msg);
   explicit ELKException(const char* msg);
   [[nodiscard]] const char* what() const noexcept override;
  private:
   const std::string _msg;
};

}
#endif //ELK_CPP_CLIENT_INCLUDE_COMMON_EXCEPTIONS_H_
