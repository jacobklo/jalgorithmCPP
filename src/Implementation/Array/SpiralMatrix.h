//
// Created by Jacob Lo on Feb 13, 2019
//

// MEDIUM
// https://leetcode.com/problems/spiral-matrix/

/*
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

 Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */
#pragma once

#include <deque>
#include <vector>
#include <iostream>

using namespace std;

// TODO: works locally but not on Leetcode
// TODO: optimize
namespace SpiralMatrix {
  void calcRows(vector<vector<int>> &matrix, deque<deque<int>> &result) {

    for (int i = 0, j = 0, k = matrix.size() - 1; i < matrix.size(); i++) {

      if (i % 2 == 0) {
        result.push_back(deque<int>(matrix[j].begin(), matrix[j].end()));
        j++;

      } else {
        result.push_back(deque<int>(matrix[k].begin(), matrix[k].end()));
        k--;
      }
    }
  }

  void calcColumn(vector<vector<int> > &matrix, deque<deque<int>> &result) {

    for (int i = 0, x = matrix[0].size() - 1, y = 0; i < matrix[0].size(); i++) {

      if (i % 2 == 0) {
        deque<int> tmpCol;
        for (int r = 0; r < matrix.size(); r++) {
          tmpCol.push_back(matrix[r][x]);
        }
        result.push_back(tmpCol);
        x--;
      } else {
        deque<int> tmpCol;
        for (int r = 0; r < matrix.size(); r++) {
          tmpCol.push_back(matrix[r][y]);
        }
        result.push_back(tmpCol);
        y++;
      }
    }
  }

  void calcRemoveRow(deque<deque<int>> &result) {

    int i = 0;
    for (int m = 0, n = 0; i < result.size(); i++) {

      if (m >= (result[0].size() - n)) {
        break;
      }
      if (m > 0) {
        result[i].erase(result[i].begin(), result[i].begin() + m);
      }
      if (n > 0) {
        result[i].erase(result[i].begin() + (result[i].size() - n), result[i].end());
      }

      if (i % 2 == 1) {
        m++;
      } else if (i % 2 == 0) {
        n++;
      }
    }

    result.erase(result.begin() + i, result.end());
  }

  void calcRemoveCol(deque<deque<int>> &result) {

    int i = 0;
    for (int m = 1, n = 0; i < result.size(); i++) {

      if (m > (result[0].size() - n)) {
        break;
      }
      if (m > 0) {
        result[i].erase(result[i].begin(), result[i].begin() + m);
      }
      if (n > 0) {
        result[i].erase(result[i].begin() + (result[i].size() - n), result[i].end());
      }

      if (i % 2 == 1) {
        m++;
      } else if (i % 2 == 0) {
        n++;
      }
    }

    result.erase(result.begin() + i, result.end());
  }

  void calcFlip(deque<deque<int>> &result) {

    for (int i = 0; i < result.size(); i++) {
      if (i % 2 == 1) {
        deque<int> tmp = result[i];
        result[i] = deque<int>(tmp.rbegin(), tmp.rend());
      }
    }
  }


  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    if (matrix.empty()) return vector<int>();

    deque<deque<int> > rrrows, cccol;
    calcRows(matrix, rrrows);
    calcRemoveRow(rrrows);
    calcFlip(rrrows);
    calcColumn(matrix, cccol);
    calcRemoveCol(cccol);
    calcFlip(cccol);

    vector<int> result;

    int i = 0, j = 0, k = 0;
    for (; i < j < rrrows.size() && k < cccol.size(); i++) {

      if (i % 2 == 0) {
        for (int x = 0; x < rrrows[j].size(); x++) {
          result.push_back(rrrows[j][x]);
        }
        j++;
      } else {
        for (int x = 0; x < cccol[k].size(); x++) {
          result.push_back(cccol[k][x]);
        }
        k++;
      }
    }

    if (j < rrrows.size()) {
      for (int x = 0; x < rrrows[j].size(); x++) {
        result.push_back(rrrows[j][x]);
      }
    }
    if (k < cccol.size()) {
      for (int x = 0; x < cccol[k].size(); x++) {
        result.push_back(cccol[k][x]);
      }
    }
    return result;
  }

  void test() {
    vector<vector<vector<int> > > ms
            {
                    {
                            {1, 2, 3, 4},
                                 {5, 6, 7, 8},
                                      {9, 10, 11, 12},
                                           {13, 14, 15, 16},
                                                {17, 18, 19, 20},
                                                     {21, 22, 23, 24}
                    },
                    {
                            {1, 2, 3, 4, 100},
                                 {5, 6, 7, 8, 200},
                                      {9, 10, 11, 12, 300},
                                           {13, 14, 15, 16, 400},
                                                {17, 18, 19, 20, 500},
                                                     {21, 22, 23, 24, 600}
                    },
                    {
                            {1}, {2}, {3}, {4}, {5}, {6}
                    },
                    {
                            {1}, {2}, {3}, {4}, {5}, {6}, {7}
                    },
                    {}
            };

    for (auto m : ms) {
//      cout << spiralOrder(m) << endl << endl;


    }
  }
}
