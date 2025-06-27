cmake_minimum_required(VERSION 3.30)
project(Lab10_OOP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.9.0\\mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Lab10_OOP
        main.cpp
        FileRepository.cpp
        CosCumparaturi.h
        UndoModifica.h
        ui.h
        FileRepository.h
        service.cpp
        validator.h
        CosCumparaturi.cpp
        repo.h
        ui.cpp
        produs.h
        repo.cpp
        UndoAdauga.h
        service.h
        UndoSterge.h
        validator.cpp
        produs.cpp
        ActiuneUndo.h
        teste/teste_cos.cpp
        teste/teste_cos.h
        teste/teste_filerepo.cpp
        teste/teste_filerepo.h
        teste/teste_produs.cpp
        teste/teste_produs.h
        teste/teste_repo.cpp
        teste/teste_repo.h
        teste/teste_service.cpp
        teste/teste_service.h
        teste/teste_validator.cpp
        teste/teste_validator.h
        gui.cpp
        gui.h
        observer.h
        CosCRUDGUI.h
        CosReadOnlyGUI.h
        ProdusTableModel.h
)
target_link_libraries(Lab10_OOP
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
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
