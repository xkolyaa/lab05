# CMake generated Testfile for 
# Source directory: /home/nikolay/project/lab05
# Build directory: /home/nikolay/project/lab05/_build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(check "/home/nikolay/project/lab05/_build/check")
set_tests_properties(check PROPERTIES  _BACKTRACE_TRIPLES "/home/nikolay/project/lab05/CMakeLists.txt;27;add_test;/home/nikolay/project/lab05/CMakeLists.txt;0;")
subdirs("formatter_lib")
subdirs("formatter_ex_lib")
subdirs("solver_lib")
subdirs("hello_world_application")
subdirs("solver_application")
subdirs("third-party/gtest")
