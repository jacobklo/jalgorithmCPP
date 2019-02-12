//
// Created by Jacob Lo on Feb 11, 2019
//

// MEDIUM
// Implement a trie with insert, search, and startsWith methods.
// https://leetcode.com/problems/implement-trie-prefix-tree/

#pragma once

#include <array>
#include <iostream>

using namespace std;

namespace ImplementTrie {
    class Node {
    public:

        void add(string s) {
            if (s.length() <= 0) return;

            if (children[s[0] - 'a'] == nullptr) {
                children[s[0] - 'a'] = new Node();
            }
            if (s.length() == 1) {
                children[s[0] - 'a']->active = true;
                return;
            }
            children[s[0] - 'a']->add(s.substr(1));
        }

        // REMEMBER : Always initialize a value, however you can do this in Node constructor
        array<Node *, 26> children {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                                    nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                                    nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};
        bool active = false;
    };

    class Trie {
    public:

        /** Initialize your data structure here. */
        Trie() {

        }

        /** Inserts a word into the trie. */
        void insert(string word) {
            root.add(word);
        }

        bool search(string word, Node *n) {
            if (word.length() == 1) {
                return n->children[word[0] - 'a'] != nullptr && n->children[word[0] - 'a']->active;
            }
            // REMEMBER : substr is creating new objects!! for every recursion, not good!!
            return n->children[word[0] - 'a'] != nullptr && search(word.substr(1), n->children[word[0] - 'a']);
        }

        /** Returns if the word is in the trie. */
        bool search(string word) {
            return search(word, &root);
        }

        bool startsWith(string prefix, Node *n) {
            if (prefix.length() == 1) {
                return n->children[prefix[0] - 'a'] != nullptr;
            }
            // REMEMBER : substr is creating new objects!! for every recursion, not good!!
            return n->children[prefix[0] - 'a'] != nullptr && startsWith(prefix.substr(1), n->children[prefix[0] - 'a']);
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix) {
            return startsWith(prefix, &root);
        }

        Node root;
    };

    void test() {

        Trie trie;

        trie.insert("apple");
        cout << trie.search("apple") << endl;  // returns true
        cout << trie.search("app") << endl;     // returns false
        cout << trie.startsWith("app") << endl; // returns true
        trie.insert("app");
        cout << trie.search("app") << endl;     // returns true
    }
}