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
        Algorithm/Backtrack/MostEleganceStringTest.cpp
        ../src/Algorithm/Backtrack/MostEleganceString.h
        Implementation/Math/BusStopTest.cpp
        ../src/Implementation/Math/BusStop.h
        Implementation/List/GetNodesBeforeTest.cpp
        ../src/Implementation/List/GetNodesBefore.h
        Implementation/List/ReverseLastnNodesTest.cpp
        ../src/Implementation/List/ReverseLastnNodes.h
        Implementation/String/ReverseStringTest.cpp
        ../src/Implementation/String/ReverseString.h
        CustomDataStructure/DequeTest.cpp
        ../src/CustomDataStructure/Deque.h
        Algorithm/Sort/QuickSortTest.cpp
        ../src/Algorithm/Sort/QuickSort.h
        Algorithm/Search/BinarySearchTest.cpp
        ../src/Algorithm/Search/BinarySearch.h
        Implementation/Dictionary/CountTripletsGeometricProgressionTest.cpp
        ../src/Implementation/Dictionary/CountTripletsGeometricProgression.h
        Algorithm/DynamicProgramming/MinCostPathTest.cpp
        ../src/Algorithm/DynamicProgramming/MinCostPath.h
        Algorithm/Sort/FraudulentActivityNotificationsTest.cpp
        ../src/Algorithm/Sort/FraudulentActivityNotifications.h
        Algorithm/DynamicProgramming/MaxSubsetSumTest.cpp
        ../src/Algorithm/DynamicProgramming/MaxSubsetSum.h
        Algorithm/DynamicProgramming/DavisStaircaseTest.cpp
        ../src/Algorithm/DynamicProgramming/DavisStaircase.h
        Algorithm/Backtrack/AddTwoNumbersTest.cpp
        ../src/Algorithm/Backtrack/AddTwoNumbers.h
        Implementation/Array/LarrysArrayTest.cpp
        ../src/Implementation/Array/LarrysArray.h
        ../src/STLDuddle/ContainersToString.h
        CustomDataStructure/RingBufferTest.cpp
        ../src/CustomDataStructure/RingBuffer.h
        Algorithm/DynamicProgramming/KnapsackTest.cpp
        ../src/Algorithm/DynamicProgramming/Knapsack.h
        )

