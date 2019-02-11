//
// Created by Jacob Lo on Jan 24, 2019
//

#pragma once

#include <vector>

using namespace std;

namespace Knapsack {

  int/* max_value */ knapsack( const vector< pair<int /* weight */, int /* value */> >& bag, int maxWeightAllow ) {

    vector< vector<int> > holder ( bag.size() + 1, vector<int> ( maxWeightAllow + 1, 0) );

    for ( int i = 1 ; i < bag.size() + 1; i++ ) {

      for( int j = 0 ; j <= maxWeightAllow ; j++ ) {

        /// case 1: if exclude e[n], then optimal solution is sum of v[n-1], and weight is sum of w[n-1]
        int valueExclude = holder[i-1][j];
        /// case 2: if include e[n], then optimal solution is sum of v[n-1] + v[n], and weight is sum of w[n-1] + w[n]
        int valueInclude = 0;

        if ( j - bag[i-1].first >= 0 ) {
          valueInclude = holder[i-1][ j - bag[i-1].first] + bag[i-1].second;
        }
        holder[i][j] = max( valueExclude, valueInclude);

      }
    }

    return holder[ bag.size() ][ maxWeightAllow ];
  }
}