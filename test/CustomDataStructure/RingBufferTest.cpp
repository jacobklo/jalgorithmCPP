//
// Created by Jacob Lo on Jan 23, 2019
//

#include "catch.hpp"
#include "CustomDataStructure/RingBuffer.h"

TEST_CASE("Test Add extra", "[TestAddExtra]") {
  RingBuffer::RingBuffer<4> rb;
  for ( int i = 1 ; i <= 6 ; i++ ) {
    rb.produce(i);
  }
  REQUIRE( rb.toString().compare("Container : { 5, 6, 3, 4, } oldestPt : 2 , newestPt : 1 , numOfElement : 4") == 0);
}

TEST_CASE("Test remove 2 element", "[TestRemove2Element]") {
  RingBuffer::RingBuffer<4> rb;
  for ( int i = 1 ; i <= 4 ; i++ ) {
    rb.produce(i);
  }

  for ( int i = 0 ; i < 2 ; i++ ) {
    rb.consume();
  }
  REQUIRE( rb.toString().compare("Container : { 1, 2, 3, 4, } oldestPt : 2 , newestPt : 0 , numOfElement : 2") == 0);
}

TEST_CASE("Test Remove extra", "[TestRemoveExtra]") {
  RingBuffer::RingBuffer<4> rb;
  for ( int i = 1 ; i <= 4 ; i++ ) {
    rb.produce(i);
  }

  for ( int i = 0 ; i < 5 ; i++ ) {
    rb.consume();
  }
  REQUIRE( rb.toString().compare("Container : { 1, 2, 3, 4, } oldestPt : 0 , newestPt : 0 , numOfElement : 0") == 0);
}

TEST_CASE("Test Add and Remove extra", "[TestAddRemoveExtra]") {
  RingBuffer::RingBuffer<4> rb;
  for ( int i = 1 ; i <= 4 ; i++ ) {
    rb.produce(i);
  }

  for ( int i = 0 ; i < 2 ; i++ ) {
    rb.consume();
  }

  rb.produce(10);
  rb.produce(20);
  rb.produce(30);
  rb.produce(40);
  rb.produce(50);

  REQUIRE( rb.toString().compare("Container : { 50, 20, 30, 40, } oldestPt : 1 , newestPt : 0 , numOfElement : 4") == 0);
}