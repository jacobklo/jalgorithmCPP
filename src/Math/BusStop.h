//
// Created by Jacob Lo on 9/28/18.
//


/*
 * MEDIUM
 * https://www.hackerrank.com/contests/101hack54/challenges/bus-stops
 *
 There are  bus stops on the street. You can imagine the street as a line with the coordinate system. The coordinates of the bus stops are , where  is the distance in meters from the  bus stop to the beginning of the street. The first bus stop is located at the beginning of the street and the last is located at the end of the street.

image

There is exactly one bus route. A bus goes from the beginning to the end of the street every  minutes with speed  meters per minute, starting at time . A bus stops at each stop. Stopping takes no time.

There are  people who want to reach the end of the street. The  person starts at point  at time  and has walking speed  meters per minute. For each person, you should find the minimum time when this person can reach the end of the street.

Complete the function minimumTimeToEnd that takes in the array  of coordinates of the bus stops and three integers ,  and  (the meanings of which are explained in the statement) and prints  real numbers, the  of which denotes the minimum time when the  person can reach the end of the street. The description of the people should be taken from the standard input as described in the input format section.

Input Format

The first line contains a single integer .

The second line contains  space-separated integers .

The third line contains two space-separated integers  and .

The fourth line contains a single integer .

The next  lines contain the description of people. The  of these lines contains three space-separated integers , , .

Constraints








Additionally, for 1/3 of the total points:


Output Format

Print  lines. The  line should contain the minimum time when the  person can reach the end of the street.

The output is considered correct if it has an absolute error of at most  from the answer.

Sample Input 0

4
0 10 40 100
20 10
3
0 0 4
15 10 1
40 2 16
Sample Output 0

10.0000000000
30.0000000000
5.7500000000
Explanation 0

The first person can take a bus at the first bus stop at time , so the final time will be .

The second person can go to bus stop number , wait and take a bus there at time , so the final time will be .

The third person can take no bus and just walk to the end of the street, so the final time will be .

image

Submissions: 532
Max Score: 45
Difficulty: Medium
Rate This Challenge:

More
 */

#pragma once

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<string> split_string(string);

double minTimeForAPersonToEnd( vector<long> busStops, long everyW, long busV, int point, int start, int walkSpeed ) {

  // find closet bus stop
  int pos = 0;
  long busStopDistance = LONG_MAX;
  for ( int i = 0 ; i < busStops.size(); i++ ) {
    long currentBusStopDistance = abs(point - busStops[i]);
    if ( currentBusStopDistance < busStopDistance)  {
      pos = i;
      busStopDistance = currentBusStopDistance;
    }
  }

  // calc time to walk to bus stop
  double timeWalkToBusStop = (double)busStopDistance / (double)walkSpeed;

  // calc total time that start and spend to walk
  double totalTimeWasted = timeWalkToBusStop + (double)start;

  // calc time that next available bus comes
  long busStopNeeded = busStops[pos];
  double timeNextBusArrive = (double)busStopNeeded / (double)busV;
  while ( timeNextBusArrive < totalTimeWasted) {
    timeNextBusArrive = timeNextBusArrive + (double)everyW;
  }
  // calc time spend to ride the bus
  double totalTimeRideBus = timeNextBusArrive + ((double)( busStops[ busStops.size() - 1] - busStopNeeded )) / (double)busV;

  // calc time just walk
  double justWalk = ((double)( busStops[ busStops.size() - 1] - point )) / (double)walkSpeed + start;

  // return min of both
  return ( totalTimeRideBus < justWalk ? totalTimeRideBus : justWalk);
}

void minimumTimeToEnd(vector<long> x, long w, long v, int q) {
  // Take the descriptions of the people from standard input and print the answers to standard output
  vector<long> points;
  vector<long> starts;
  vector<long> walks;

  string temp;
  for ( int i = 0 ; i < q ; i++ ) {
    getline(cin, temp);
    vector<string> personString = split_string(temp);
    points.push_back( stol(personString[0]) );
    starts.push_back( stol(personString[1]) );
    walks.push_back( stol(personString[2]) );
  }

  for ( int i = 0 ; i < q ; i++ ) {
    double result = minTimeForAPersonToEnd( x, w, v, points[i], starts[i], walks[i] );
    cout.precision(10);
    cout << fixed << result << endl;
  }
}

vector<string> split_string(string input_string) {
  string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
    return x == y and x == ' ';
  });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}

void BusStopMain2() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string x_temp_temp;
  getline(cin, x_temp_temp);

  vector<string> x_temp = split_string(x_temp_temp);

  vector<long> x(n);

  for (int x_itr = 0; x_itr < n; x_itr++) {
    long x_item = stol(x_temp[x_itr]);

    x[x_itr] = x_item;
  }

  string wv_temp;
  getline(cin, wv_temp);

  vector<string> wv = split_string(wv_temp);

  long w = stol(wv[0]);

  long v = stol(wv[1]);

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  minimumTimeToEnd(x, w, v, q);

}