file(GLOB srcs
    *.cpp
    *.h
)

add_library(Shader STATIC ${srcs})
target_include_directories(Shader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Shader PRIVATE Base)