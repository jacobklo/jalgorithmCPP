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
        String/ReverseString.h
        Math/SquareRoot.h
        DataStructure/Deque.h
        Sort/QuickSort.h
        STLDuddle/ContainersToString.h
        Search/BinarySearch.h
        DesignPattern/Singleton.h
        Array/MinSwap.h
        DynamicProgramming/Abbreviation.h
        Dictionary/CountTripletsGeometricProgression.h
        DynamicProgramming/MinCostPath.h
        Sort/FraudulentActivityNotifications.h
        DynamicProgramming/MaxSubsetSum.h
        Backtrack/DavisStaircase.h
        DataStructure/QueueUsingTwoStack.h
        Search/TripleSum.h
        Backtrack/AddTwoNumbers.h
        Array/LarrysArray.h
        Math/OrganizingContainersOfBalls.h
        STLDuddle/Pointers.h
        String/SherlockValidString.h
        STLDuddle/Sort.h
        STLDuddle/PrintContainer.h
        STLDuddle/SplitString.h
        STLDuddle/ConcatenateStrings.h
        List/MergeTwoList.h
        Heap/KClosest.h
        Dictionary/SubdomainVisitCount.h
        String/UniqueEmails.h
        Tree/FlattenBinaryTreeList.h
        Tree/PopulatingNextRightPointersInEachNode.h
        )

