//
// Created by Jacob Lo on Jan 25, 2019
//

#include "catch.hpp"
#include "DynamicProgramming/Knapsack.h"

#include <vector>

using namespace Knapsack;

TEST_CASE("Test 1", "[Test1]") {
  vector< pair<int, int> > bag { {20, 100},
                                 {30, 120},
                                 {10, 60} };
  REQUIRE(220 == knapsack( bag, 50));
}

TEST_CASE("Test 2", "[Test2]") {
  vector< pair<int, int> > bag { {4, 3},
                                  {3, 2},
                                  {4, 2},
                                  {3, 4},
                                  {6, 40}};
  REQUIRE(40 == knapsack( bag, 6));
}