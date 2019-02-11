//
// Created by Jacob Lo on 10/10/18.
//

#include "catch.hpp"
#include "DynamicProgramming/MinCostPath.h"

using namespace MinCostPath;

TEST_CASE("Test Min Cost Path", "[TestMinCostPath]") {
  vector< vector<int> > map { { 1,3,1,1 },
                              { 2,4,4,2 },
                              { 3,1,1,3 },
                              { 3,1,1,1 }};
  int result = MinCostPath::minCostPath( map );
  REQUIRE( 10 == result);
}

TEST_CASE("Test Min Cost Path2", "[TestMinCostPath2]") {
  vector< vector<int> > map { {1,2},
                              {1,1}};
  int result = MinCostPath::minCostPath( map );
  REQUIRE( 3 == result);
}
