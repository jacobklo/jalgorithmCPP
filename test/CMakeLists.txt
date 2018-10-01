cmake_minimum_required(VERSION 3.12)
#--------------------------------------------
# NO NEED MODIFY
# Add all subdirectories to this project,
# which is getting from this directories name
#--------------------------------------------

# About this project
#-------------------
LIST(APPEND CMAKE_PROGRAM_PATH  "/usr/bin/")
# set(CMAKE_C_COMPILER /usr/bin/gcc)
# set(CMAKE_CXX_COMPILER /usr/bin/g++)

project(jalgorithmCPP_Test)

set(CMAKE_CXX_STANDARD 14)

#--------------------------------------------
# -- END -- NO NEED MODIFY
#--------------------------------------------

# Set env
#--------
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/../src)

add_executable(jalgorithmCPP_Test
        # Need to add a main() to run, it is in MostEleganceStringTest.cpp
        Backtrack/MostEleganceStringTest.cpp
        ../src/Backtrack/MostEleganceString.h
        Math/BusStopTest.cpp
        ../src/Math/BusStop.h
        DataStructure/LinkedList/GetNodesBeforeTest.cpp
        ../src/DataStructure/LinkedList/GetNodesBefore.h
        DataStructure/LinkedList/ReverseLastnNodesTest.cpp
        ../src/DataStructure/LinkedList/ReverseLastnNodes.h
        String/ReverseStringTest.cpp
        ../src/String/ReverseString.h)

