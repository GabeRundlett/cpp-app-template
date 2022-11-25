cmake_minimum_required(VERSION 3.21)
execute_process(COMMAND vcpkg x-update-baseline)
include(cmake/warnings.cmake)
include(cmake/static_analysis.cmake)

project(my_app VERSION 0.1.0)
add_executable(${PROJECT_NAME} "src/main.cpp")
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
set_project_warnings(${PROJECT_NAME})

find_package(SDL2 CONFIG REQUIRED)
find_package(my-lib CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
    SDL2::SDL2
    my-lib::my-lib
)
