//
// Created by Jacob Lo on 10/7/18.
//

/*
 * MEDIUM
 * Minimum number of swaps required to sort an array
 * https://www.hackerrank.com/challenges/minimum-swaps-2/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
 * https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/

Given an array of n distinct elements, find the minimum number of swaps required to sort the array.

Examples:

Input : {4, 3, 2, 1}
Output : 2
Explanation : Swap index 0 with 3 and 1 with 2 to
              form the sorted array {1, 2, 3, 4}.

Input : {1, 5, 4, 3, 2}
Output : 2
 */
#pragma once

#include <vector>
#include <unordered_map>

using namespace std;

namespace MinSwap {

  // TODO
  int minimumSwaps( vector<int> arr) {
    vector<int> sorted (arr);
    /// sort the sorted array
    sort( sorted.begin(), sorted.end() );

    int result = 0;

    /// create a hash table, with desire position
    unordered_map<int, int> desireMap;
    for ( int i = 0 ; i < sorted.size() ; i++ ) {
      desireMap[ sorted[i] ] = i;
    }

    /// loop
    for ( int i = 0 ; i < arr.size() ; i++ ) {
      /// case 2: not equal, result ++
      if ( arr[i] != sorted[i] ) {
        result++;
      }
      /// case 3: check if current swapped element position can also be swap to this position
      int toBeSwapPos = desireMap[ arr[i] ];
      int toBeSwapEle = arr[ toBeSwapPos ];
      // if toBeSwap element actually fit current i position, that swap 1 time can fix 2 elements
      if ( desireMap[ toBeSwapEle ] == i ) {
        // replace toBeSwapEle to rightful pos, so it will pass case 2 in the future
        arr[ toBeSwapPos ] = sorted[ toBeSwapPos ];
      }
      /// case 1 ( no action needed): element already in right pos
    }

    return result;
  }
}