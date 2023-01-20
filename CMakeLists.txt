cmake_minimum_required(VERSION 3.5)

project(QianDengLake VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES QianDengLake_zh_CN.ts)

set(ABOUT_QIANDENG_LAKE AboutQianDengLake.h AboutQianDengLake.cpp AboutQianDengLake.ui)

set(ICONS Icons/Icons.qrc)

set(INFO Info.qrc)

set(THANKS thanks.h thanks.cpp thanks.ui)

set(CHANGLOG changlog.h changlog.cpp changlog.ui)

set(QIANDENGLAKEPROJECT
        QianDengLakeProject/QianDengLakeProject.h
        QianDengLakeProject/QianDengLakeProject.cpp
        QianDengLakeProject/QianDengConfig.h
        QianDengLakeProject/QianDengConfig.cpp)

set(NOTEPAD notepad/filemanager.h notepad/filemanager.cpp notepad/notepad.h notepad/notepad.cpp notepad/notepad.ui)

set(QIANDENGLAKECONFIGSET
    Preferences/qiandenglakeconfigset.h
    Preferences/qiandenglakeconfigset.cpp
    Preferences/qiandenglakeconfigset.ui
    Preferences/editor.h
    Preferences/editor.cpp
    Preferences/editor.ui
    Preferences/enviroment.h
    Preferences/enviroment.cpp
    Preferences/enviroment.ui)

set(QIANDENGLAKE_RESOURCES resources/resources.qrc)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${ABOUT_QIANDENG_LAKE}
        ${QIANDENG_LAKE_RESOURCE}
        ${TS_FILES}
        ${INFO}
        ${ICONS}
        ${THANKS}
        ${CHANGLOG}
        ${QIANDENGLAKEPROJECT}
        ${QIANDENGLAKECONFIGSET}
        ${NOTEPAD}
        ${QIANDENGLAKE_RESOURCES})

if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QianDengLake
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET QianDengLake APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else ()
    if (ANDROID)
        add_library(QianDengLake SHARED
                ${PROJECT_SOURCES}
                )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else ()
        add_executable(QianDengLake
                ${PROJECT_SOURCES}
                )
    endif ()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif ()

target_link_libraries(QianDengLake PRIVATE Qt${QT_VERSION_MAJOR}::Widgets PUBLIC libqscintilla2_qt6.so)

set_target_properties(QianDengLake PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        )

install(TARGETS QianDengLake
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QianDengLake)
endif ()
