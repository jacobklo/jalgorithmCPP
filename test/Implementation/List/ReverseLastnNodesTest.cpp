//
// Created by Jacob Lo on 9/30/18.
//

#include "catch.hpp"
#include "DataStructure/LinkedList/ReverseLastnNodes.h"

namespace ReverseLastnNodes {
  Node genList(int num) {
    Node root(0);
    Node *current = &root;

    for (int i = 1; i < num; i++) {
      Node *newNode = new Node(i);
      current->next = newNode;
      current = newNode;
    }
    return root;
  }

// REMEMBER : DO NOT PUT Space as first character in name!!
  TEST_CASE("Test Gen List", "[TestGenList]") {
    Node root = genList(7);
    Node *n1 = root.next;
    Node *n2 = n1->next;
    Node *n3 = n2->next;
    Node *n4 = n3->next;
    Node *n5 = n4->next;
    Node *n6 = n5->next;

    REQUIRE(0 == root.m_Id);
    REQUIRE(1 == n1->m_Id);
    REQUIRE(2 == n2->m_Id);
    REQUIRE(3 == n3->m_Id);
    REQUIRE(4 == n4->m_Id);
    REQUIRE(5 == n5->m_Id);
    REQUIRE(6 == n6->m_Id);
    REQUIRE(nullptr == n6->next);
  }

  TEST_CASE( "Test Reverse Last 2 nodes", "[TestReverseLast2Nodes]") {
    Node root = genList(2);
    reverseLastNNode(&root, 2);

    Node *n1 = root.next;

    REQUIRE(1 == root.m_Id);
    REQUIRE(0 == n1->m_Id);
  }

  TEST_CASE( "Test Reverse Last 2 nodes 2", "[TestReverseLast2Nodes2]") {
    Node root = genList(3);
    reverseLastNNode(&root, 2);

    Node *n1 = root.next;
    Node *n2 = n1->next;

    REQUIRE(0 == root.m_Id);
    REQUIRE(2 == n1->m_Id);
    REQUIRE(1 == n2->m_Id);

  }

  TEST_CASE( "Test Reverse Last 5 nodes", "[TestReverseLast5Nodes]") {
    Node root = genList(7);
    reverseLastNNode(&root, 5);

    Node *n1 = root.next;
    Node *n2 = n1->next;
    Node *n3 = n2->next;
    Node *n4 = n3->next;
    Node *n5 = n4->next;
    Node *n6 = n5->next;

    REQUIRE(0 == root.m_Id);
    REQUIRE(1 == n1->m_Id);
    REQUIRE(6 == n2->m_Id);
    REQUIRE(5 == n3->m_Id);
    REQUIRE(4 == n4->m_Id);
    REQUIRE(3 == n5->m_Id);
    REQUIRE(2 == n6->m_Id);

  }
}
