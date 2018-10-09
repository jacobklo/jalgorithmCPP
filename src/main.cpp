//
// Created by Jacob Lo on 28/09/2018.
//

#include <iostream>
#include <random>
#include <vector>

#include "String/ContainersToString.h"

#include "Array/MinSwap.h"

using namespace std;


int main() {
//  vector<int> arr{ 8,7,6,5,4,3,2,1 };
  vector<int> arr{ 4,3,1,2};
  int result = MinSwap::minimumSwaps( arr) ;
  cout << result;
}