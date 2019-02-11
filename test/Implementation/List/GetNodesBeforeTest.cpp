//
// Created by Jacob Lo on 9/29/18.
//

#include "catch.hpp"
#include "DataStructure/LinkedList/GetNodesBefore.h"

namespace GetNodesBefore {
  Node genList() {
    Node root(0);
    Node *current = &root;
    for (int i = 1; i < 9; i++) {
      Node *newNode = new Node(i);
      current->next = newNode;
      current = newNode;
    }
    return root;
  }

  TEST_CASE("Test Reverse Mode from -1 to -5", "[ReverseMode1]") {
    REQUIRE(0 == backFive(0, 5));
    REQUIRE(1 == backFive(1, 5));
    REQUIRE(2 == backFive(2, 5));
    REQUIRE(3 == backFive(3, 5));
    REQUIRE(4 == backFive(4, 5));
    REQUIRE(0 == backFive(5, 5));
  }

  TEST_CASE("Test Reverse Mode from 1 to 5", "[ReverseMode1]") {
    REQUIRE(1 == backFive(6, 5));
    REQUIRE(2 == backFive(7, 5));
    REQUIRE(3 == backFive(8, 5));
    REQUIRE(4 == backFive(9, 5));
    REQUIRE(0 == backFive(10, 5));
  }

  TEST_CASE("Test Reverse Node", "[ReverseNode]") {
    Node root = genList();
    Node *n5 = root.next->next->next->next->next;
    Node *n6 = n5->next;
//  REQUIRE( 0 == getNodesBefore(&root, n5, 5)->nodeId );
    REQUIRE(1 == getNodesBefore(&root, n6, 5)->nodeId);
  }
}
