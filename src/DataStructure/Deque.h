//
// Created by Jacob Lo on 9/30/18.
//

#pragma once

namespace Deque {
  template<class T>
  class Node {
  public:
    Node(T d) {
      data = d;
    }

    T data;
    Node *last;
    Node *next;
  };

  template<class T>
  class Deque {
  public:
    Deque() {}

    void push_back(T d) {
      if (!rootFront) {
        rootFront = new Node<T>(d);
        rootEnd = rootFront;
      } else {
        Node<T> *newNode = new Node<T>(d);
        rootEnd.next = newNode;
        newNode->last = rootEnd;
        rootEnd = newNode;
      }
    }

    void push_front(T d) {
      if (!rootFront) {
        rootFront = new Node<T>(d);
        rootEnd = rootFront;
      } else {
        Node<T> *newNode = new Node<T>(d);
        newNode->next = rootFront;
        rootFront->last = newNode;
        rootFront = newNode;
      }
    }

    T pop_back() {
      if (rootEnd == nullptr) return nullptr;
      Node<T> *result = rootEnd;
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
      if (rootFront == nullptr) return nullptr;
      Node<T> *result = rootFront;
      if (rootFront->next == nullptr) {
        rootFront = nullptr;
        rootEnd = nullptr;
      } else {
        rootFront->next->last = nullptr;
        rootFront = rootFront->next;
      }
      return result->data;
    }

    // https://gist.github.com/jeetsukumaran/307264
    // TODO fix error
    class iterator {
    public:
      iterator(Node<T> *ptr) : m_Ptr(ptr) {}

      iterator operator++() {
        iterator i = *this;
        m_Ptr = m_Ptr->next;
        return i;
      }

      bool operator==( const iterator& other ) {
        return m_Ptr == other.m_Ptr;
      }
      bool operator!=( const iterator& other ) {
        return m_Ptr != other.m_Ptr;
      }
      Node<T>& operator*() {
        return **m_Ptr;
      }

    private:
      Node<T> *m_Ptr;
    };

    iterator begin() {
      if (rootFront == nullptr) return nullptr;
      return iterator(rootFront);
    }

    iterator end() {
      return iterator(nullptr);
    }

    Node<T> *rootFront = nullptr;
    Node<T> *rootEnd = nullptr;
  };
}

