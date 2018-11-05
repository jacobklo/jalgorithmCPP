//
// Created by Jacob Lo on 11/4/18.
//

#include "catch.hpp"
#include "Array/LarrysArray.h"

TEST_CASE( "Most Larry's Array", "[LarrysArrayTest1]" ) {
  vector<int> arr{ 1,6,5,2,4,3 };
  vector<int> arr2{ 1,2,3,5,4 };
  vector<int> arr3{ 3,1,2 };
  bool result = LarrysArray::larrysArray( arr );
  bool result2 = LarrysArray::larrysArray( arr2 );
  bool result3 = LarrysArray::larrysArray( arr3 );
  REQUIRE( result == true );
  REQUIRE( result2 == false );
  REQUIRE( result3 == true );
}