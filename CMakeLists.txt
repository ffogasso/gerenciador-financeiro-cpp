cmake_minimum_required(VERSION 3.16)

project(GerenciadorFinanceiro VERSION 0.1.0 LANGUAGES CXX)

add_executable(gerenciador_financeiro src/main.cpp)

target_include_directories(gerenciador_financeiro PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

set_target_properties(gerenciador_financeiro PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
