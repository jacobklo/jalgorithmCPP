//
// Created by Jacob Lo on 10/10/18.
//

#include "catch.hpp"
#include "Dictionary/CountTripletsGeometricProgression.h"

using namespace CountTripletsGeometricProgression;

TEST_CASE("Test Count Triplets in Geometric Progression", "[TestCountTripletsGeometricProgression]") {
  vector<long> arr{ 1,3,3,9,9};
  long result = CountTripletsGeometricProgression::countTriplets( arr, 3 );
  REQUIRE ( 4 == result );
}