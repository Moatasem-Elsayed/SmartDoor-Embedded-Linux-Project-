cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# message("${ARCH}")
option(ARCH "X86")
if( ${ARCH} STREQUAL "ARM")
set(CMAKE_C_COMPILER "arm-linux-gnueabihf-gcc")
set(CMAKE_CXX_COMPILER "arm-linux-gnueabihf-g++")
set(CMAKE_ASM_COMPILER "arm-linux-gnueabihf-as")
set(CMAKE_OBJCOPY "arm-linux-gnueabihf-objcopy")
message("-------- Hello")
endif()

PROJECT(SmartDoor)
set(SRC_URI
    main.cpp
    src/FacadeResourceManager.cpp
    src/Servo.cpp
    src/TempertureStreatgy.cpp
    src/TempSensor.cpp
)
add_executable(${PROJECT_NAME} ${SRC_URI})

target_include_directories(${PROJECT_NAME} PUBLIC src/)

add_custom_target(send
    DEPENDS ${PROJECT_NAME}
    COMMAND scp ${PROJECT_NAME} pi@192.168.100.30:/home/pi
)
add_custom_target(run
    DEPENDS ${PROJECT_NAME}
    COMMAND ssh pi@192.168.100.30 '/home/pi/${PROJECT_NAME}'
)
