# ELK C++ Client

This project contains classes that can be used to interface with the [ELK stack](https://www.elastic.co/elastic-stack?ultron=B-Stack-Trials-AMER-US-W-Exact&gambit=Stack-ELK&blade=adwords-s&hulk=paid&Device=c&thor=elk%20stack&gclid=CjwKCAiA866PBhAYEiwANkIneBzl7n9qo5y2Ij1eXkCUF64LALcs7VZ0mBtR9JWHHadOjDu12huI9hoCr8wQAvD_BwE). 
Currently, the projects scope doesn't extend any further than what is required 
in the [benchmarkr-cpp](https://github.com/tnweiss/Benchmarkr-cpp) project.

## CMake

To include this library in your cmake project just add the following lines to your
`CMakeLists.txt`.

```cmake
include(FetchContent)
FetchContent_Declare(elkClient GIT_REPOSITORY https://github.com/tnweiss/elk-cpp GIT_TAG v0.0.1)
FetchContent_MakeAvailable(elkClient)
```

which will give you a target `elkClient::elkClint` that you can link against

```cmake
target_link_libraries(your_project PRIVATE elkClient::elkClient)
```

## Dependencies

The following dependencies are automatically installed / built with this project, so you don't 
have to worry about installing them yourself. 

- [CPR - C++ Requests: Curl for People](https://github.com/libcpr/cpr/blob/master/README.md)
- [SPDLOG - C++ Logging library](https://github.com/gabime/spdlog)
- [NLOHMANN JSON - JSON Parsing](https://github.com/nlohmann/json)
- [CATCH2 - Unit / Integration Testing](https://github.com/catchorg/Catch2)
- [Magic Enum - Enum Reflection](https://github.com/Neargye/magic_enum)

If you would like to override the default versions used in this project set the associated version 
variable before importing this project.

```cmake
set(SPDLOG_VERSION 1.9.2)
set(CPR_VERSION 1.7.2)
set(MAGIC_ENUM_VERSION 0.7.3)
set(CATCH_VERSION 2.13.8)
set(NLOHMANN_JSON_VERSION 3.10.5)
```

## Usage

Elasticsearch and Kibana clients have the same constructor interface, so for the examples below
we'll just use the Elasticsearch client

To instantiate a client using the default origin (http://localhost:9200) and no authentication

```c++
#include "elk/elasticsearch/elasticsearch_client.h"

int main() {
  const elk::ElasticsearchClient elastic_client();
  
  return 0;
}
```

To override the origin pass a c string in the constructor

```c++
#include "elk/elasticsearch/elasticsearch_client.h"

int main() {
  const elk::ElasticsearchClient elastic_client("http://192.168.1.70:9200");
  
  return 0;
}
```

As of now, the only authentication model supported by this client is basic. To use 
basic auth create an auth object and pass it to the constructor of the elasticsearch client

```c++
#include "elk/elasticsearch/elasticsearch_client.h"
#include "elk/common/authentication.h"

int main() {
  const elk::ElkAuthentication authentication("username", "password")
  const elk::ElasticsearchClient elastic_client("http://192.168.1.70:9200", authentication);
  
  return 0;
}
```

The best way to test your connection is to do a get on your elasticsearch's cluster details

```c++
#include <iostream>

#include "elk/elasticsearch/elasticsearch_client.h"
#include "elk/common/authentication.h"

int main() {
  const elk::ElkAuthentication authentication("username", "password")
  const elk::ElasticsearchClient elastic_client("http://192.168.1.70:9200", authentication);
  
  std::cout << elastic_client.get_cluster_details().name() << std::endl;
  
  return 0;
}
```
