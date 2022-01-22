# Elasticsearch C++ Client

This project contains classes that can be used to interface with the ELK stack. 
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

## Usage

