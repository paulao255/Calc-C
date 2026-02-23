# Project configuration:
cmake_minimum_required(VERSION 4.2.2)
project(Calc-C LANGUAGES C VERSION 20260223)
include(FetchContent)

# Defines:
set(CMAKE_C_STANDARD 99) # 90 for C89, 99 for C99, 11 for C11, 17 for C17 and 23 for C23.
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Declare dependencies:
FetchContent_Declare(C-Utils GIT_REPOSITORY https://github.com/paulao255/C-Utils.git GIT_TAG main)

# Build dependencies:
FetchContent_MakeAvailable(C-Utils)

# Build the executable:
add_executable(Ccalc ../src/Main.c)
target_compile_options(Ccalc PUBLIC -fdiagnostics-color=always -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Wformat=2 -Wnull-dereference -Wstrict-prototypes -Wmissing-prototypes -Wcast-align -Wpointer-arith -Wundef -v -O3 -funroll-loops -flto -mtune=native -march=native -fPIE -pie -fstack-protector-all)

# Link dependencies:
target_link_libraries(Ccalc PRIVATE C-Utils)

# Set output directory:
set_target_properties(Ccalc PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
