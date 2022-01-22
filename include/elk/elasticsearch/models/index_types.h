//
// Created by tnwei on 1/14/2022.
//

#ifndef ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_INDEX_TYPES_H_
#define ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_INDEX_TYPES_H_

#include "magic_enum.hpp"

// https://www.elastic.co/guide/en/elasticsearch/reference/current/mapping-types.html
enum class IndexType {
  BINARY,
  BOOLEAN,

  // https://www.elastic.co/guide/en/elasticsearch/reference/current/keyword.html
  KEYWORD,
  CONSTANT_KEYWORD,
  WILDCARD,

  // https://www.elastic.co/guide/en/elasticsearch/reference/current/number.html
  LONG,
  INTEGER,
  SHORT,
  BYTE,
  DOUBLE,
  FLOAT,
  HALF_FLOAT,
  SCALED_FLOAT,
  UNSIGNED_LONG,

  DATE,
  DATE_NANOS,
  ALIAS,
  OBJECT,
  FLATTENED,
  NESTED,
  JOIN,

  // https://www.elastic.co/guide/en/elasticsearch/reference/current/range.html
  INTEGER_RANGE,
  FLOAT_RANGE,
  LONG_RANGE,
  DOUBLE_RANGE,
  DATE_RANGE,
  IP_RANGE,

  IP,
  VERSION,
  MURMUR3,
  AGGREGATE_METRIC_DOUBLE,
  HISTOGRAM,

  // https://www.elastic.co/guide/en/elasticsearch/reference/current/text.html
  TEXT,
  MATCH_ONLY_TEXT,

  // ANNOTATED-TEXT
  COMPLETION,
  SEARCH_AS_YOU_TYPE,
  TOKEN_COUNT,
  DENSE_VECTOR,
  SPARSE_VECTOR,
  RANK_FEATURE,
  RANK_FEATURES,
  GEO_POINT,
  GEO_SHAPE,
  POINT,
  SHAPE,
  PERCOLATOR,
  ARRAY
};


#endif //ELK_CPP_CLIENT_SRC_ELK_CLIENT_ELASTICSEARCH_MODELS_INDEX_TYPES_H_
