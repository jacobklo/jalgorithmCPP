//
// Created by Jacob Lo on 10/9/18.
//

/*
 * MEDIUM
 * Find all triplets in a sorted array that forms Geometric Progression
 * https://www.geeksforgeeks.org/find-all-triplets-in-a-sorted-array-that-forms-geometric-progression/
 * https://www.hackerrank.com/challenges/count-triplets-1/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps
 *
 * Calculate all triplets in an array that is in geometric progression form and i<j<k
 * More in the end
 */
#pragma once

#include <vector>
#include <map>

using namespace std;

namespace CountTripletsGeometricProgression {

  long countTriplets(const vector<long>& arr, long r) {

    /// create a map, with key is r progression, value is vector of positions occurance
    long currentProgression = 1;
    map<long, long> cmap;

    for ( int i = 0 ; i < arr.size() ; i++ ) {

      // making sure map has all progression keys
      while ( arr[i] >= currentProgression ) {
        cmap[currentProgression] = 0;
        currentProgression *= r;
      }

      if ( cmap.find(arr[i]) != cmap.end() ) {
        cmap[arr[i]]++;
      }
    }
    /// loop through map, count each triplets
    int result = 0;
    for ( map<long, long>::iterator it = cmap.begin() ; it != cmap.end() ; ++it ) {

      map<long, long>::iterator current = it;
      long currentResult = current->second;
      for ( int j = 0 ; j < 2; j++ ) {
        ++current;
        if ( current == cmap.end() ) {
          return result;
        }
        currentResult *= current->second;
      }
      result += currentResult;
    }
    return result;
  }
}

/*
 * You are given an array and you need to find number of tripets of indices  such that the elements at those indices are in geometric progression for a given common ratio  and .
For example, . If , we have  and  at indices  and .
Function Description
Complete the countTriplets function in the editor below. It should return the number of triplets forming a geometric progression for a given  as an integer.
countTriplets has the following parameter(s):
arr: an array of integers
r: an integer, the common ratio
Input Format
The first line contains two space-separated integers  and , the size of  and the common ratio.
The next line contains  space-seperated integers .
Constraints



Output Format
Return the count of triplets that form a geometric progression.
Sample Input 0
4 2
1 2 2 4
Sample Output 0
2
Explanation 0
There are  triplets in satisfying our criteria, whose indices are  and
Sample Input 1
6 3
1 3 9 9 27 81
Sample Output 1
6
Explanation 1
The triplets satisfying are index , , , ,  and .
Sample Input 2
5 5
1 5 5 25 125
Sample Output 2
4
Explanation 2
The triplets satisfying are index , , , .
 */