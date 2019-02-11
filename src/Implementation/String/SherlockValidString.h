//
// Created by Jacob Lo on Jan 07, 2019.
//

// MEDIUM
// https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings
// Sherlock considers a string to be valid if all characters of the string appear the same number of times. It is also valid if he can remove just  character at  index in the string, and the remaining characters will occur the same number of times.
#pragma once

#include <map>
#include <unordered_map>

using namespace std;

namespace SherlockValidString {
  struct IntDecrementComparator {
    bool operator() ( const int& lhs, const int& rhs ){
      return lhs > rhs;
    }
  };
  bool isValid(string s) {

    /// put char and count into hash map
    unordered_map<char, int> hmap;
    for ( string::iterator it = s.begin() ; it != s.end() ; ++it ) {
      char currentChar = (char) (*it);
      if ( hmap.find( currentChar ) == hmap.end() ) {
        hmap.insert(pair<char, int>( currentChar, 1));
      }

      else {
        hmap.at( currentChar ) += 1;
      }
    }

    /// add occurances.
    map<int, int, IntDecrementComparator> rmap;
    for ( unordered_map<char, int>::iterator it = hmap.begin() ; it != hmap.end() ; ++it) {
      if ( rmap.find( it->second ) == rmap.end() ) {
        rmap.insert( pair<int,int> ( it->second, 1) );
      }
      else {
        rmap.at( it->second ) += 1;
      }
    }

    /// check occurances. The correct occurances is all char has same count, so rmap's size == 1,
    /// or all char has same count, with 1 char has 1 more count.

    // check if more than 2 sizes for each char count. If so, false
    if ( rmap.size() > 2 ) {
      return false;
    }

    // check case : all char has same count, with 1 char has 1 more count.
    if ( rmap.size() == 2 ) {
      auto firstCountPair = rmap.begin();
      auto secondCountPAir = firstCountPair++;

      // check with 1 char has 1 more count.
      if ( firstCountPair->second != 1 && secondCountPAir->second != 1) {
        return false;
      }

      if ( firstCountPair->second == 1 && firstCountPair->first == 1 || secondCountPAir->second == 1 && secondCountPAir->first == 1) {
        return true;
      }

      if ( !((firstCountPair->second == 1 && firstCountPair->first - secondCountPAir->first == 1) ||
             (secondCountPAir->second == 1 && secondCountPAir->first - firstCountPair->first == 1)) ) {
        return false;
      }
    }
    return true;
  }

  void test() {
    string s[] = { "abc",
                   "abcc",
                   "abccc",
                   "abcabc",
                   "abcabcc",
                   "aabbcc",
                   "aabbccc",
                   "aabbcccc",
                   "aabbccd"};
    for( auto each : s) {
      bool result = SherlockValidString::isValid(each);
      // cout << each << " " << result << endl;
    }
  }
}


