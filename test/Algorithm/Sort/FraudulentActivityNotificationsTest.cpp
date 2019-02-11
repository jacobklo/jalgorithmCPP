//
// Created by Jacob Lo on 17/10/2018.
//

#include <vector>

#include "catch.hpp"

#include "Sort/FraudulentActivityNotifications.h"

using namespace std;
using namespace FraudulentActivityNotifications;

TEST_CASE("Test Fraudulent Activity Notifications", "[TestFraudulentActivityNotifications]") {
  vector<int> arr{ 2,3,4,2,3,6,8,4, };
  int result = FraudulentActivityNotifications::activityNotifications(arr, 5);
  REQUIRE( 2 == result);
}
