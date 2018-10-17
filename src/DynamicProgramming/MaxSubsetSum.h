//
// Created by Jacob Lo on 17/10/2018.
//

/*
 * MEDIUM
 * Max Array Sum
 * https://www.hackerrank.com/interview/interview-preparation-kit/dynamic-programming/challenges
 *
 * Given an array of integers, find the subset of non-adjacent elements with the maximum sum. Calculate the sum of that subset.
 *
 * For array {3,5,-7,8,10}, max non-adjacent subset is {5,10} == 15, while {3,-7,10} == 6 is not.
 * More in the end
 */
#pragma once

#include <vector>
#include <algorithm>

using namespace std;

namespace MaxSubsetSum {

  int maxSubsetSum(vector<int> arr) {

    vector<int> results( arr.size() );

    /// base case:
    results[0] = ( arr[0] > 0 ? arr[0] : 0 );
    results[1] = ( arr[1] > 0 ? arr[1] : 0 );

    int maxResultSoFarPos = 0;
    for ( int i = 2 ; i < arr.size() ; i++ ) {

      int subResult = 0;
      /// sub-loop through results from 0 to i-2, to find which result has the max for including myself arr[j]
      for ( int j = maxResultSoFarPos ; j <= (i-2); j++ ) {

        // calc the last sub max sum from i-2, and include current element
        int current = results[j] + arr[i];

        // update subResult
        if ( subResult < current) {
          subResult = current;
          maxResultSoFarPos = j;
        }
      }

      results[i] = subResult;
    }

    // find max result, as the last one may not be the max
    return *max_element( results.begin(), results.end());
  }
}

/*
 *Given an array of integers, find the subset of non-adjacent elements with the maximum sum. Calculate the sum of that subset.

For example, given an array  we have the following possible subsets:

Subset      Sum
[-2, 3, 5]   6
[-2, 3]      1
[-2, -4]    -6
[-2, 5]      3
[1, -4]     -3
[1, 5]       6
[3, 5]       8
Our maximum subset sum is .

Function Description

Complete the  function in the editor below. It should return an integer representing the maximum subset sum for the given array.

maxSubsetSum has the following parameter(s):

arr: an array of integers
Input Format

The first line contains an integer, .
The second line contains  space-separated integers .

Constraints

Output Format

Return the maximum sum described in the statement.

Sample Input 0

5
3 7 4 6 5
Sample Output 0

13
Explanation 0

Our possible subsets are  and . The largest subset sum is  from subset

Sample Input 1

5
2 1 5 8 4
Sample Output 1

11
Explanation 1

Our subsets are  and . The maximum subset sum is  from the first subset listed.

Sample Input 2

5
3 5 -7 8 10
Sample Output 2

15
Explanation 2

Our subsets are  and . The maximum subset sum is  from the fifth subset listed.
 */
