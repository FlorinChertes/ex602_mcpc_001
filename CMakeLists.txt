# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(unit_test_01 LANGUAGES CXX)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# functions library
add_library(functions_lib
    sum_integers.hpp
    sum_integers.cpp	
)

# test library
add_library(google_test_001 
    ../../googletest-release-1.8.0/googletest/include/gtest/gtest.h
    ../../googletest-release-1.8.0/googletest/src/gtest_main.cc
    ../../googletest-release-1.8.0/googletest/src/gtest-all.cc
)
target_include_directories(google_test_001 SYSTEM
  PUBLIC ../../googletest-release-1.8.0/googletest/include)
target_include_directories(google_test_001 SYSTEM
  PUBLIC ../../googletest-release-1.8.0/googletest)

  
# main code
add_executable(test_prg
    main_test.cpp
)
target_link_libraries(test_prg functions_lib)


# testing binary
add_executable(unit_test 
    unit_test.cpp
)
target_include_directories(unit_test SYSTEM
  PUBLIC ../../googletest-release-1.8.0/googletest/include)
target_include_directories(unit_test SYSTEM
  PUBLIC ../../googletest-release-1.8.0/googletest)
IF (MSVC)
target_link_libraries(unit_test 
   PRIVATE
    functions_lib
    google_test_001
)
ELSE ()
target_link_libraries(unit_test 
   PRIVATE
    functions_lib
    google_test_001
    pthread
)
ENDIF ()

  