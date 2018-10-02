//
// Created by Jacob Lo on 02/10/2018.
//

#include <vector>

#include "catch.hpp"
#include "String/ContainersToString.h"
#include "Sort/QuickSort.h"

using namespace std;

namespace QuickSort {
  TEST_CASE( "Test QuickSort ", "[TestQuickSort]") {
    vector<int> standardVector{ 1,2,3,4,5,6,7,8,9 };
    string standard = util::vectorToString(standardVector);

    // Since QuickSort is randomized algorithm, we need to test more with different pivot
    for ( int i = 0 ; i < standardVector.size() ; i++ ) {
      vector<int> arr{ 4,8,2,6,9,3,5,7,1};
      quickSort( arr, 0, arr.size()-1 );
      string result = util::vectorToString(arr);
      REQUIRE( standard.compare(result) == 0);
    }

  }
}

