cmake_minimum_required(VERSION 3.25)
project(cpp_tdd_testes_unidade_catch_2)

set(CMAKE_CXX_STANDARD 17)

#coverage
#https://stackoverflow.com/questions/65603144/how-to-get-coverage-for-tests-with-cmake-and-catch2

# Defina o diretório de origem
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_PROJECT_TOP_LEVEL_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/conan_provider.cmake")


#boilerplate to download cmake-conan

if(NOT EXISTS "${CMAKE_PROJECT_TOP_LEVEL_INCLUDES}")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/develop2/conan_provider.cmake"
            "${CMAKE_PROJECT_TOP_LEVEL_INCLUDES}"
            EXPECTED_HASH SHA256=ebcac264a8e25662b5292900c9131c7bd5f838175996b4b1545f99cbb749fa88
            TLS_VERIFY ON)
endif()



# Adicione todos os arquivos-fonte do diretório src
file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)

find_package(Catch2 REQUIRED)

add_executable(tests ${SOURCES} tests/teste_avaliador.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_compile_features(tests PRIVATE cxx_std_17)

