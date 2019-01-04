//
// Created by lok1 on 04/01/2019.
//

#pragma once

#include <iostream>

using namespace std;

void checkPointers() {
  int a = 10;
  int *b = &a;
  int c = *b;
  int *d = b;
  int &e = *b;

  cout << a << " " << b << " " << c << " " << d << " " << e << "  " << *b << " " << *d << endl;
  a = 20;
  cout << a << " " << b << " " << c << " " << d << " " << e << "  " << *b << " " << *d << endl;
  cout << endl;

  int arr[10];
  for ( int i = 0 ; i < 10 ; i++ ) {
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << endl;

  int arr2[10] = { 0 };
  for ( int i = 0 ; i < 10 ; i++ ) {
    cout << arr2[i] << " ";
  }
  cout << endl;
  cout << endl;


  int *arr3[5] = { b, b, b, b, b };
  for ( int i = 0 ; i < 5 ; i++ ) {
    cout << arr3[i] << " ";
  }
  cout << endl;
  for ( int i = 0 ; i < 5 ; i++ ) {
    cout << *arr3[i] << " ";
  }
  cout << endl;
  cout << endl;

  int * arr5 = arr2;
  for ( int i = 0 ; i < 5 ; i++ ) {
    cout << arr5[i] << " ";
  }
  cout << endl;
  for ( int i = 0 ; i < 5 ; i++ ) {
    cout << *(arr5 + i) << " ";
  }
  cout << endl;

//  int (*x)[10];
//  for ( int i = 0 ; i < 10 ; i++ ) {
//    cout << x[i] << endl;
//  }
}