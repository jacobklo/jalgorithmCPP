//
// Created by Jacob Lo on Jan 08, 2019.
//

// STL Sort implemented as Quick-Sort.

#pragma once

#include <vector>
#include <algorithm>

namespace STLDuddle {

  /// default sort ( default comparator with increment )
  void sortDefaultIncrement () {
    int arr[] =  {32,71,12,45,26,80,53,33};
    std::vector<int> v( arr, arr+8);
    std::sort(v.begin(), v.end() );
    std::cout <<
  }
};