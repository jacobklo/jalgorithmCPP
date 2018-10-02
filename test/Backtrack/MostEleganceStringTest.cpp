//
// Created by Jacob Lo on 28/09/2018.
//
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Backtrack/MostEleganceString.h"

TEST_CASE( "Most Elegance String test 1", "[MostEleganceStringTest1]" ) {
    vector<string> s{ "1032", "2467", "48957" };
    vector<int> b{ 2, 3, 1 };

    int result = maximumElegance( 2, s, b);
    REQUIRE( result == 7 );
}