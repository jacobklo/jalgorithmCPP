//
// Created by Jacob Lo on 10/18/18.
//

#include "catch.hpp"
#include "Backtrack/DavisStaircase.h"

TEST_CASE( "Test Davis Staircase", "[TestDavisStaircase]" ) {
    REQUIRE( 1132436852 == DavisStaircase::stepPerms(35) );
    REQUIRE( 53798080 ==  DavisStaircase::stepPerms(30) );
    REQUIRE( 334745777 == DavisStaircase::stepPerms(33) );
    REQUIRE( 2082876103 == DavisStaircase::stepPerms(36) );
    REQUIRE( 121415 == DavisStaircase::stepPerms(20) );

}