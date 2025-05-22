set(srcs
    main.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SoftRender MANUAL_FINALIZATION ${srcs})
else()
    add_executable(SoftRender ${srcs})
endif()

target_link_libraries(SoftRender PRIVATE
    UI
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SoftRender)
endif()