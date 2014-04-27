/*
 * TestSuite.h
 *
 *  Created on: Apr 22, 2014
 *      Author: josephx
 */

#ifndef TESTSUITE_H_
#define TESTSUITE_H_

#include "Composite.hpp"

namespace eut {
class TestSuite : public dp::Composite {
 public:
  TestSuite();
  virtual ~TestSuite();
  virtual void Accept(dp::BaseVisitor* guest);
};
} /* namespace eut */

#endif /* TESTSUITE_H_ */
