/*
 * Cloneable_test.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: josephx
 */

#include "Cloneable.hpp"
#include <boost/test/unit_test.hpp>
#include <iostream>

class A : public dp::Cloneable {
 public:
  virtual int num() { return (1); }
  virtual ~A() {}
  CLONE(A);
};

class B : public A {
 public:
  virtual int num() { return (2); }
  virtual ~B() {}
  CLONE(B);
};

BOOST_AUTO_TEST_CASE(clonetest) {
  B b;
  A* bb = b.clone();
  BOOST_CHECK_EQUAL(2, bb->num());
  delete bb;
}
