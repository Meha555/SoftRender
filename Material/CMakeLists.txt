file(GLOB srcs
    *.cpp
    *.h
)

add_library(Material STATIC ${srcs})
target_include_directories(Material PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Material PRIVATE Base)