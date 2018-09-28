//
// Created by Jacob Lo on 28/09/2018.
//

#include "Backtrack/MostEleganceString.h"

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