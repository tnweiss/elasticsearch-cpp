############## Subdirectories ##############
add_subdirectory(common)
add_subdirectory(elasticsearch)
add_subdirectory(kibana)

message("-- LIBRARY_NAME=${LIBRARY_NAME}")
############## Benchmarkr Library ##############
add_library(${LIBRARY_NAME} STATIC
        ${COMMON_SOURCES}
        ${ELASTICSEARCH_SOURCES}
        ${KIBANA_SOURCES})
add_library(elkClient::elkClient ALIAS ${LIBRARY_NAME})

target_precompile_headers(${LIBRARY_NAME} PRIVATE elk_client_pch.h)
target_link_libraries(${LIBRARY_NAME} ${LIBRARY_LINK_LIBRARIES})
