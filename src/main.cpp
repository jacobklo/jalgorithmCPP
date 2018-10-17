//
// Created by Jacob Lo on 28/09/2018.
//

#include <iostream>
#include <random>
#include <vector>

#include "String/ContainersToString.h"

#include "Sort/FraudulentActivityNotifications.h"

using namespace std;

int main() {
  vector<int> arr{ 2,3,4,2,3,6,8,4, };
  int result = FraudulentActivityNotifications::activityNotifications(arr, 5);
  cout << result;
}