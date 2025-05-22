file(GLOB srcs
    *.cpp
    *.h
    *.ui
)

add_library(UI STATIC ${srcs})
target_include_directories(UI PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}
)
target_link_libraries(UI PRIVATE
    Base Pipeline
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
)