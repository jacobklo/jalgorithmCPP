//
// Created by Jacob Lo on 9/30/18.
//

#pragma once

template <class T>
class Node {
public:
  Node(T d) {
    data = d;
  }

  T data;
  Node* last;
  Node* next;
};

template <class T>
class Deque {
public:
  Deque() {}

  void push_back(T d) {
    if (!rootFront) {
      rootFront = new Node<T>(d);
      rootEnd = rootFront;
    }
    else {
      Node<T>* newNode = new Node<T>(d);
      rootEnd.next = newNode;
      newNode->last = rootEnd;
      rootEnd = newNode;
    }
  }

  void push_front(T d) {
    if (!rootFront) {
      rootFront = new Node<T>(d);
      rootEnd = rootFront;
    }
    else {
      Node<T>* newNode = new Node<T>(d);
      newNode->next = rootFront;
      rootFront->last = newNode;
      rootFront = newNode;
    }
  }

  T pop_back() {
    if( rootEnd == nullptr) return nullptr;
    Node<T>* result = rootEnd;
    if ( rootEnd->last == nullptr ) {
      rootFront = nullptr;
      rootEnd = nullptr;
    }
    else {
      rootEnd->last->next = nullptr;
      rootEnd = rootEnd->last;
    }
    return result->data;
  }

  T pop_front() {
    if( rootFront == nullptr) return nullptr;
    Node<T>* result = rootFront;
    if ( rootFront->next == nullptr ) {
      rootFront = nullptr;
      rootEnd = nullptr;
    }
    else {
      rootFront->next->last = nullptr;
      rootFront = rootFront->next;
    }
    return result->data;
  }


  Node<T>* rootFront = nullptr;
  Node<T>* rootEnd = nullptr;
};


