####### Project ##########
cmake_minimum_required (VERSION 3.5)
project(elkClient VERSION 0.0.10)

####### Import Install Filepaths ##########
include(GNUInstallDirs)

####### CMAKE VARIABLES ##########
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_STANDARD 17)

####### Handle Collecting Dependencies ##########
include(cmake/dependencies.cmake)

####### Create Version Header ##########
configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/version.h.in
        ${CMAKE_CURRENT_SOURCE_DIR}/include/elk/version.h
        @ONLY
)

########## Include the src subdirectory ##########
add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(dependencies)

# If the project is not a submodule, add the test directory
if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
    add_subdirectory(test)
endif()

########## Script to Install ##########
include(cmake/install.cmake)
