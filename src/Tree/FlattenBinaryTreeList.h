//
// Created by Jacob Lo on Jan 18, 2019
//

// MEDIUM
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Given a binary tree, flatten it to a linked list in-place.
//
//For example, given the following tree:
//
//    1
//   / \
//  2   5
// / \   \
//3   4   6
//The flattened tree should look like:
//
//1
// \
//  2
//   \
//    3
//     \
//      4
//       \
//        5
//         \
//          6

#pragma once


namespace FlattenBinaryTreeList {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    TreeNode *flattenRec(TreeNode *n) {

        if (!n) return nullptr;

        TreeNode *listedRight = flattenRec(n->right);

        /// if no child, or only right child
        if (!n->left) {
            n->right = listedRight;
            return n;
        }

        TreeNode *listedLeft = flattenRec(n->left);

        TreeNode *lastOfRightNodeInListedLeft = listedLeft;
        while (lastOfRightNodeInListedLeft->right != nullptr) {
            lastOfRightNodeInListedLeft = lastOfRightNodeInListedLeft->right;
        }

        n->left = nullptr;
        n->right = listedLeft;
        lastOfRightNodeInListedLeft->right = listedRight;

        return n;
    }

    void flatten(TreeNode *root) {

        flattenRec(root);
    }

}