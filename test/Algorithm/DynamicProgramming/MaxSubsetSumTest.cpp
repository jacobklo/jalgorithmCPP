//
// Created by Jacob Lo on 17/10/2018.
//

#include <vector>

#include "catch.hpp"

#include "DynamicProgramming/MaxSubsetSum.h"

using namespace std;
using namespace MaxSubsetSum;

TEST_CASE("Test Max Subset Sum", "[TestMaxSubsetSum]") {
  vector<int> arr{ 3,5,-7,8,10};
  int result = maxSubsetSum(arr);
  REQUIRE( 15 == result);
}

TEST_CASE("Test Max Subset Sum 2", "[TestMaxSubsetSum2]") {
  vector<int> arr{ 3,7,4,6,5};
  int result = maxSubsetSum(arr);
  REQUIRE( 13 == result);
}

