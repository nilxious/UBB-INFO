cmake_minimum_required(VERSION 3.30)
project(Lab7_OOP)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab7_OOP main.cpp
        produs.cpp
        produs.h
        repo.cpp
        repo.h
        service.cpp
        service.h
        validator.cpp
        validator.h
        ui.cpp
        ui.h
        teste/teste_repo.cpp
        teste/teste_repo.h
        teste/teste_service.cpp
        teste/teste_service.h
        teste/teste_produs.cpp
        teste/teste_produs.h
        teste/teste_validator.cpp
        teste/teste_validator.h
        VectorDinamic.cpp
        VectorDinamic.h)
