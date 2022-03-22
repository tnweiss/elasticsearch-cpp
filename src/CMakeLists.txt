############## Subdirectories ##############
add_subdirectory(common)
add_subdirectory(elasticsearch)
add_subdirectory(kibana)

############## Benchmarkr Library ##############
add_library(elkClient STATIC
        ${COMMON_SOURCES}
        ${ELASTICSEARCH_SOURCES}
        ${KIBANA_SOURCES})

target_precompile_headers(elkClient PRIVATE elk_client_pch.h)

target_link_libraries(elkClient ${LIBRARY_LINK_LIBRARIES})

set_target_properties(elkClient PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR})

add_library(elkClient::elkClient ALIAS elkClient)