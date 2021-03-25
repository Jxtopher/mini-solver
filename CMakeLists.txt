#
# @Author: Jxtopher
# @License: *
# @Date: 2020-11
# @Version: 2
# @Description: CMakeLists.txt
#
# cmake .. -G "MinGW Makefiles"

cmake_minimum_required(VERSION 3.12)

###############################################################################
# Set of compilator parameters
###############################################################################
set(CMAKE_BUILD_TYPE Release) # (Release|Debug)
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++2a -fopenmp\
                                    -pedantic -Wall -Wextra -Wcast-align -Wctor-dtor-privacy    \
                                    -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op \
                                    -Wmissing-include-dirs -Wnoexcept -Wno-unused  -Wshadow     \
                                    -Woverloaded-virtual -Wredundant-decls  -Wsign-promo        \
                                    -Wstrict-null-sentinel -Wstrict-overflow=5 -Wundef -Werror  \
                                    -Wswitch-default -Wsign-conversion -Wcast-qual -Wold-style-cast") # -Wmissing-declarations 
endif(CMAKE_COMPILER_IS_GNUCXX)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

###############################################################################
# Load modules cmake
###############################################################################
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(cppcheck)       # apply cppcheck
include(clang-format)   # apply clang-format
include(doxygen)        # Create the documentation

###############################################################################
# Projet
###############################################################################
project(mini-solver)
add_executable(${PROJECT_NAME} sources/main.cpp)

###############################################################################
# Unit tests
###############################################################################
find_package(PkgConfig)
pkg_check_modules(CPPUNIT cppunit)

if (CPPUNIT_FOUND)
    enable_testing()
    set(UNITTEST_TO_APPLY "tests/*.cpp")

    file(GLOB_RECURSE ALL_SOURCE_FILES  ${UNITTEST_TO_APPLY})
    foreach (SOURCE_FILE ${ALL_SOURCE_FILES})
        get_filename_component(NAME_FILE ${SOURCE_FILE} NAME_WE)
        add_executable(${NAME_FILE} ${SOURCE_FILE})
        target_link_libraries(${NAME_FILE} LINK_PRIVATE ${CPPUNIT_LIBRARIES})
        target_include_directories(${NAME_FILE} PRIVATE 
            "sources/"
        )
        add_test(NAME ${NAME_FILE} COMMAND ${NAME_FILE} WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
    endforeach()
endif(CPPUNIT_FOUND)

###############################################################################
# Globals tests
###############################################################################
FIND_PROGRAM(PYTHON_EXECUTABLE python)

file(GLOB LIST_OF_FILES  tests-globals/*.py)
foreach(PATH_FILE  ${LIST_OF_FILES})
    get_filename_component(FILE ${PATH_FILE} NAME)
    add_test(NAME ${FILE} COMMAND ${PYTHON_EXECUTABLE} ${PATH_FILE} "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}" WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
endforeach()
