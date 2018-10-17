//
// Created by Jacob Lo on 28/09/2018.
//

#include <iostream>
#include <random>
#include <vector>

#include "String/ContainersToString.h"

#include "DynamicProgramming/MaxSubsetSum.h"

using namespace std;

int main() {
  vector<int> arr{3,7,4,6,5};
  vector<int> arr2{3,5,-7,8,10};
  int result = MaxSubsetSum::maxSubsetSum(arr);
  cout << result;
}