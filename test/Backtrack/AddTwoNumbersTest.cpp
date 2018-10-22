//
// Created by Jacob Lo on 10/21/18.
//

#include "catch.hpp"
#include "Backtrack/AddTwoNumbers.h"

using namespace AddTwoNumbers;

TEST_CASE( "Test Add Two Numbers Represented Linked Lists", "[TestAddTwoNumbers]" ) {
  Node* hundard = new Node(1);
  hundard->next = new Node(2);
  hundard->next->next = new Node(3);

  Node* ten = new Node(1);
  ten->next = new Node(0);

  Node* o = new Node(1);
  Node* t = new Node(2);

//  Node result = Node(INT_MIN);
//  add(result, hundard, o);
//  REQUIRE(string("0124") == nodeToString( &result ) );
//
//  Node result2 = Node(INT_MIN);
//  add(result2, hundard, hundard);
//  REQUIRE(string("0246") == nodeToString( &result2 ) );

  Node result3 = Node(INT_MIN);
  add(result3, hundard, ten);
  REQUIRE(string("0133") == nodeToString( &result3 ) );


}
