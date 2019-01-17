//
// Created by Jacob Lo on Jan 17, 2019
//

#pragma once

#include <vector>
#include <string>

using namespace std;

// Split a string base on a string delimiter
vector<string> split( const string& s, const string& delimiter ) {
  vector<string> result;
  int cur, next = 0;

  next = s.find(delimiter);

  while( next != string::npos) {
    result.push_back( s.substr ( cur, next - cur ) );
    cur = next + 1;
    next = s.find(delimiter, cur);
  }
  result.push_back( s.substr ( cur, next - cur ) );
  return result;
}