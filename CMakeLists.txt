cmake_minimum_required(VERSION 3.15)

project(SoftRender VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

message(NOTICE "Qt Version: Qt${QT_VERSION}")

add_subdirectory(Base)
add_subdirectory(Material)
add_subdirectory(Shader)
add_subdirectory(Pipeline)
add_subdirectory(UI)
add_subdirectory(App)