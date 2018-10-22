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

Node* NineNine = new Node(9);
NineNine->next = new Node(9);
NineNine->next->next = new Node(9);

string result = add( hundard, o);
REQUIRE(string("124") == result );

string result2 = add(hundard, hundard);
REQUIRE(string("246") == result2 );

string result3 = add(hundard, ten);
REQUIRE(string("133") == result3 );

string result4 = add(NineNine, NineNine);
REQUIRE(string("1998") == result4 );


}
