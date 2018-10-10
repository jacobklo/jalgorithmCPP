//
// Created by Jacob Lo on 10/10/18.
//

/*
 * MEDIUM
 * Min Cost Path
 * https://www.geeksforgeeks.org/min-cost-path-dp-6/
 *
 * For a matrix, find the minimum path from 1 node to the end. from start(0,0), we can only go left or lower
 */
#pragma once

#include <vector>

using namespace std;

namespace MinCostPath {

  int minCostPath( const vector< vector<int> >& map) {

    /// construct a 2D array, storing the min cost from start (0,0) to (i,j). load the first column and row
    vector< vector< int> > cmap( map.size(), vector<int>( map[0].size(), 0 ));
    cmap[0][0] = map[0][0];
    for ( int i = 1 ; i < map.size() ; i++ ) {
      cmap[i][0] = map[i][0] + cmap[i-1][0];
    }
    for ( int i = 1 ; i < map[0].size() ; i++ ) {
      cmap[0][i] = map[0][i] + cmap[0][i-1];
    }

    /// for loop, (i,j) position, we will calculate from top or left to (i,j) is minimum
    for ( int i = 1 ; i < cmap.size() ; i++ ) {
      for (int j = 1; j < cmap[i].size(); j++) {

        /// Case 1: from top
        int top = cmap[i-1][j];

        /// Case 2: from left
        int left = cmap[i][j-1];

        /// update (i,j) min cost
        cmap[i][j] = ( top > left ? left : top ) + map[i][j];
      }
    }

    return cmap[cmap.size()-1][cmap[0].size()-1];
  }
}

/*
 * Min Cost Path | DP-6
Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. Total cost of a path to reach (m, n) is sum of all the costs on that path (including both source and destination). You can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.

For example, in the following figure, what is the minimum cost path to (2, 2)?


The path with minimum cost is highlighted in the following figure. The path is (0, 0) –> (0, 1) –> (1, 2) –> (2, 2). The cost of the path is 8 (1 + 2 + 2 + 3).


Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.



1) Optimal Substructure
The path to reach (m, n) must be through one of the 3 cells: (m-1, n-1) or (m-1, n) or (m, n-1). So minimum cost to reach (m, n) can be written as “minimum of the 3 cells plus cost[m][n]”.

minCost(m, n) = min (minCost(m-1, n-1), minCost(m-1, n), minCost(m, n-1)) + cost[m][n]

2) Overlapping Subproblems
Following is simple recursive implementation of the MCP (Minimum Cost Path) problem. The implementation simply follows the recursive structure mentioned above.
 */