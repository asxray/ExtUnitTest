/*
 * TestCase.h
 *
 *  Created on: Apr 22, 2014
 *      Author: josephx
 */

#ifndef TESTCASE_H_
#define TESTCASE_H_

#include "Cloneable.hpp"
#include "Composite.hpp"
#include "TestBody.h"
#include "TestResource.h"
#include "TestResult.h"
#include "TestStatus.h"

namespace eut {
class TestCase : public TestBody,
                 public TestResource,
                 public TestStatus,
                 public TestResult,
                 public dp::Cloneable,
                 public dp::Component {
 public:
  enum ATTRIBUTE {
    DEFAULT = 0b00,
    SINGLETHREAD = 0b01,
    WAIVED = 0b10
  };
  TestCase();
  virtual ~TestCase();
  virtual void Accept(dp::BaseVisitor *const guest);

  void setAttr(const ATTRIBUTE aAttr);
  ATTRIBUTE getAttr() const;

 private:
  ATTRIBUTE mAttr;
};
} /* namespace eut */

#endif /* TESTCASE_H_ */
