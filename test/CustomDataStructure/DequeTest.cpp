//
// Created by Jacob Lo on 10/1/18.
//

#include "catch.hpp"
#include "DataStructure/Deque.h"

using namespace JDeque;

TEST_CASE("Test Deque Push Back", "[TestPushBack]") {
  Deque<int> d;
  for (int i = 0; i < 10; i++) {
    d.push_back(i);
  }

  int i = 0;
  for ( Deque<int>::iterator it = d.begin(); it != d.end() ; ++it, i++) {
    REQUIRE( i == (*it));
  }
}

TEST_CASE("Test Deque Push Front", "[TestPushFront]") {
  Deque<int> d;
  for (int i = 9; i >= 0; i--) {
    d.push_front(i);
  }

  int i = 0;
  for ( Deque<int>::iterator it = d.begin(); it != d.end() ; ++it, i++) {
    REQUIRE( i == (*it));
  }
}

TEST_CASE("Test Deque Pop Back", "[TestPopBack]") {
  Deque<int> d;
  for (int i = 0; i < 10; i++) {
    d.push_back(i);
  }

  for (int i = 0; i < 5; i++) {
    d.pop_back();
  }

  int i = 0;
  Deque<int>::iterator it = d.begin();
  for ( ; it != d.end() && i < 5; ++it, i++) {
    REQUIRE( i == (*it));
  }
  REQUIRE( !(it != d.end()) );
}

TEST_CASE("Test Deque Pop Front", "[TestPopFront]") {
  Deque<int> d;
  for (int i = 0; i < 10; i++) {
    d.push_back(i);
  }

  for (int i = 0; i < 5; i++) {
    d.pop_front();
  }

  int i = 5;
  Deque<int>::iterator it = d.begin();
  for ( ; it != d.end() && i < 10; ++it, i++) {
    REQUIRE( i == (*it));
  }
  REQUIRE( !(it != d.end()) );
}
