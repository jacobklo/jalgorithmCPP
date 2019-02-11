//
// Created by Jacob Lo on 9/29/18.
//

// Problem : Given the root node to a singly linked list, get the node that is w before current node

#pragma once
#include <iostream>
#include <cmath>

using namespace std;

namespace GetNodesBefore {
  int backFive(int num, int base) {
    return (num - base) < 0 ? abs(num) : (num - base) % base;
  }

  class Node {
  public:
    Node(int n) {
      nodeId = n;
    }

    int nodeId;
    // REMEMBER : initialize as nullptr!! Or it will be random address
    Node *next = nullptr;
  };

// Idea is the keep track of the last w nodes while looping
  Node *getNodesBefore(Node *root, Node *n, int w) {
    Node *storage[w];
    int counter = 0;
    Node *current = root;

    while (current->next) {
      current = current->next;
      // If equals and the list has equal or less than 5 elements
      if (n->nodeId == current->nodeId && counter < w) {
        return nullptr;
      }
      // if equals and list has more than 5 elements
      if (n->nodeId == current->nodeId) {
        return storage[backFive(counter, w)];
      }
      // update the current into last 5 records
      storage[counter % w] = current;
      counter++;
    }
    return nullptr;
  }
}
