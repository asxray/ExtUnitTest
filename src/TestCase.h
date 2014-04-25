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
#include  "TestResult.h"
#include "TestStatus.h"

namespace eut
{
class TestCase
    : public TestBody,
      public TestResource,
      public TestStatus,
      public TestResult,
      public dp::Cloneable,
      public dp::Component
{
public:
    TestCase();
    virtual
    ~TestCase();
    virtual void
    Accept(dp::BaseVisitor* guest);
};
} /* namespace eut */

#endif /* TESTCASE_H_ */
