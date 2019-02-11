//
// Created by Jacob Lo on Feb 11, 2019.
//

// MEDIUM and HARD
// Given an array of non-negative integers, you are initially positioned at the first index of the array.

//Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

// https://leetcode.com/problems/jump-game/
// https://leetcode.com/problems/jump-game-ii/

#pragma once

#include <vector>
#include <iostream>
#include <climits>

using namespace std;

namespace JumpGame {

  bool canJump(vector<int>& nums) {
    int maxPathPos = 0;
    int maxSteps = 0;

    for ( int i = 0 ; i < nums.size() ; i++ ) {

      if ( maxPathPos < i+nums[i] ) {
        maxPathPos = i+nums[i];
        maxSteps++;

      }
      if ( maxPathPos <= i && i + 1 < nums.size() ) {
        return false;
      }
    }

    return true;
  }

  // calc min jump required
  // TODO :
  int jump(vector<int>& nums) {
    vector<int> minStepsTo ( nums.size(), INT_MAX);
    minStepsTo[0] = 0;
    int maxReachPos = 0;
    int curStep = 0;

    for ( int i = 0; i < nums.size() ; i++ ) {

      if ( maxReachPos < i ) {
        return INT_MAX;
      }

      if ( maxReachPos == i && i < nums.size() - 1) {
        maxReachPos = i+nums[i] > nums.size()-1  ? nums.size() - 1 : i+nums[i];
        minStepsTo[ maxReachPos ] = curStep + 1;
        curStep = minStepsTo[ maxReachPos ];
      }
      else {
        maxReachPos = i+nums[i] > nums.size()-1  ? nums.size() - 1 : i+nums[i];
        minStepsTo[ maxReachPos ] = curStep;
      }
    }

    return minStepsTo[minStepsTo.size() - 1];
  }

  void test() {
    vector< vector<int> > r {
            {3,2,1,0,4},
            {2,3,1,1,4},
            {0},
            {2,3,0,1,4},
            {1,2,1,1,1}
    };

    for ( auto v : r ) {
      cout << canJump(v) << endl;
    }
  }
}