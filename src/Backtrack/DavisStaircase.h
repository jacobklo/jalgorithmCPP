//
// Created by Jacob Lo on 10/18/18.
//

/*
 * MEDIUM
 * https://www.hackerrank.com/challenges/ctci-recursive-staircase/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=recursion-backtracking
 *
 * calc number of all possible way to climb a stair with n step, with each step of 1 or 2 or 3
 */
#pragma once

#include <vector>

using namespace std;

namespace DavisStaircase {
  int stepPermsRecursive(int n) {

    /// base case: n = 1, 2, 3
    if ( n == 1) return 1;
    if ( n == 2) return 2;
    if ( n == 3) return 4;

    /// step is based on last 3 step, plus them all
    return ( stepPermsRecursive(n-1) + stepPermsRecursive(n-2) +  stepPermsRecursive(n-3) ) % (int)(1e+9 + 7);

  }

  int stepPerms(int n ) {
    vector<int> results( (unsigned long)( n > 3 ? n : 3 ) );

    /// base case: n = 1, 2, 3
    results[0] = 1;
    results[1] = 2;
    results[2] = 4;

    /// calc each number till n
    for ( int i = 3 ; i < n ; i++ ) {
      results[i] = ( results[i-1] + results[i-2] + results[i-3] );
    }

    return results[n-1];
  }
}

// 1

// 2
// 1 1

// 3
// 1 1 1
// 1 2
// 2 1

// 1 1 1 1
// 1 1 2
// 1 2 1
// 2 1 1
// 3 1
// 1 3
// 2 2