set(ELASTICSEARCH_SOURCES

        elasticsearch/actions/cluster_details.cpp
        elasticsearch/actions/index.cpp
        elasticsearch/models/index/index_mapping_properties.cpp
        elasticsearch/models/index/index_mappings.cpp
        elasticsearch/models/index/property_value.cpp
        elasticsearch/models/cluster_details.cpp
        elasticsearch/models/create_index_body.cpp
        elasticsearch/models/version.cpp
        elasticsearch/elasticsearch_client.cpp
        elasticsearch/models/index/bulk_insert_action.cpp
        elasticsearch/models/index/bulk_insert_body.cpp

        PARENT_SCOPE)