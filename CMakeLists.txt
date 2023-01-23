cmake_minimum_required(VERSION 3.10)
PROJECT(SmartDoor)
set(SRC_URI
    main.cpp
    src/FacadeResourceManager.cpp
    src/Servo.cpp
    src/TempertureStreatgy.cpp
    src/TempSensor.cpp
)
add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC src/)