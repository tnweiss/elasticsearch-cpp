//
// Created by tnwei on 1/14/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_INDEX_TYPES_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_INDEX_TYPES_H_

#include "magic_enum.hpp"

enum class IndexTypes {
  binary = 1,
  boolean = 2,
  keyword = 3,
  constant_keyword = 4,
  wildcard = 5,
  LONG = 6,
  DOUBLE,
  integer = 8
};

#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_INDEX_TYPES_H_
