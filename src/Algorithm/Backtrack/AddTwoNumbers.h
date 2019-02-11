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
    /// REMEMBER : to init as nullptr!
    Node* next = nullptr;

    Node(int d) { data = d; }

    static string nodeToString(Node* root) {
      string result = "";
      while (root != nullptr) {
        result += to_string(root->data);
        root = root->next;
      }
      return result;
    }

    static int size(Node* root ) {
      int i = 1;
      for( ; root->next != nullptr; i++, root = root->next ) { }
      return i;
    }
  };

  /// util add method
  void add(Node& result, int aPos, int bPos, Node* a, Node* b) {

    /// if both a and b is last node
    if ( aPos == 0 && bPos == 0 ) {
      int added = a->data + b->data;
      Node* newNode = new Node( ( added > 10 ? added - 10: added ) );
      result.data = ( added > 10 ? 1 : 0 );
      result.next = newNode;
      return;
    }

    result.next = new Node(INT_MIN);
    int added = 0;
    /// if both a's and b's current node is not the last node, but the digit align, then add current digit
    if ( aPos == bPos ) {
      add( *(result.next), aPos-1, bPos-1, a->next, b->next);
      added = result.next->data + a->data + b->data;
    }

      /// digit from a and b is not align, recursively call until it is align
    else if ( aPos > bPos ) {
      add( *(result.next), aPos-1, bPos, a->next, b);
      added = result.next->data + a->data;
    }

    else if ( aPos < bPos ) {
      add( *(result.next), aPos, bPos-1, a, b->next);
      added = result.next->data + b->data;
    }
    result.next->data = ( added > 10 ? added - 10: added );
    // add first digit so far, it is either 1 or 0, because added digit from last digit is max of 19
    result.data = ( added > 10 ? 1 : 0 );
  }

  /// wrapper method
  string add( Node* a, Node* b) {
    int aPos = Node::size(a) - 1;
    int bPos = Node::size(b) - 1;
    Node * result = new Node(INT_MIN);
    add( *result, aPos, bPos, a, b);

    // remove first digit if it is 0
    if( result->data == 0 ) {
      result = result->next;
    }
    return Node::nodeToString(result );
  }

}
