
/**
 * MEDIUM
 * https://www.hackerrank.com/contests/hourrank-28/challenges/the-most-elegant-sequence
 * The Most Elegant Sequence
 *
 * In this problem, every string has a beauty value which is represented as a positive integer.

The elegance of a sequence of strings  is defined as

where  denotes the beauty of string , and  represents the bitwise XOR operation. In particular, the elegance of a sequence of just one string is just the beauty value of that string. Also, the elegance of an empty sequence is .
Diane has  strings , each consisting of the digits  to , and  has beauty value . She would like to form the most elegant sequence of strings among them. She can write any string with her digit cards; for every digit  from  to , she has exactly  cards in which the digit  is written, so she has  cards in total. For example, 1 digit card each for every number  to  would be,

image

Furthermore:

She may write the strings in any order, but she can only form each string at most once.
To write a string, she has to use the cards. But each card can only be used once, so it may not be possible to write all strings.
Given the above restrictions, what is the maximum elegance of any sequence that Diane can form?

Complete the function maximumElegance which takes in an integer , an array  consisting of  strings, and an array  consisting of  integers denoting their respective beauty values and returns the maximum elegance of any sequence that Diane can form.

Input Format

The first line contains two space-separated integers  and .

The second line contains  space-separated integers  denoting the beauty values of the strings.

The  of the next  lines contains the  string, .

Constraints

 is a string of digits -.
Subtask

For ~20% of the total score,
Output Format

Print a single integer denoting the maximum elegance which can be obtained by Diane.

Sample Input 0

3 2
2 3 1
1032
2467
48957
Sample Output 0

8
Explanation 0

Note that , which means we have two cards for each digit, and so we can write all three strings.

image

If we write all three strings in the order , then we get an elegance of , which is the maximum possible.

Submissions: 417
Max Score: 50
Difficulty: Medium
Rate This Challenge:



 */
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
