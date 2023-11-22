#!/bin/bash

CMAKE_TOOLCHAIN_DIR=cmake-build-debug/build/Debug/generators

# Script to install Conan dependencies
install_dependencies() {
    conan install . -of cmake-build-debug -s build_type=Debug -b missing
}

# Script to configure the project with CMake
configure_project() {
    cmake -S . -B cmake-build-debug \
        -DCMAKE_BUILD_TYPE=Debug \
        -DCMAKE_TOOLCHAIN_FILE=$CMAKE_TOOLCHAIN_DIR/conan_toolchain.cmake \
        -G Ninja
}

# Script to build the project
build_project() {
    cmake --build cmake-build-debug
}

# Script to run the project
run_project() {
    ./cmake-build-debug/tests
}

# Display help
display_help() {
    echo "Usage: $0 [command]"
    echo "Available commands:"
    echo "  install    - Install Conan dependencies"
    echo "  configure  - Configure the project with CMake"
    echo "  build      - Build the project"
    echo "  run        - Run the project"
    echo "  all        - Execute all tasks (install, configure, build, run)"
}

# Check the number of arguments
if [ "$#" -eq 0 ]; then
    display_help
    exit 1
fi

# Execute the appropriate task
case "$1" in
    "install") install_dependencies ;;
    "configure") configure_project ;;
    "build") build_project ;;
    "run") run_project ;;
    "all"|"")  # Default to "all" if no task is provided
        install_dependencies
        configure_project
        build_project
        run_project
        ;;
    *)
        echo "Invalid command: $1"
         display_help
        exit 1
        ;;
esac
