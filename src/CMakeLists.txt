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

target_include_directories(${LIBRARY_NAME} PUBLIC elk-client)
target_link_libraries(${LIBRARY_NAME} PUBLIC spdlog::spdlog cpr::cpr)
