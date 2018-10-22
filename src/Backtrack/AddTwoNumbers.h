//
// Created by Jacob Lo on 10/21/18.
//

/*
 * EASY
 * https://www.geeksforgeeks.org/sum-of-two-linked-lists/
 * Given two numbers represented by two linked lists, write a function that returns sum list. The sum list is linked list representation of addition of two input numbers. It is not allowed to modify the lists. Also, not allowed to use explicit extra space (Hint: Use Recursion).

Example

Input:
  First List: 5->6->3  // represents number 563
  Second List: 8->4->2 //  represents number 842
Output
  Resultant list: 1->4->0->5  // represents number 1405
 */
#pragma once

#include <string>
#include <climits>

using namespace std;

namespace AddTwoNumbers {
  struct Node {
    int data;
    Node* next = nullptr;

    Node(int d) { data = d; }
  };

  string nodeToString(Node* root) {
    string result = "";
    while(root != nullptr) {
      result += to_string(root->data);
      root = root->next;
    }
    return result;
  }

  void add(Node& result, Node* a, Node* b) {

    /// if both a and b is last node
    if ( a->next == nullptr && b->next == nullptr ) {
      int added = a->data + b->data;
      Node* newNode = new Node( ( added > 10 ? added - 10: added ) );
      result.data = ( added > 10 ? 1 : 0 );
      result.next = newNode;
      return;
    }

    // TODO : test case 123 + 10 wrong!
    result.next = new Node(INT_MIN);
    Node* ANextNodeOrLast = ( a->next != nullptr ? a->next : a );
    Node* BNextNodeOrLast = ( b->next != nullptr ? b->next : b );

    add( *(result.next), ANextNodeOrLast, BNextNodeOrLast);
    int added = result.next->data;
    // if current a is not the last node, which means we need to handle current a,
    // if it is last node already, then recursive already added, no need to handle
    // Think of a == 1[2]3, where [] is current
    // b == [6]
    // we recursive call add, where recursive-current of a == 12[3], and b == [6].
    // if this current recurion, it should be a == 1[2]3, b == [0]6
    if ( a->next != nullptr ) {
      added += a->data;
    }
    if ( b->next != nullptr ) {
      added += b->data;
    }
    result.next->data = ( added > 10 ? added - 10: added );
    result.data = ( added > 10 ? 1 : 0 );
    return;

  }
}
