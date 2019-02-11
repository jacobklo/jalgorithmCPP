//
// Created by Jacob Lo on 10/18/18.
//

#pragma once

#include <stack>

using namespace std;

namespace QueueUsingTwoStack {

  template <class T>
  class Queue {
    stack<T> pushStack, popStack;

    // 6,7,8
    // 5,4,3
  public:
    Queue(){}

    void push(T x) {
      pushStack.push(x);
    }

    void pop() {
      /// if popStack is empty, push everything from pushStack to popStack
      reorder();
      /// than u can pop
      popStack.pop();
    }

    T front() {
      /// if popStack is empty, push everything from pushStack to popStack
      reorder();
      /// than u can look
      return popStack.top();
    }

  private:
    void reorder() {
      if ( popStack.empty() ) {
        while( !pushStack.empty() ) {
          popStack.push( pushStack.top() );
          pushStack.pop();
        }
      }
    }
  };

}