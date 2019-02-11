//
// Created by Jacob Lo on Jan 16, 2019
//

// EASY
// https://leetcode.com/problems/k-closest-points-to-origin/

#pragma once

#include <vector>
#include <queue>

#include <cmath>
#include <iostream>

using namespace std;

namespace KClosest {
    struct PointsComp {
        bool operator() (const vector<int>& lhs, const vector<int>& rhs ) {
            return ( pow( lhs[0], 2) + pow( lhs[1], 2) ) > ( pow( rhs[0], 2) + pow( rhs[1], 2) );
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

        priority_queue< vector<int>, vector < vector<int> >, PointsComp> pq ( points.begin(), points.end() );
        points.clear();

        for ( int i = 0 ; i < K ; i++ ) {
            points.push_back( pq.top() );
            pq.pop();
        }

        return points;
    }

    void test() {
        vector< vector<int> > pss {{68,97},{34,-84},{60,100},{2,31},{-27,-38},{-73,-74},{-55,-39},{62,91},{62,92},{-57,-67}};

        vector<int> p1 { 3,3 };
        vector<int> p2 { 50,-10 };
        vector<int> p3 { -200,400 };
        vector<int> p4 { 1,3 };
        vector<int> p5 { -2,2 };

        vector< vector<int> > points { p3, p2, p1 };

        auto result = kClosest( pss, 5 );
    }
}