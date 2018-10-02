//
// Created by Jacob Lo on 28/09/2018.
//

#include "DataStructure/Deque.h"
#include <iostream>
#include <math.h>

using namespace std;

int main() {
  JDeque::Deque<int> d;
  for ( int i = 0 ; i < 10 ; i++ ) {
    d.push_back(i);
  }

//  for ( int i = 100 ; i > 0 ; i=i-10) {
//    d.push_front(i);
//  }



  for ( JDeque::Deque<int>::iterator it = d.begin() ; it != d.end() ; ++it) {
    //cout << (*it) << endl;
  }
  cout << "sfd";
}