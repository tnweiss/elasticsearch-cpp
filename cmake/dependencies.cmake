include(FetchContent)

####### Set default versions ##########
message(----------------- ELK Client Dependencies -----------------)
if(NOT DEFINED SPDLOG_VERSION)
    set(SPDLOG_VERSION 1.9.2)
endif()
message("-- Using SPDLOG Version:        ${SPDLOG_VERSION}")

if(NOT DEFINED CPR_VERSION)
    set(CPR_VERSION 1.7.2)
endif()
message("-- Using CPR Version:           ${CPR_VERSION}")

if(NOT DEFINED MAGIC_ENUM_VERSION)
    set(MAGIC_ENUM_VERSION 0.7.3)
endif()
message("-- Using Magic Enum Version:    ${MAGIC_ENUM_VERSION}")

if(NOT DEFINED CATCH_VERSION)
    set(CATCH_VERSION 2.13.8)
endif()
message("-- Using Catch Version:         ${CATCH_VERSION}")

if(NOT DEFINED NLOHMANN_JSON_VERSION)
    set(NLOHMANN_JSON_VERSION 3.10.5)
endif()
message("-- Using Nlohmann Json Version: ${NLOHMANN_JSON_VERSION}")
message(-----------------------------------------------------------)

####### UUID for linux ##########
if (UNIX)
    set(LIBRARY_LINK_LIBRARIES "PRIVATE;uuid;${LIBRARY_LINK_LIBRARIES}")
endif ()

####### Logging ##########
FetchContent_Declare(spdlog GIT_REPOSITORY https://github.com/gabime/spdlog GIT_TAG v${SPDLOG_VERSION})
FetchContent_MakeAvailable(spdlog)
set(LIBRARY_LINK_LIBRARIES "PUBLIC;spdlog::spdlog;-fPIC;${LIBRARY_LINK_LIBRARIES}")

####### CRP Http ##########
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG ${CPR_VERSION})
FetchContent_MakeAvailable(cpr)
set(LIBRARY_LINK_LIBRARIES "PUBLIC;cpr::cpr;${LIBRARY_LINK_LIBRARIES}" )

####### JSON ##########
if (NOT EXISTS ${CMAKE_CURRENT_LIST_DIR}/../dependencies/include/nlohmann/json.hpp)
    file(DOWNLOAD
            https://raw.githubusercontent.com/nlohmann/json/v${NLOHMANN_JSON_VERSION}/single_include/nlohmann/json.hpp
            ${CMAKE_CURRENT_LIST_DIR}/../dependencies/include/nlohmann/json.hpp)
endif()

####### Enum ##########.
if (NOT EXISTS ${CMAKE_CURRENT_LIST_DIR}/../dependencies/include/magic_enum.hpp)
    file(DOWNLOAD
            https://raw.githubusercontent.com/Neargye/magic_enum/v${MAGIC_ENUM_VERSION}/include/magic_enum.hpp
            ${CMAKE_CURRENT_LIST_DIR}/../dependencies/include/magic_enum.hpp)
endif()

####### Unit Testing ##########.
if (NOT EXISTS ${CMAKE_CURRENT_LIST_DIR}/../dependencies/include/catch.hpp)
    file(DOWNLOAD
            https://raw.githubusercontent.com/catchorg/Catch2/v${CATCH_VERSION}/single_include/catch2/catch.hpp
            ${CMAKE_CURRENT_LIST_DIR}/../dependencies/include/catch.hpp)
endif()
