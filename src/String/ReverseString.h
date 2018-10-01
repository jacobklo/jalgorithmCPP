//
// Created by Jacob Lo on 9/30/18.
//

// Problem : Given a const null terminated string containing a sentence
// , can you print out the words of the sentence in reverse without changing any data
// and without creating a temporary string buffer?
// Do not use any helper functions, write it all out on your own.
// (ie "The dog is fast" becomes "fast is dog The")

#pragma once

#include <iostream>

using namespace std;

namespace ReverseString {
  void printReverseString(const char *s) {
    if ((*s) == '\0') return;
    printReverseString(s + sizeof(char));
    cout << (*s);
  }
}
