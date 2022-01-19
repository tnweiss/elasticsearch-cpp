//
// Created by tnwei on 1/8/2022.
//

#include "elasticsearch/models/cluster_details.h"

std::string elk::ClusterDetails::name() const {
  return Model::get_string(NAME);
}

std::string elk::ClusterDetails::cluster_name() const {
  return Model::get_string(CLUSTER_NAME);
}

std::string elk::ClusterDetails::cluster_uuid() const {
  return Model::get_string(CLUSTER_UUID);
}

elk::Version elk::ClusterDetails::version() const {
  return Model::get_object<elk::Version>(VERSION);
}

std::string elk::ClusterDetails::tagline() const {
  return Model::get_string(TAGLINE);
}

void elk::ClusterDetails::name(std::string &name) const {
  set(NAME, name);
}

void elk::ClusterDetails::cluster_name(std::string &cluster_name) const {
  set(CLUSTER_NAME, cluster_name);
}

void elk::ClusterDetails::cluster_uuid(std::string &cluster_uuid) const {
  set(CLUSTER_UUID, cluster_uuid);
}

void elk::ClusterDetails::version(elk::Version version) const {
  set(VERSION, version);
}

void elk::ClusterDetails::tagline(std::string &tagline) const {
  set(TAGLINE, tagline);
}
