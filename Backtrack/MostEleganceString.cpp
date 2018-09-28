#include <iostream>
#include <vector>

using namespace std;

// 1) calc Elegance:
//      1.1) First one take whole beauty
//      1.2) After take take beauty[lastPos] ^ beauty[thisPos]
// 2) cards: the digits 0-9 has finite number, digits is keeping track
// 3) strings: they can different order

// using backtracking algorithm, for recursive call we take out 1 string and compute the rest. O( 2 ^ n )
int maxEleganceRec( vector<string> s, vector<int> b, vector<int> & digits
        , vector<bool> & visited, int lastPos, int pos, int currentElegance) {

    if ( visited[pos] ) return currentElegance;
    visited[pos] = true;

    bool excludeThisString = false;
    // check has enough digits
    for ( char c : s[pos]) {
        int currentDigit = (c-48);
        // exclude this card
        if ( digits[ currentDigit ] < 1) {
            excludeThisString = true;
            break;
        }
    }

    if ( !excludeThisString ) {
        // update digits for minusing this string
        for ( char c : s[pos]) {
            int currentDigit = (c-48);
            digits[ currentDigit ]--;
        }

        // update current elegance
        if ( lastPos == -1 ) {
            currentElegance += b[pos];
            lastPos = -2; // it is just a condition identify that we used the first position
        }
        else {
            currentElegance += b[lastPos] ^ b[pos];
        }
    }

    // recursively call for next card
    int subResult = 0;
    for ( int i = 0 ; i < s.size() ; i++ ) {
        int currentResult = maxEleganceRec(s, b, digits, visited, ( lastPos == -1 ? -1 : pos ), i, currentElegance);
        if ( subResult < currentResult) {
            subResult = currentResult;
        }
    }

    // update visited and digits
    visited[pos] = false;
    if ( !excludeThisString ) {
        for ( char c : s[pos]) {
            int currentDigit = (c-48);
            digits[ currentDigit ]++;
        }
    }

    return subResult;
}
int maximumElegance(int q, vector<string> s, vector<int> b) {
    vector<int> digits;
    for (int i = 0; i < 10; i++) {
        digits.push_back(q);
    }
    vector<bool> visited;
    for (int i = 0; i < s.size(); i++) {
        visited.push_back(false);
    }

    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        int currentResult = maxEleganceRec(s, b, digits, visited, -1, i, 0);
        if (result < currentResult) {
            result = currentResult;
        }
    }
    return result;
}

int main() {
    vector<string> s;
    s.push_back("1032");
    s.push_back("2467");
    s.push_back("48957");

    vector<int> b;
    b.push_back(2);
    b.push_back(3);
    b.push_back(1);

    int result = maximumElegance( 2, s, b);
    cout << result << endl;
    return 0;
}

//vector< vector<int>> possibleSet( vector< vector<int>> sets, int n ) {
//    if ( n <= 0 ) return sets;
//
//    vector< vector<int>> newSets;
//
//    for ( int k = 0 ; k <= sets[0].size() ; k++ ) {
//        for ( int i = 0 ; i < sets.size() ; i++ ) {
//
//            vector<int> currentSet;
//
//            for ( int j = 0 ; j < k ; j++ ) {
//                currentSet.push_back( sets[i][j] );
//            }
//            currentSet.push_back(n);
//            for ( int j = k; j < sets[i].size() ; j++ ) {
//                currentSet.push_back( sets[i][j] );
//            }
//            newSets.push_back( currentSet );
//        }
//    }
//
//    return possibleSet( newSets, n-1);
//}
