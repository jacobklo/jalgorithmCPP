//
// Created by Jacob Lo on Jan 16, 2019
//

// EASY
// https://leetcode.com/problems/merge-two-sorted-lists/

#pragma once

#include <iostream>

using namespace std;

namespace MergeTwoLists {
  struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };

  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    ListNode * curL1 = l1;
    ListNode * tmp = nullptr;

    if ( l2 != nullptr && (curL1 == nullptr || curL1->val > l2->val) ) {
      tmp = curL1;
      curL1 = l2;
      l2 = l2->next;
      curL1->next = tmp;
    }
    l1 = curL1;
    // curl = 1 4 5 6
    // l2 = 2 3

    while( l2 != nullptr ) {

      while ( curL1->next != nullptr && curL1->next->val < l2->val ) {
        curL1 = curL1->next;
      }

      if ( curL1->next == nullptr || curL1->next->val >= l2->val ) {

        tmp = curL1->next;
        curL1->next = l2;
        l2 = l2->next;
        curL1->next->next = tmp;
        curL1 = curL1->next;

      }
    }

    return l1;
  }

  void print( ListNode* n ) {
    while ( n != nullptr ) {
      cout << n->val << " ";
      n = n->next;
    }
    cout <<endl;
  }

  void test () {
    ListNode * l3 = new ListNode(4);
    ListNode * r3 = new ListNode(4);
    ListNode * l2 = new ListNode(2);
    ListNode * r2 = new ListNode(3);
    l2->next = l3;
    r2->next = r3;
    ListNode * l1 = new ListNode(1);
    ListNode * r1 = new ListNode(0);
    l1->next = l2;
    r1->next = r2;

    print(l1);
    print(r1);

    l1 = mergeTwoLists(l1,r1);
    print(l1);

  }
}
