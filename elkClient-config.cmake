# - C++ Requests, Curl for People
# This module is a libcurl wrapper written in modern C++.
# It provides an easy, intuitive, and efficient interface to
# a host of networking methods.
#
# Finding this module will define the following variables:
#  CPR_FOUND - True if the core library has been found
#  CPR_LIBRARIES - Path to the core library archive
#  CPR_INCLUDE_DIRS - Path to the include directories. Gives access
#                     to cpr.h, which must be included in every
#                     file that uses this interface

find_path(ELK_CLIENT_INCLUDE_DIR
          NAMES keys.h)

find_library(ELK_CLIENT_LIBRARY
             NAMES elkClient)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(ELK_CLIENT REQUIRED_VARS ELK_CLIENT_LIBRARY ELK_CLIENT_INCLUDE_DIR)

if(ELK_CLIENT_FOUND)
    set(ELK_CLIENT_LIBRARIES ${ELK_CLIENT_LIBRARY})
    set(ELK_CLIENT_INCLUDE_DIRS ${ELK_CLIENT_INCLUDE_DIR})
endif()
