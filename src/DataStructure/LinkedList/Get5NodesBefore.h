//
// Created by Jacob Lo on 9/29/18.
//

// Problem : Given the root node to a singly linked list, reverse the last 5 nodes in the list.

#pragma once
#include <iostream>
#include <cmath>

using namespace std;

int backFive(int num, int base ) {
  return (num - base) < 0 ? abs(num) : (num - base) % base;
}

class Node {
public:
  Node(int n) {
    nodeId = n;
  }

  int nodeId;
  Node* next;
};

// Idea is the keep track of the last 5 nodes while looping
Node* get5NodesBefore(Node *root, Node *n) {
  Node* storage[5];
  int counter = 0;
  Node* current = root;

  while ( current->next ) {
    current = current->next;
    // If equals and the list has equal or less than 5 elements
    if ( n->nodeId == current->nodeId && counter < 5) {
      return nullptr;
    }
    // if equals and list has more than 5 elements
    if ( n->nodeId == current->nodeId) {
      return storage[ backFive( counter, 5 )];
    }
    // update the current into last 5 records
    storage [ counter % 5 ] = current;
    counter++;
  }
  return nullptr;
}

