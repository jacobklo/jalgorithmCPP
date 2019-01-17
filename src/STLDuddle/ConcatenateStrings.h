//
// Created by Jacob Lo on Jan 17, 2019.
//

#pragma once

#include <string>
#include <sstream>

using namespace std;

string concatString() {
  std::stringstream ss;
  ss << "Hello, world, " << " " << "sdfdsf";
  return ss.str();
}