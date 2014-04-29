/*
 * TestCase.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: josephx
 */

#include "TestCase.h"

namespace eut {
TestCase::TestCase() : mAttr(TestCase::ATTRIBUTE::DEFAULT) {}
TestCase::~TestCase() {}
void TestCase::Accept(dp::BaseVisitor* guest) { AcceptImpl(this, guest); }
void TestCase::setAttr(const eut::TestCase::ATTRIBUTE aAttr) {
  this->mAttr = aAttr;
}
TestCase::ATTRIBUTE TestCase::getAttr() const { return this->mAttr; }

} /* namespace eut */
