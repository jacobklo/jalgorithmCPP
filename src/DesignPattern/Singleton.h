//
// Created by Jacob Lo on 10/3/18.
//

// Problem : Implement a Singleton.  It's the most over used and mis-used design pattern.
// Everyone knows the "textbook" implementation of the singleton
// but think of all the different ways you can implement it and what are their pros/cons?
// Make a thread-safe version

#pragma once

#include <mutex>

namespace Singleton {

  // TODO
  template <typename T>
  class Singleton {
  public:
    static Singleton<T>& getInstance() {
      if( instance == nullptr ) {
        std::lock_guard<std::mutex> guard(mutex);
        if ( instance == nullptr ) {
          Singleton<T>* temp = new Singleton<T>;
          instance = temp;
        }
      }
      return instance;
    }
  private:
    Singleton()= default;
    ~Singleton()= default;
    Singleton( const Singleton& )= delete;
    Singleton& operator=( const Singleton& )= delete;

    static std::mutex mutex;
    static Singleton<T>* instance;
    T data;
  };

}

