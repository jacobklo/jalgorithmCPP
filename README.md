# Check out my Java edition, jalgorithm

# This project
includes some of the algorithms I came across online
I actively work on new Algorithms in GeeksforGeeks.org, Hackerrank.com, Topcoder.org, etc.

# This solution is configure into 2 CMake solutions:
src and test.
The file structure inside each solutions is the same.
With Unit tests has a file suffix XXXTest.cpp

# For src solution, all algorithms is written inside header file
This allow easy extraction of that algorithm
All algorithms also is namespaced of its own, so no interaction between others,
Unlike normal projects.

# List of Algorithm curently have:

src
 |- Backtrack
 |  |
 |  |- MostEleganceString - Hackerrank
 |
 |- DataStructure
 |  |
 |  |- LinkedList
 |  |  |
 |  |  |- GetNodesBefore
 |  |  |- ReverseLastnNodes
 |
 |- Math
 |  |
 |  |- BusStop - Hackerrank
 |
 |- main

