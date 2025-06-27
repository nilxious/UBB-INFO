cmake_minimum_required(VERSION 3.29.0)
project(LAB3 C)

set(CMAKE_C_STANDARD 11)

add_executable(LAB3 main.c
        Domain/Car.c
        Domain/Car.h
        Repository/Repository.c
        Repository/Repository.h
        Service/Service.c
        Service/Service.h
        UI/UI.c
        UI/UI.h
        Vector/Vector.c
        Vector/Vector.h
        Domain/CarValidator.c
        Domain/CarValidator.h
        Domain/Tests1.c
        Domain/Tests1.h
        Repository/Tests2.c
        Repository/Tests2.h
        Service/Tests3.c
        Service/Tests3.h
        Vector/Tests4.c
        Vector/Tests4.h
)
