file(GLOB srcs
    *.cpp
    *.h
)

add_library(Base STATIC ${srcs})
target_include_directories(Base PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/3rdParty
)