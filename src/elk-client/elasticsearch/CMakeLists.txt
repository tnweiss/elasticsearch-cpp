set(ELASTICSEARCH_SOURCES
        elasticsearch/actions/cluster_details.h
        elasticsearch/actions/cluster_details.cpp

        elasticsearch/actions/index.h
        elasticsearch/actions/index.cpp

        elasticsearch/models/index/index_mapping_properties.h
        elasticsearch/models/index/index_mapping_properties.cpp

        elasticsearch/models/index/index_mappings.h
        elasticsearch/models/index/index_mappings.cpp

        elasticsearch/models/index/property_value.h
        elasticsearch/models/index/property_value.cpp

        elasticsearch/models/cluster_details.h
        elasticsearch/models/cluster_details.cpp

        elasticsearch/models/create_index_body.h
        elasticsearch/models/create_index_body.cpp

        elasticsearch/models/index_types.h

        elasticsearch/models/version.h
        elasticsearch/models/version.cpp

        elasticsearch/elasticsearch_client.h
        elasticsearch/elasticsearch_client.cpp

        PARENT_SCOPE)