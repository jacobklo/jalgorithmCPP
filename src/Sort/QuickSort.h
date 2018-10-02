//
// Created by Jacob Lo on 02/10/2018.
//

#pragma once

#include <vector>
#include <random>

using namespace std;
namespace QuickSort {
  void swap( vector<int>& arr, int a, int b);

  void quickSort ( vector<int>& arr, int start, int end) {
    /// Base case : inclusive [ start, end ] So if end == start, it means there are only 1 element in this sub array
    if ( end - start < 1) return;

    /// choose random pivot
    default_random_engine gen;
    uniform_int_distribution<int> dis(start, end);
    int pivot = dis(gen);

    /// reassign all smaller then pivot elements to left side, bigger to right.
    // swap pivot to the start position temporarily
    swap( arr, start, pivot);

    // move all elements in following order : [ pivot, smaller elements, bigger elements ], smallerPtEnd == pivot(start) at first, in case pivot is actually the smallest
    int smallerPtEnd = start;
    for ( int i = smallerPtEnd+1 ; i <= end ; i++ ) {
      // arr[start] is now a pivot
      if ( arr[i] < arr[start] ) {
        smallerPtEnd++;
        swap( arr, smallerPtEnd, i );
      }
    }

    // swap pivot back to its right position
    swap( arr, start, smallerPtEnd);

    /// recursively quickSort left and right
    quickSort( arr, start, smallerPtEnd-1);
    quickSort( arr, smallerPtEnd+1, end);
  }

  void swap( vector<int>& arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
  }
};
