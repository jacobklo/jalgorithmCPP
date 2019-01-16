//
// Created by Jacob Lo on 02/10/2018.
//
#pragma once

#include <vector>
#include <sstream>
#include <iterator>

namespace util {
  // REMEMBER : Print String using std::ostream_iterator
  template <class T>
  std::string vectorToString(const std::vector<T>& vec) {
    std::ostringstream oss;
    std::copy( vec.begin(), vec.end()-1, std::ostream_iterator<T>( oss, ", " ));
    oss << vec.back();
    return oss.str();
  }

}