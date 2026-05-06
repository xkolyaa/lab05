cmake_minimum_required(VERSION 3.4)
project(lab03)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(formatter_lib)
add_subdirectory(formatter_ex_lib)
add_subdirectory(solver_lib)
add_subdirectory(hello_world_application)
add_subdirectory(solver_application)
install(TARGETS formatter formatter_ex solver_lib
ARCHIVE DESTINATION lib)

install(TARGETS hello_world solver
RUNTIME DESTINATION bin)


option(BUILD_TESTS "Создать тесты" OFF)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  file(GLOB SOLVER_TEST_SOURCES tests/*.cpp)
  add_executable(check ${SOLVER_TEST_SOURCES})
  target_link_libraries(check solver_lib gtest_main)
  add_test(NAME check COMMAND check)
endif()
