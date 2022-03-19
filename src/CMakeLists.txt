############## Subdirectories ##############
add_subdirectory(common)
add_subdirectory(elasticsearch)
add_subdirectory(kibana)

message("-- LIBRARY_NAME=elkClient")
############## Benchmarkr Library ##############
add_library(elkClient SHARED
        ${COMMON_SOURCES}
        ${ELASTICSEARCH_SOURCES}
        ${KIBANA_SOURCES})
add_library(elkClient::elkClient ALIAS elkClient)
set_target_properties(elkClient
        PROPERTIES
        VERSION 0.0.10
        SOVERSION 0)

target_precompile_headers(elkClient PRIVATE elk_client_pch.h)
target_link_libraries(elkClient ${LIBRARY_LINK_LIBRARIES})
set_target_properties(elkClient PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR})

