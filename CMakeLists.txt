
cmake_minimum_required(VERSION 3.16)

project(gerenciador_financeiro LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(gerenciador_financeiro
    src/main.cpp
    src/financeiro.cpp
)

target_include_directories(gerenciador_financeiro
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)
