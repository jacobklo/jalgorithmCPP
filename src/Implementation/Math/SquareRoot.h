//
// Created by Jacob Lo on 9/30/18.
//

// Calculate the square root of a number.

#pragma once
#include <iostream>

// Using this equation:
// sqrt(n+1) = ( sqrt(n) + n/ sqrt(n) ) / 2
double sqrt(int n) {
  if ( n <= 0 ) return 0;

  double tmp;
  double sqaureRoot = (double)n / 2.0;
  do {
    tmp = sqaureRoot;
    std::cout << sqaureRoot << '\n';
    sqaureRoot = ( tmp + n / tmp ) / 2.0;
  }while ( (tmp - sqaureRoot) != 0 );

  return sqaureRoot;
}