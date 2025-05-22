file(GLOB srcs *.cpp *.ui)
add_library(UI SHARED ${srcs})
target_include_directories(UI PUBLIC
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/3rdParty
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(UI PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Pipeline
)

add_library(Render::UI ALIAS UI)