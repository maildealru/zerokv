cmake_minimum_required(VERSION 3.16)

project(zerokv C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(conan/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(include)

add_compile_definitions(__FILE_PREFIX__="${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(zerokv
               src/main.c
               src/zkv_sys.c
               src/zkv_conn.c
               src/zkv_config.c
               src/zkv_log.c)

target_link_libraries(zerokv ${CONAN_LIBS})
