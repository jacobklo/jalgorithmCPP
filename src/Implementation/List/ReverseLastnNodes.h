//
// Created by Jacob Lo on 9/30/18.
//

// Problem : Given the root node to a singly linked list, reverse the last n nodes in the list.

#pragma once
#include <cmath>

namespace ReverseLastnNodes {
  class Node {
  public:
    Node(int id) { m_Id = id; }

    int m_Id;
    // REMEMBER : initialize as nullptr!! Or it will be random address
    Node *next = nullptr;
  };

  void swap(Node *a, Node *b) {
    // TODO swap potiner instead
    int tmp = a->m_Id;
    a->m_Id = b->m_Id;
    b->m_Id = tmp;
  }

  void reverseLastNNode(Node *root, int n) {
    if (root == nullptr) return;
    Node *current = root;

    // create pointer storage for last n positions
    Node *storage[n];
    int count = 0;

    // loop through the next node and put in storage
    while (current != nullptr) {

      storage[count % n] = current;
      count++;
      current = current->next;
    }

    // if count < n, means list is smaller than n, cannot reverse
    if (count < n) return;

    // reverse last n node
    for ( int i = 0 ; i < n/2 ; i++ ) {
      int lastPos = ((count-1) - i) % n;
      int firstPos = ((count - n) + i) % n;
      swap( storage[lastPos], storage[firstPos]);
    }

  }

}
