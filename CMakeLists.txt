project(elk-cpp-client)
cmake_minimum_required (VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(ELASTICSEARCH_VERSION 0.0.1)

####### Dependencies ##########
link_directories(dependencies/lib)
include_directories(dependencies/include)
find_package(spdlog REQUIRED) # logging

####### CRP Http Dep ##########
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 67e12da316754ff3c6c91b50aafb2658438f3c1e) # the commit hash for 1.7.0
FetchContent_MakeAvailable(cpr)

########## Include the src subdirectory ##########
add_subdirectory(src)

########## Libraries ##########
install(TARGETS elk-cpp-client DESTINATION lib)
