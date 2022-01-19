//
// Created by tnwei on 1/14/2022.
//

#include "elk/elasticsearch/models/version.h"

std::string elk::Version::number() const {
  return get_string(NUMBER);;
}

std::string elk::Version::build_flavor() const {
  return get_string(BUILD_FLAVOR);
}

void elk::Version::number(std::string &number) const {
  set(NUMBER, number);
}

void elk::Version::build_flavor(std::string &build_flavor) const {
  set(BUILD_FLAVOR, build_flavor);
}

std::string elk::Version::build_type() const {
  return get_string(BUILD_TYPE);
}

void elk::Version::build_type(std::string &build_type) const {
  set(BUILD_TYPE, build_type);
}

std::string elk::Version::build_hash() const {
  return get_string(BUILD_HASH);
}

void elk::Version::build_hash(std::string &build_hash) const {
  set(BUILD_HASH, build_hash);
}

std::string elk::Version::build_date() const {
  return get_string(BUILD_DATE);
}

bool elk::Version::build_snapshot() const {
  return get_bool(BUILD_SNAPSHOT);
}

void elk::Version::build_date(std::string &build_date) const {
  set(BUILD_DATE, build_date);
}

std::string elk::Version::lucene_version() const {
  return get_string(LUCENE_VERSION);
}

void elk::Version::build_snapshot(bool build_snapshot) const {
  set(BUILD_SNAPSHOT, build_snapshot);
}

void elk::Version::lucene_version(std::string &lucene_version) const {
  set(LUCENE_VERSION, lucene_version);
}

std::string elk::Version::minimum_wire_compatibility_version() const {
  return get_string(MINIMUM_WIRE_COMPATIBILITY_VERSION);
}

void elk::Version::minimum_wire_compatibility_version(std::string &minimum_wire_compatibility_version) const {
  set(MINIMUM_WIRE_COMPATIBILITY_VERSION, minimum_wire_compatibility_version);
}

std::string elk::Version::minimum_index_compatibility_version() const {
  return get_string(MINIMUM_INDEX_COMPATIBILITY_VERSION);
}

void elk::Version::minimum_index_compatibility_version(std::string &minimum_index_compatibility_version) const {
  set(MINIMUM_INDEX_COMPATIBILITY_VERSION, minimum_index_compatibility_version);
}
