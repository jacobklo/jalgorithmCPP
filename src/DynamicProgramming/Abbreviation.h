//
// Created by Jacob Lo on 10/8/18.
//

/*
 * MEDIUM
 * Abbreviation
 * https://www.hackerrank.com/challenges/abbr/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dynamic-programming
 *
 * Given 2 string a and b, see if they can become equal by doing any numbers of operations, but only 2 types of operations
 * 1. Capitalize zero or more of a's lowercase letters.
 * 2. Delete all of the remaining lowercase letters in .
 * More at the end
 */

#pragma once

#include <string>
#include <vector>

using namespace std;
namespace Abbreviation {

  // TODO
  int minOperationsToChangeString(const string& a, const string& b) {

    /// Handle impossible case?

    /// create vector of int store minimum operations needed to convert substring a to substring b at i position
    vector<vector<int>> ops( a.size()+1, vector<int>( b.size()+1, INT_MAX ) );
    ops[0] = vector<int>( b.size()+1, 0);

    /// loop and calc min operations needed in a[i] and b[j] position
    for ( int i = 1 ; i < a.size()+1 ; i++ ) {
      for ( int j = 1 ; j < b.size()+1 ; j++ ) {

        /// Case 1: a[i] == b[i], this position's operations is the last one
        ops[i][j] = ops[i-1][j-1];

        /// Case 2: a[i] != b[i], need to change to capital
        ops[i][j] = ops[i-1][j-1] + 1;

        /// Case 3: need to delete a[i]

      }
    }

  }
}

/*
 * You can perform the following operations on the string, :
Capitalize zero or more of 's lowercase letters.
Delete all of the remaining lowercase letters in .
Given two strings,  and , determine if it's possible to make  equal to  as described. If so, print YES on a new line. Otherwise, print NO.
For example, given  and , in  we can convert  and delete  to match . If  and , matching is not possible because letters may only be capitalized or discarded, not changed.
Function Description
Complete the function  in the editor below. It must return either  or .
abbreviation has the following parameter(s):
a: the string to modify
b: the string to match
Input Format
The first line contains a single integer , the number of queries.
Each of the next  pairs of lines is as follows:
- The first line of each query contains a single string, .
- The second line of each query contains a single string, .
Constraints


String  consists only of uppercase and lowercase English letters, ascii[A-Za-z].
String  consists only of uppercase English letters, ascii[A-Z].
Output Format
For each query, print YES on a new line if it's possible to make string  equal to string . Otherwise, print NO.
Sample Input
1
daBcd
ABC
Sample Output
YES
Explanation
image
We have  daBcd and  ABC. We perform the following operation:
Capitalize the letters a and c in  so that  dABCd.
Delete all the remaining lowercase letters in  so that  ABC.
Because we were able to successfully convert  to , we print YES on a new line.
 */