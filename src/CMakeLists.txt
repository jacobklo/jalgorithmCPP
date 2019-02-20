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
        Algorithm/Backtrack/MostEleganceString.h
        Implementation/Math/BusStop.h
        Implementation/List/GetNodesBefore.h
        Implementation/List/ReverseLastnNodes.h
        Implementation/String/ReverseString.h
        Implementation/Math/SquareRoot.h
        CustomDataStructure/Deque.h
        Algorithm/Sort/QuickSort.h
        STLDuddle/ContainersToString.h
        Algorithm/Search/BinarySearch.h
        DesignPattern/Singleton.h
        Implementation/Array/MinSwap.h
        Algorithm/DynamicProgramming/Abbreviation.h
        Implementation/Dictionary/CountTripletsGeometricProgression.h
        Algorithm/DynamicProgramming/MinCostPath.h
        Algorithm/Sort/FraudulentActivityNotifications.h
        Algorithm/DynamicProgramming/MaxSubsetSum.h
        Algorithm/DynamicProgramming/DavisStaircase.h
        CustomDataStructure/QueueUsingTwoStack.h
        Algorithm/Backtrack/AddTwoNumbers.h
        Implementation/Array/LarrysArray.h
        STLDuddle/Pointers.h
        Implementation/String/SherlockValidString.h
        STLDuddle/Sort.h
        STLDuddle/PrintContainer.h
        STLDuddle/SplitString.h
        STLDuddle/ConcatenateStrings.h
        Implementation/List/MergeTwoList.h
        Implementation/Heap/KClosest.h
        Implementation/Dictionary/SubdomainVisitCount.h
        Implementation/String/UniqueEmails.h
        Implementation/Tree/FlattenBinaryTreeList.h
        Implementation/Tree/PopulatingNextRightPointersInEachNode.h
        Implementation/String/Permutations.h
        Algorithm/Backtrack/RestoreIPAddress.h
        CustomDataStructure/RingBuffer.h
        Algorithm/DynamicProgramming/Knapsack.h
        Implementation/Array/DiagonalTraverse.h
        Algorithm/Greedy/JumpGame.h
        Implementation/Trie/ImplementTrie.h
        Implementation/Array/SpiralMatrix.h
        DesignPattern/Creational/AbstractFactory.h
        DesignPattern/Structural/Adapter.h
        DesignPattern/Behavioral/Iterator.h DesignPattern/Creational/Builder.h)

