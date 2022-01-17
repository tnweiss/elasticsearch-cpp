############## Benchmarkr Library ##############
add_library(elk-cpp-client STATIC

        common/authentication.cpp
        common/error_handler.cpp
        common/model.cpp
        common/keys.h

        elasticsearch/elasticsearch_client.cpp

        elasticsearch/models/cluster_details.cpp
        elasticsearch/models/version.cpp
        elasticsearch/models/create_index_body.cpp
        elasticsearch/models/index_types.h
        elasticsearch/models/index/property_value.cpp
        elasticsearch/models/index/index_mapping_properties.cpp
        elasticsearch/models/index/index_mappings.cpp

        elasticsearch/actions/cluster_details.cpp
        elasticsearch/actions/index.cpp

        kibana/kibana_client.cpp

        kibana/models/create_saved_object_body.cpp
        kibana/models/saved_object_type.h
        kibana/models/saved_object_attributes.cpp
        kibana/models/create_saved_object_response.cpp

        kibana/actions/saved_object.cpp
        )

target_include_directories(elk-cpp-client PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(elk-cpp-client PUBLIC spdlog::spdlog cpr::cpr)
