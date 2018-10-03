//
// Created by Jacob Lo on 10/2/18.
//

#include <vector>
#include <iostream>

#include "catch.hpp"
#include "Search/BinarySearch.h"

using namespace std;
using namespace BinarySearch;

TEST_CASE( "Test Binary Search iterate", "[TestBSIterate]" ) {
  vector<int> a { 0,2,3,5,6,9,10,11,14,15 };
  int* arr = a.data();

  REQUIRE( true == numExists( arr, a.size() ,0 ) );
  REQUIRE( false == numExists( arr, a.size() ,1 ) );
  REQUIRE( true == numExists( arr, a.size() ,2 ) );
  REQUIRE( true == numExists( arr, a.size() ,3 ) );
  REQUIRE( false == numExists( arr, a.size() ,4 ) );
  REQUIRE( true == numExists( arr, a.size() ,5 ) );
  REQUIRE( true == numExists( arr, a.size() ,6 ) );
  REQUIRE( false == numExists( arr, a.size() ,7 ) );
  REQUIRE( false == numExists( arr, a.size() ,8 ) );
  REQUIRE( true == numExists( arr, a.size() ,9 ) );
  REQUIRE( true == numExists( arr, a.size() ,10 ) );
  REQUIRE( true == numExists( arr, a.size() ,11 ) );
  REQUIRE( false == numExists( arr, a.size() ,12 ) );
  REQUIRE( false == numExists( arr, a.size() ,13 ) );
  REQUIRE( true == numExists( arr, a.size() ,14 ) );
  REQUIRE( true == numExists( arr, a.size() ,15 ) );
}