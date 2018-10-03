//
// Created by Jacob Lo on 28/09/2018.
//

#include <iostream>
#include <random>
#include <vector>

#include "String/ContainersToString.h"

#include "Search/BinarySearch.h"

using namespace std;


int main() {
  vector<int> a { 0,2,3,5,6,9,10,11,14,15 };
  int* arr = a.data();

  for ( int i = 0 ; i < 16 ; i++ ) {
    cout << i << boolalpha << BinarySearch::numExists(arr, a.size(), i) << endl;
  }
}