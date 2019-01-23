//
// Created by Jacob Lo on Jan 23, 2019
//

// MEDIUM - NOT FINISH
// https://leetcode.com/problems/restore-ip-addresses/

#pragma once

#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

namespace RestoreIPAddress {
  bool checkValidIp ( const string& p1, const string& p2, const string& p3, const string& p4 ) {
    return p1.size() <= 3 && p2.size() <= 3 && p3.size() <= 3 && p4.size() <= 3 && stoi(p1) < 256 && stoi(p2) < 256 && stoi(p3) < 256 && stoi(p4) < 256;
  }


  vector<string> restoreIpAddresses(string s) {
    vector<string> holder;

    for ( int i = 1; i <= 3 ; i++ ) {
      for ( int j = 1 ; j <= 3 ; j++ ) {
        for ( int k = 1 ; k <= 3 && (i+j+k) < s.size() ; k++ ) {
          string p1 = s.substr(0, i), p2 = s.substr(i, j), p3 = s.substr( i+j , k), p4 = s.substr(i+j+k, s.size());
          if ( checkValidIp (p1, p2, p3, p4 )) {
            stringstream tmpss;
            tmpss << p1 << '.' << p2 << '.' << p3 << '.' << p4;
            holder.push_back(tmpss.str());
          }
        }
      }

    }

    return holder;
  }

  void test() {
    vector<string> ips = {"010010"};
    for ( auto ip : ips ) {
      vector<string> holder = restoreIpAddresses(ip);

      for ( auto s : holder ) {
        cout << s << endl;
      }

      cout << endl << endl;
    }

  }
}