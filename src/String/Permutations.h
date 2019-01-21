//
// Created by Jacob Lo on 2019-01-20.
//

#pragma once

#include <vector>

using namespace std;

namespace Permutations {

    vector< vector<int> > premuteRec( vector<int>& nums, const vector< vector<int> >& res, int pt ) {

        if ( pt >= nums.size() ) {
            return res;
        }
        vector< vector<int> > newRes;

        for ( int i = 0 ; i < res.size() ; i++ ) {

            for ( auto it = res[i].begin(); it != res[i].end() ; ++it) {

                vector<int> newTmp ( res[i].begin(), it);
                newTmp.push_back( nums[pt] );
                newTmp.insert( newTmp.end(), it, res[i].end() );
                newRes.push_back( newTmp );
            }

            // REMEMBER: [begin(), end() ), so need to do one last time
            vector<int> newTmp ( res[i].begin(), res[i].end());
            newTmp.push_back( nums[pt] );
            newRes.push_back( newTmp );
        }

        return premuteRec( nums, newRes, pt+1);
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> first { nums[0] };
        vector< vector<int> > res { first };
        return premuteRec( nums, res, 1);

    }

    void test() {
            vector<int> nums { 1, 2, 3, 4 };
            vector< vector<int> > result = permute(nums);

            for ( auto each : result ) {
                for (auto i : each ) {
                //    cout << i << " ";
                }
                //cout << endl;
            }
    };

}