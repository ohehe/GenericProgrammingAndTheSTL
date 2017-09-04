cmake_minimum_required(VERSION 3.8)
project(GenericProgrammingAndTheSTL)

set(CMAKE_CXX_STANDARD 11)

#compile Googletest，make dll
add_subdirectory(./googletest)
include_directories(./googletest/include)
link_directories(./googletest)
set(LIBRARIES gtest)
set(SOURCE_FILES main.cpp Example_ReadAndPrintLines/SimpleReader.cpp Example_ReadAndPrintLines/SimpleReader.h normalheader.h Example_ReadAndPrintLines/test/TestReadAndPrintLines.h TestClassesIncluder.h Example_ReadAndPrintLines/LineIterator.h Example_ReadAndPrintLines/StrTableIterator.h)
add_executable(GenericProgrammingAndTheSTL ${SOURCE_FILES})
target_link_libraries(GenericProgrammingAndTheSTL ${LIBRARIES})