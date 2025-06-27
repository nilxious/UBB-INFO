cmake_minimum_required(VERSION 3.29)
project(Lab2_OOP)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab2_OOP
        main.c
        controller/service.h
        repository/repository.c
        repository/repository.h
        teste/teste.c
        teste/teste.h
        ui/ui.c
        ui/ui.h
        domain/medicament.c
        domain/medicament.h
        controller/service.c
        validator/validator.c
        validator/validator.h)

