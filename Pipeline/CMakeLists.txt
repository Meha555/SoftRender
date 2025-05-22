file(GLOB srcs
    *.cpp
    *.h
)

add_library(Pipeline STATIC ${srcs})
target_include_directories(Pipeline PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Pipeline PRIVATE
    Base Shader Material
    Qt${QT_VERSION_MAJOR}::Core
)