cmake_minimum_required(VERSION 3.0.0)
project(hello VERSION 0.1.0)

include(CTest)
enable_testing()
find_package(httplib)

add_executable(http_json main.cpp)

target_link_libraries(http_json httplib::httplib)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
