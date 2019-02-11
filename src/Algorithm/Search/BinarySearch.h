//
// Created by Jacob Lo on 10/2/18.
//

// Problem : Given the function: "bool numExists( int array[], int array_len, int num )"
// where "array" is a sorted array of integers.  Determine if "num" exists in the array.
// This is basically a binary search question. Do a recursive version and an iterative version.
// Writing binary search is easy but getting it the most efficient is hard.
// Can you do it with the minimum number of operations possible?

#pragma once

namespace BinarySearch {
  bool numExists( int array[], int array_len, int num ) {
    /// Null Check
    if ( array == nullptr ) return false;

    /// Keep track of start and end position, have while loop to generate middle position and do binary search
    int start = 0;        // 2
    int end = array_len;  // 4

    while ( end != start ) {
      // calc current middle position
      int middle = ( end + start ) /2;

      // REMEMBER : Base case : need to check infinite loop for middle.
      // sometimes the result of middle will become start/end itself again
      if ( start == middle || end == middle ) {
        return array[start] == num;
      }
      // 3 cases, smaller
      else if ( num < array[middle] ) {
        end = middle;
      }
      // bigger
      else if ( num > array[middle] ) {
        start = middle;
      }
      // equal
      else {
        return true;
      }
    }

    /// Last element from while loop need to check too
    return array[start] == num || array[end] == num;
  }
}