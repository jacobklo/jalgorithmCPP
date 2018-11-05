//
// Created by Jacob Lo on 11/4/18.
//

/*
 * MEDIUM
 * https://www.hackerrank.com/challenges/larrys-array/problem
 *
 * Larry has been given a permutation of a sequence of natural numbers incrementing from  as an array. He must determine whether the array can be sorted using the following operation any number of times:
Choose any  consecutive indices and rotate their elements in such a way that .
For example, if :
A		rotate
[1,6,5,2,4,3]	[6,5,2]
[1,5,2,6,4,3]	[5,2,6]
[1,2,6,5,4,3]	[5,4,3]
[1,2,6,3,5,4]	[6,3,5]
[1,2,3,5,6,4]	[5,6,4]
[1,2,3,4,5,6]

YES
 */
#pragma once

#include <vector>

using namespace std;

namespace LarrysArray {
  void rotateClockwise( vector<int>& arr, int startPos) {
    int tmp = arr[ startPos ];
    arr[ startPos ] = arr[ startPos + 1 ];
    arr[ startPos + 1 ] = arr[ startPos + 2 ];
    arr[ startPos + 2 ] = tmp;
  }

  bool larrysArray( vector<int> arr ) {

    /// for loop
    for ( int i = 0 ; i < arr.size() ; i++ ) {
      /// for loop to end to find next smallest element
      int currentSmallestPos = i;
      int currentSmallest = arr[i];
      for (int j = i+1; j < arr.size(); j++) {
        if (currentSmallest > arr[j]) {
          currentSmallestPos = j;
          currentSmallest = arr[j];
        }
      }

      /// do rotate and check element in right position, return false if cannot
      while (currentSmallestPos > i) {
        // default, currentSmallestPos is at last pos of the 3 elements
        int swapIndex = currentSmallestPos - 2;
        // if currentSmallestPos is in the middle of 3 elements
        if ( currentSmallestPos - 1 == i) {
          swapIndex = currentSmallestPos - 1;
        }
        // special case, overflow protection, if currentSmallestPos is last element of whole array
        if ( currentSmallestPos == arr.size() - 1) {
          swapIndex = currentSmallestPos - 2;
        }
        rotateClockwise( arr, swapIndex);
        currentSmallestPos--;
      }
    }
    /// check if last 3 is sorted
    return arr[ arr.size() - 3] < arr[ arr.size() - 2] &&
           arr[ arr.size() - 2] < arr[ arr.size() - 1];
  }
}
