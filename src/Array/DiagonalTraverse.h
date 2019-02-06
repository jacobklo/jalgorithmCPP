//
// Created by Jacob Lo on 06/02/2019.
//

// MEDIUM
// Input : {  {1, 2, 3},
//            {4, 5, 6},
//             {7, 8, 9} }

// Output: [1,2,4,7,5,3,6,8,9]

// https://leetcode.com/problems/diagonal-traverse/
#pragma once

#include <vector>
#include <deque>
#include <iostream>

using namespace std;

namespace DiagonalTraverse {
  vector<vector<int>> DoubleArrayToPyramid(const vector<vector<int> > arr) {

    int rowSize = arr.size();
    int colSize = arr.size() == 0 ? 0 : arr[0].size();
    vector<vector<int> > newArr;

    int minSize = min(rowSize, colSize);
    /// top left
    for (int r = 0; r < minSize; r++) {
      vector<int> tmpArr;
      for (int i = 0, j = r; i <= r && j >= 0; i++, j--) {
        tmpArr.push_back(arr[i][j]);
      }
      newArr.push_back(tmpArr);
    }

    /// middle
    if (colSize < rowSize) {
      for (int r = minSize; r < rowSize; r++) {
        deque<int> tmpArr;
        for (int i = r, j = 0; j < minSize; i--, j++) {
          tmpArr.push_front(arr[i][j]);
        }
        newArr.push_back(vector<int>(tmpArr.begin(), tmpArr.end()));
      }
    } else if (colSize > rowSize) {
      for (int r = minSize; r < colSize; r++) {
        vector<int> tmpArr;
        for (int i = 0, j = r; i < minSize; i++, j--) {
          tmpArr.push_back(arr[i][j]);
        }
        newArr.push_back(tmpArr);
      }
    }

    /// bottom right
    if (colSize <= rowSize) {
      for (int r = 1; r < colSize; r++) {
        deque<int> tmpArr;
        for (int i = rowSize - 1, j = r; j < colSize; i--, j++) {
          tmpArr.push_front(arr[i][j]);
        }
        newArr.push_back(vector<int>(tmpArr.begin(), tmpArr.end()));
      }
    } else if (colSize > rowSize) {
      for (int r = 1; r < rowSize; r++) {
        vector<int> tmpArr;
        for (int i = r, j = colSize - 1; i < rowSize; i++, j--) {
          tmpArr.push_back(arr[i][j]);
        }
        newArr.push_back(tmpArr);
      }
    }

    return newArr;
  }

  vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {

    vector<vector<int>> pyramid = DoubleArrayToPyramid(matrix);
    vector<int> result;
    for (int i = 0; i < pyramid.size(); i++) {

      /// if row of pyramid is even, than from left to right
      if (i % 2 == 0) {
        for (int j = pyramid[i].size() - 1; j >= 0; j--) {
          result.push_back(pyramid[i][j]);
        }
      }
        /// if row of pyramid is odd, than from right to left;
      else {
        for (auto ele : pyramid[i]) {
          result.push_back(ele);
        }

      }
    }

    return result;
  }

  void test() {
    vector<vector<vector<int> > > ins =
            {
                    {
                            {1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}
                    },

                    {
                            {1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16}
                    },

                    {
                            {1, 2, 3, 4},
                            {5, 6, 7, 8}
                    },

                    {
                            {1, 2},
                            {3, 4},
                            {5, 6},
                            {7, 8}
                    },

                    {
                            {1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12}
                    },

                    {
                            {1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9},
                            {10, 11, 12}
                    }
            };

    for (int i = 0; i < ins.size(); i++) {
      vector<vector<int>> resultPyramid = DoubleArrayToPyramid(ins[i]);

      for (auto v : resultPyramid) {
        for (int i : v) {
          cout << i << " ";
        }
        cout << endl;
      }
      cout << "RESULT: " << endl;

      vector<int> result = findDiagonalOrder(ins[i]);
      for (auto i : result) {
        cout << i << " ";
      }
      cout << "Next : " << endl;
    }
  }
}