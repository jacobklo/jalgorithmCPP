//
// Created by Jacob Lo on 28/09/2018.
//

#include "DataStructure/Deque.h"
#include <iostream>
#include <math.h>

using namespace std;

int main() {
  Deque::Deque<int> d;
  for ( int i = 0 ; i < 10 ; i++ ) {
    d.push_back(i);
  }

  for ( Deque::Deque<int>::iterator it = d.begin() ; it != d.end() ; ++it) {
    cout << (*it) << endl;
  }
}