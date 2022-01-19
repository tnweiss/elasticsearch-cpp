project(elk-client)
cmake_minimum_required (VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_PROJECT_VERSION 0.0.1)

####### Configure Library Name ##########
if (MSVC)
    set(LIBRARY_NAME "elk-client-${CMAKE_PROJECT_VERSION}-${CMAKE_C_COMPILER_ARCHITECTURE_ID}-vc${MSVC_TOOLSET_VERSION}")
else()
    set(LIBRARY_NAME "elk-client-${CMAKE_PROJECT_VERSION}-${CMAKE_LIBRARY_ARCHITECTURE}")
endif()

####### Dependencies ##########
link_directories(dependencies/lib)
include_directories(dependencies/include include)
find_package(spdlog REQUIRED) # logging

####### CRP Http Dep ##########
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 67e12da316754ff3c6c91b50aafb2658438f3c1e) # the commit hash for 1.7.0
FetchContent_MakeAvailable(cpr)

########## Include the src subdirectory ##########
add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(test)

########## Libraries ##########
# Include CMake helpers for package config files
# Follow this installation guideline: https://cmake.org/cmake/help/latest/manual/cmake-packages.7.html
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
        "${PROJECT_BINARY_DIR}/elkClient/elkClientConfigVersion.cmake"
        VERSION ${CMAKE_PROJECT_VERSION}
        COMPATIBILITY ExactVersion)

configure_package_config_file(${PROJECT_SOURCE_DIR}/cmake/elkClientConfig.cmake.in
        "${PROJECT_BINARY_DIR}/elkClient/elkClientConfig.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/elkClient)

install(TARGETS ${LIBRARY_NAME}
        EXPORT elkClientTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        )

install(
        FILES
            ${PROJECT_BINARY_DIR}/elkClient/elkClientConfig.cmake
            ${PROJECT_BINARY_DIR}/elkClient/elkClientConfigVersion.cmake
        DESTINATION
            ${CMAKE_INSTALL_LIBDIR}/cmake/elkClient
)

#install(EXPORT elkClientTargets
#        FILE elkClientTargets.cmake
#        NAMESPACE elkClient::
#        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/elkClient)
