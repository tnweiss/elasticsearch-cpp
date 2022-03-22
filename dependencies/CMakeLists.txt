target_include_directories(elkClient
        PUBLIC
            include
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include
)
