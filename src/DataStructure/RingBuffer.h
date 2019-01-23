//
// Created by Jacob Lo on Jan 23, 2019
//

#pragma once

#include <array>
#include <sstream>

using namespace std;

namespace RingBuffer {

  template <int BufSize>
  class RingBuffer {
  public:
    int consume() {
      if ( numOfElement <= 0 ) {
        return -1;
      }
      else {
        int result = arr[ oldestPt ];
        oldestPt = calcNextPt( BufSize, oldestPt, 1);
        numOfElement--;
        return result;
      }
    }

    void produce(int x) {

      if ( numOfElement < BufSize ) {
        arr[newestPt] = x;
        numOfElement++;
        newestPt = calcNextPt( BufSize, newestPt, 1);
      }
      else {
        arr[oldestPt] = x;
        newestPt = oldestPt;
        oldestPt = calcNextPt( BufSize, oldestPt, 1);
      }
    }

    string toString() {
      stringstream ss;
      ss << "Container : { ";
      for ( auto i : arr) {
        ss << i << ", ";
      }
      ss << "} oldestPt : " << oldestPt << " , newestPt : " << newestPt << " , numOfElement : " << numOfElement;
      ss << endl;
      return ss.str();
    }

  private:
    int calcNextPt( int bufSize, int currentPt, int move ) {
      return ( currentPt + move ) % bufSize;
    }

    array<int, BufSize> arr {};
    int oldestPt = 0;
    int newestPt = 0;
    int numOfElement = 0;
  };
}