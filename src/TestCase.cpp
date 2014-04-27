/*
 * TestCase.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: josephx
 */

#include "TestCase.h"

namespace eut {
TestCase::TestCase() {
  // TODO Auto-generated constructor stub
}
TestCase::~TestCase() {
  // TODO Auto-generated destructor stub
}
void TestCase::Accept(dp::BaseVisitor* guest) { AcceptImpl(this, guest); }
} /* namespace eut */
