//
// Created by Jacob Lo on 9/28/18.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Math/BusStop.h"

TEST_CASE("Bus Stops Test Person 1-3", "[BusStopsTestPerson]") {
  vector<long> busStops{0, 10, 40, 100};
  long everyW = 20;
  long busV = 10;

  vector<long> points{ 0, 15, 40 };
  vector<long> starts{ 0, 10, 2 };
  vector<long> walks{ 4, 1, 16 };

  REQUIRE( 10 == minTimeForAPersonToEnd( busStops, everyW, busV, points[0], starts[0], walks[0] ) );
  REQUIRE( 30 == minTimeForAPersonToEnd( busStops, everyW, busV, points[1], starts[1], walks[1] ) );
  REQUIRE( 5.75 == minTimeForAPersonToEnd( busStops, everyW, busV, points[2], starts[2], walks[2] ) );
}