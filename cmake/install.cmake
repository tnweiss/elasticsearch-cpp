########## Install directives if not a submodule ##########
if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
    # Explicitly define install targets
    install(CODE "set(CMAKE_INSTALL_LOCAL_ONLY true)")

    # Include CMake helpers for package config files
    # Follow this installation guideline: https://cmake.org/cmake/help/latest/manual/cmake-packages.7.html
    include(CMakePackageConfigHelpers)

    write_basic_package_version_file(
            "${PROJECT_BINARY_DIR}/cmake/elkClientConfigVersion.cmake"
            VERSION ${CMAKE_PROJECT_VERSION}
            COMPATIBILITY ExactVersion)

    configure_package_config_file(
                ${PROJECT_SOURCE_DIR}/cmake/elkClientConfig.cmake.in
                "${PROJECT_BINARY_DIR}/cmake/elkClientConfig.cmake"
            INSTALL_DESTINATION
                ${CMAKE_INSTALL_LIBDIR}/cmake/elkClient-${PROJECT_VERSION}
    )

    install(FILES
                ${PROJECT_BINARY_DIR}/cmake/elkClientConfig.cmake
                ${PROJECT_BINARY_DIR}/cmake/elkClientConfigVersion.cmake
            DESTINATION
                ${CMAKE_INSTALL_LIBDIR}/cmake/elkClient-${PROJECT_VERSION}
    )

    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/elk
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
            PATTERN *.h)
endif()

########## Install all Libraries ##########
install(TARGETS elkClient spdlog cpr
        EXPORT elkClientTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)