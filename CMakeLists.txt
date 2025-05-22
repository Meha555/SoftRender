cmake_minimum_required(VERSION 3.15)

project(SoftRender VERSION 0.1.0 LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 启用 Qt 自动处理 MOC/UIC/RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

# 查找 Qt6
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

message(NOTICE "Qt Version: Qt${QT_VERSION}")

# 手动列出源文件（推荐方式，避免 GLOB_RECURSE 污染）
set(srcs
    Base/Camera.cpp
    Base/Clip.cpp
    Base/FrameBuffer.cpp
    Base/Image.cpp
    Base/Light.cpp
    Base/Mesh.cpp
    Base/Model.cpp
    Base/Transform.cpp
    Base/Vertex.cpp
    Base/Function.h
    Base/Global.h

    Material/BlinnMaterial.cpp
    Material/MaterialBase.cpp
    Material/PBRMaterial.cpp
    Material/SkyBoxMaterial.cpp
    Material/Texture.cpp
    Material/BlinnMaterial.h
    Material/MaterialBase.h
    Material/PBRMaterial.h
    Material/SkyBoxMaterial.h
    Material/Texture.h

    Pipeline/Graphics.cpp
    Pipeline/RenderLoop.cpp
    Pipeline/StateMachine.cpp
    Pipeline/Graphics.h
    Pipeline/RenderLoop.h
    Pipeline/StateMachine.h

    Shader/BlinnShader.cpp
    Shader/ShaderBase.cpp
    Shader/PBRShader.cpp
    Shader/ShadowShader.cpp
    Shader/SkyboxShader.cpp
    Shader/BlinnShader.h
    Shader/ShaderBase.h
    Shader/PBRShader.h
    Shader/ShadowShader.h
    Shader/SkyboxShader.h

    UI/EnvTab.cpp
    UI/ModelTab.cpp
    UI/RenderWidget.cpp
    UI/MaterialDialog.cpp
    UI/EnvTab.ui
    UI/ModelTab.ui
    UI/RenderWidget.ui
    UI/MaterialDialog.ui
    UI/EnvTab.h
    UI/ModelTab.h
    UI/RenderWidget.h
    UI/MaterialDialog.h

    main.cpp
)

# 添加可执行文件
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SoftRender MANUAL_FINALIZATION ${srcs})
else()
    add_executable(SoftRender ${srcs})
endif()

# 包含目录
target_include_directories(SoftRender PRIVATE
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/3rdParty
)

# 链接 Qt 库
target_link_libraries(SoftRender PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
)

# 如果是 Qt6，则需要手动 finalize executable
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SoftRender)
endif()