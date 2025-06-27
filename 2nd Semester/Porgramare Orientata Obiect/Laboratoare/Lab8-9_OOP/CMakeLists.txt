cmake_minimum_required(VERSION 3.30)
project(Lab8_9_OOP)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab8_9_OOP main.cpp
        validator.h
        service.h
        validator.cpp
        ui.h
        repo.h
        service.cpp
        ui.cpp
        repo.cpp
        produs.h
        produs.cpp
        teste/teste_produs.cpp
        teste/teste_produs.h
        teste/teste_repo.cpp
        teste/teste_repo.h
        teste/teste_service.cpp
        teste/teste_validator.cpp
        teste/teste_validator.h
        teste/teste_service.h
        CosCumparaturi.cpp
        CosCumparaturi.h
        ActiuneUndo.h
        UndoAdauga.h
        UndoModifica.h
        UndoSterge.h
        FileRepository.cpp
        FileRepository.h
        teste/teste_cos.cpp
        teste/teste_cos.h
        teste/teste_filerepo.cpp
        teste/teste_filerepo.h
        obiecftDTO.h
)
