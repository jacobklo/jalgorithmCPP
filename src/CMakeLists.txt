cmake_minimum_required(VERSION 3.12)
#--------------------------------------------
# NO NEED MODIFY
# Add all subdirectories to this project,
# which is getting from this directories name
#--------------------------------------------

# About this project
#-------------------
# LIST(APPEND CMAKE_PROGRAM_PATH  "/usr/bin/")
# set(CMAKE_C_COMPILER /usr/bin/gcc)
# set(CMAKE_CXX_COMPILER /usr/bin/g++)

project(jalgorithmCPP)

set(CMAKE_CXX_STANDARD 14)


#--------------------------------------------
# -- END -- NO NEED MODIFY
#--------------------------------------------

add_executable(jalgorithmCPP
        main.cpp
        Backtrack/MostEleganceString.h
        Math/BusStop.h
        DataStructure/LinkedList/GetNodesBefore.h
        DataStructure/LinkedList/ReverseLastnNodes.h
        )

