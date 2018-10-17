//
// Created by Jacob Lo on 10/11/18.
//

/*
 * MEDIUM
 * Fraudulent Activity Notifications
 * https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting
 *
 * Problem: send a notice if a transactions amount is larger than median in range of d transactions before
 * More at the end
 */
#pragma once

#include <vector>
#include <set>
#include <functional>

using namespace std;

namespace FraudulentActivityNotifications {

  // TODO
  int activityNotifications(vector<int> expenditure, int d) {

    int notices;
    multiset<int> dmap;
    /// loop through expenditure, update BST to max d num of elements, find if i is bigger than median
    for ( int i = 0 ; i < expenditure.size() ; i++ ){

      /// check if BST has enough elements. if num of elements smaller than d, append and continue
      if ( dmap.size() < d ) {
        dmap.insert( expenditure[i] );
        continue;
      }

      /// check if median is smaller than i expends, if so, add notice
      multiset<int>::iterator it = dmap.begin();
      // find median node
      for ( int j = 0 ; j < dmap.size() / 2 ; j++, ++it ) {}

      // check median < i expends
      if ( (*it) < expenditure[i] ) {
        notices++;
      }

      /// update BST
      dmap.erase( dmap.begin() );
      dmap.insert( expenditure[i] );
    }

    return notices;
  }


  class MedianHeap {
    priority_queue<int, vector<int>, greater<int> > greatEles; // elements greater than median store in min heap
    priority_queue<int> lessEles; // elements less than median store in max heap

  public:
    void push(int n) {
      double currentMedian = 0;
      if (size() % 2 == 0 ) {
        currentMedian = (double)(( greatEles.top() + lessEles.top() ) / 2);
      }
      else {
        if ( greatEles.size() > lessEles.size()) {
          currentMedian = greatEles.top();
        }
        else {
          currentMedian = lessEles.top();
        }
      }

      if ( n > currentMedian ) {
        greatEles.push(n);
      }
      else {
        lessEles.push(n);
      }

      balance();
    }

    void balance() {
      while ( greatEles.size() - lessEles.size() > 2 ) {
        int n = greatEles.top();
        lessEles.push( n );
        greatEles.pop();
      }
      while( greatEles.size() - lessEles.size() < -2 ) {
        int n = lessEles.top();
        greatEles.push( n );
        lessEles.pop();
      }
    }

    void  {

    }

    unsigned long size() {
      return greatEles.size() + lessEles.size();
    }
  };

}

/*
 * HackerLand National Bank has a simple policy for warning clients about possible fraudulent account activity. If the amount spent by a client on a particular day is greater than or equal to  the client's median spending for a trailing number of days, they send the client a notification about potential fraud. The bank doesn't send the client any notifications until they have at least that trailing number of prior days' transaction data.
Given the number of trailing days  and a client's total daily expenditures for a period of  days, find and print the number of times the client will receive a notification over all  days.
For example,  and . On the first three days, they just collect spending data. At day , we have trailing expenditures of . The median is  and the day's expenditure is . Because , there will be a notice. The next day, our trailing expenditures are  and the expenditures are . This is less than  so no notice will be sent. Over the period, there was one notice sent.
Note: The median of a list of numbers can be found by arranging all the numbers from smallest to greatest. If there is an odd number of numbers, the middle one is picked. If there is an even number of numbers, median is then defined to be the average of the two middle values. (Wikipedia)
Function Description
Complete the function activityNotifications in the editor below. It must return an integer representing the number of client notifications.
activityNotifications has the following parameter(s):
expenditure: an array of integers representing daily expenditures
d: an integer, the lookback days for median spending
Input Format
The first line contains two space-separated integers  and , the number of days of transaction data, and the number of trailing days' data used to calculate median spending.
The second line contains  space-separated non-negative integers where each integer  denotes .
Constraints



Output Format
Print an integer denoting the total number of times the client receives a notification over a period of  days.
Sample Input 0
9 5
2 3 4 2 3 6 8 4 5
Sample Output 0
2
Explanation 0
We must determine the total number of  the client receives over a period of  days. For the first five days, the customer receives no notifications because the bank has insufficient transaction data: .
On the sixth day, the bank has  days of prior transaction data, , and  dollars. The client spends  dollars, which triggers a notification because : .
On the seventh day, the bank has  days of prior transaction data, , and  dollars. The client spends  dollars, which triggers a notification because :  .
On the eighth day, the bank has  days of prior transaction data, , and  dollars. The client spends  dollars, which does not trigger a notification because : .
On the ninth day, the bank has  days of prior transaction data, , and a transaction median of  dollars. The client spends  dollars, which does not trigger a notification because : .
Sample Input 1
5 4
1 2 3 4 4
Sample Output 1
0
There are  days of data required so the first day a notice might go out is day . Our trailing expenditures are  with a median of  The client spends  which is less than  so no notification is sent.
 */
