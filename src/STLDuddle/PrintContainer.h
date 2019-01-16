//
// Created by Jacob Lo on Jan 08, 2019
//

// https://stackoverflow.com/questions/34052948/printing-any-stl-container

#include <iostream>

template< typename T1, typename T2>
std::ostream& operator<< ( std::ostream& out, const std::pair<T1,T2>& val) {
  out << "{" << val.first << ", " << val.second << "}";
  return out;
}

template< template<typename...> class TT, typename... Args>
std::ostream& operator<< ( std::ostream &out, const TT<Args...> &cont) {
  for( auto&& e: cont) {
    out << e << " ";
  }
  return out;
}