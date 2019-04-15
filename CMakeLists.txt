# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(unit_test_01 LANGUAGES CXX)

# require C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

IF (MSVC) 
	# Activate C++ exception handling 
	IF (NOT CMAKE_CXX_FLAGS MATCHES "/EHsc") 
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
	ENDIF ()
ELSE ()
	SET(GCC_STD_CPP_17_COMPILE_FLAGS "-std=c++17")
	SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_STD_CPP_17_COMPILE_FLAGS}")
ENDIF () 

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

IF (MSVC)
	# Silence std::tr1 warning on MSVC  if(MSVC)
	foreach(_tgt google_test_001 )
		target_compile_definitions(${_tgt}
			PRIVATE
				"_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING"
		)
	endforeach()
ENDIF ()

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

	# Silence std::tr1 warning on MSVC  if(MSVC)
	foreach(_tgt unit_test )
		target_compile_definitions(${_tgt}
			PRIVATE
				"_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING"
		)
	endforeach()


ELSE ()
target_link_libraries(unit_test 
   PRIVATE
    functions_lib
    google_test_001
    pthread
)
ENDIF ()

  