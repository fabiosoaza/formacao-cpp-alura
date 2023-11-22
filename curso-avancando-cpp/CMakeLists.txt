cmake_minimum_required(VERSION 3.26)
project(curso_avancando_cpp)

set(CMAKE_CXX_STANDARD 17)

# Defina o diretório de origem
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Adicione todos os arquivos-fonte do diretório src
file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)

# Crie o executável
add_executable(curso_avancando_cpp ${SOURCES})