#cmake_minimum_required(VERSION 3.5)
#
#project(metodik_invaders2 VERSION 0.1 LANGUAGES CXX)
# list(APPEND CMAKE_PREFIX_PATH "C:/Qt/6.4.2/mingw_64")
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#
#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
#find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
#find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Multimedia)
#find_package(Qt6 COMPONENTS Core REQUIRED)
##find_package(Qt6 REQUIRED COMPONENTS Multimedia)
#set(PROJECT_SOURCES
#        main.cpp
#        invaders.cpp
#        invaders.h
#        invaders.ui
#        resource.qrc
#        player.h
#        player.cpp
#        settings.h
#        bullet.h
#        bullet.cpp
#        enemy.h
#        enemy.cpp
#        game.h
#        game.cpp
#        background.h
#        background.cpp
#        backgroundmusic.h
#        backgroundmusic.cpp
#)
#
#if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#    qt_add_executable(metodik_invaders2
#        MANUAL_FINALIZATION
#        ${PROJECT_SOURCES}
#    )
## Define target properties for Android with Qt 6 as:
##    set_property(TARGET metodik_invaders2 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
##                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
## For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
#else()
#    if(ANDROID)
#        add_library(metodik_invaders2 SHARED
#            ${PROJECT_SOURCES}
#        )
## Define properties for Android with Qt 5 after find_package() calls as:
##    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    else()
#        add_executable(metodik_invaders2
#            ${PROJECT_SOURCES}
#        )
#    endif()
#endif()
#
#target_link_libraries(metodik_invaders2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
#target_link_libraries(metodik_invaders2 PRIVATE Qt${QT_VERSION_MAJOR}::Multimedia)
#target_link_libraries(metodik_invaders2 PRIVATE Qt${QT_VERSION_MAJOR}::Core)
#
#set_target_properties(metodik_invaders2 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
#    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#    MACOSX_BUNDLE TRUE
#    WIN32_EXECUTABLE TRUE
#)
#
#install(TARGETS metodik_invaders2
#    BUNDLE DESTINATION .
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
#
#if(QT_VERSION_MAJOR EQUAL 6)
#    qt_finalize_executable(metodik_invaders2)
#endif()
cmake_minimum_required(VERSION 3.24)
project(metodik_invaders2)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.4.2\\mingw_64\\")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        REQUIRED)

add_executable(metodik_invaders2
        settings.h
        settings.cpp
        main.cpp
        invaders.cpp
        invaders.h
        invaders.ui
        resource.qrc
        player.h
        player.cpp
        bullet.h
        bullet.cpp
        enemy.h
        enemy.cpp
        game.h
        game.cpp
        background.h
        background.cpp
        backgroundmusic.h
        backgroundmusic.cpp
        )
target_link_libraries(metodik_invaders2
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Multimedia
        )


if (WIN64)

    # multimedia folder
    add_subdirectory("${CMAKE_PREFIX_PATH}/plugins/multimedia build/plugins")
    file(COPY CMAKE_PREFIX_PATH/plugins/multimedia DESTINATION build/plugins)


    set(DEBUG_SUFFIX)
    #    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
    #        set(DEBUG_SUFFIX "d")
    #    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()