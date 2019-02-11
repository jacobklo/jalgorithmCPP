//
// Created by Jacob Lo on 2019-01-20.
//

// MEDIUM
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// link each row of a full binary tree from left to right

/*
 *  1
   /  \
  2    3
 / \  / \
4  5  6  7
 */

#pragma once

#include <queue>

using namespace std;

namespace PopulatingNextRightPointersInEachNode {
    struct TreeLinkNode {
        TreeLinkNode *left = nullptr;
        TreeLinkNode *right = nullptr;
        TreeLinkNode *next = nullptr;
        int val;

        TreeLinkNode ( int x) : val(x){}
    };

    void convertToVector ( queue< TreeLinkNode* > holder ) {

        if ( holder.empty() ) return;

        TreeLinkNode *tmp = nullptr;
        queue< TreeLinkNode* > nextHolder;

        while ( !holder.empty() ) {
            TreeLinkNode* n = holder.front();
            holder.pop();

            if ( n->left ) {
                nextHolder.push( n->left );
                if ( tmp ) {
                    tmp->next = n->left;
                }
            }

            tmp = n->left;

            if ( n->right ) {
                nextHolder.push(n->right);
                if ( tmp ) {
                    tmp->next = n->right;
                }
            }

            tmp = n->right;
        }

        convertToVector( nextHolder );
    }

    void connect(TreeLinkNode *root) {
        queue< TreeLinkNode* > holder;
        holder.push(root);

        convertToVector( holder );

    }

    void test() {
        TreeLinkNode n4 (4), n5 (5), n6 (6), n7 (7);
        TreeLinkNode n2 (2), n3 (3);
        n2.left = &n4;
        n2.right = &n5;
        n3.left = &n6;
        n3.right = &n7;
        TreeLinkNode n1 (1);
        n1.left = &n2;
        n1.right = &n3;

        connect( &n1 );
    }

}