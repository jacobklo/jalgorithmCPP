//
// Created by Jacob Lo on 9/30/18.
//

#pragma once

namespace JDeque {

  template<class T>
  class Deque {
    class Node;

  public:
    Deque() {}

    void push_back(T d) {
      if (!rootFront) {
        rootFront = new Node(d);
        rootEnd = rootFront;
      } else {
        Node *newNode = new Node(d);
        rootEnd->next = newNode;
        newNode->last = rootEnd;
        rootEnd = newNode;
      }
    }

    void push_front(T d) {
      if (!rootFront) {
        rootFront = new Node(d);
        rootEnd = rootFront;
      } else {
        Node *newNode = new Node(d);
        newNode->next = rootFront;
        rootFront->last = newNode;
        rootFront = newNode;
      }
    }

    T pop_back() {
      if (rootEnd == nullptr) return 0;
      Node *result = rootEnd;
      if (rootEnd->last == nullptr) {
        rootFront = nullptr;
        rootEnd = nullptr;
      } else {
        rootEnd->last->next = nullptr;
        rootEnd = rootEnd->last;
      }
      return result->data;
    }

    T pop_front() {
      if (rootFront == nullptr) return 0;
      Node *result = rootFront;
      if (rootFront->next == nullptr) {
        rootFront = nullptr;
        rootEnd = nullptr;
      } else {
        rootFront->next->last = nullptr;
        rootFront = rootFront->next;
      }
      return result->data;
    }

    // REMEMBER : how to implement iterator
    class iterator;
    iterator begin() {
      if (rootFront == nullptr) return nullptr;
      return iterator(rootFront);
    }

    iterator end() {
      return iterator(nullptr);
    }
    // Reference for more : https://www.geeksforgeeks.org/implementing-iterator-pattern-of-a-single-linked-list/
    class iterator {
    public:
      iterator(Node *ptr) : m_Ptr(ptr) {}

      iterator& operator++() {
        if ( m_Ptr ) {
          m_Ptr = m_Ptr->next;
        }
        return *this;
      }

      bool operator!=( const iterator& other ) {
        return m_Ptr != other.m_Ptr;
      }

      T operator*() {
        return m_Ptr->data;
      }

    private:
      const Node *m_Ptr;
    };


  private:
    class Node {
    public:

      Node(T d) {
        data = d;
      }

      T data;
      Node *last = nullptr;
      Node *next = nullptr;
    };

    Node *rootFront = nullptr;
    Node *rootEnd = nullptr;
  };
}

