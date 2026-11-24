cmake_minimum_required(VERSION 3.20)
project(hse_se_prog_seminars LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Each exercise has its own main(), so build each file separately.
# CONFIGURE_DEPENDS picks up new exercises when the project is rebuilt.
file(GLOB_RECURSE EXERCISES CONFIGURE_DEPENDS
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "submissions/*.c"
    "submissions/*.cpp"
)

foreach(SOURCE IN LISTS EXERCISES)
    string(REGEX REPLACE "^submissions/" "" TARGET_NAME "${SOURCE}")
    string(REGEX REPLACE "\\.(c|cpp)$" "" TARGET_NAME "${TARGET_NAME}")
    string(REPLACE "/" "_" TARGET_NAME "${TARGET_NAME}")
    add_executable("${TARGET_NAME}" "${SOURCE}"
            submissions/seminar-05/3.c
            submissions/seminar-05/6.c
    )
    if(CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
        target_compile_options("${TARGET_NAME}" PRIVATE -Wall -Wextra)
    endif()
endforeach()
