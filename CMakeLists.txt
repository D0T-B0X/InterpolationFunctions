cmake_minimum_required(VERSION 3.10)
project(InterpolationFunctions
    DESCRIPTION "Base Template for Interpolation Functions" 
    LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.c ${CMAKE_SOURCE_DIR}/src/csv_utils.c)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|CLANG")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
endif()