/*
 * BaseTestRunner.h
 *
 *  Created on: Apr 23, 2014
 *      Author: josephx
 */

#ifndef BASETESTRUNNER_H_
#define BASETESTRUNNER_H_

#include "TestCase.h"
#include "TestSuite.h"
#include "Visitor.hpp"

namespace eut
{
class BaseTestRunner
    : public dp::BaseVisitor,
      public dp::Visitor<TestCase>,
      public dp::Visitor<TestSuite>
{
public:
    BaseTestRunner();
    virtual
    ~BaseTestRunner();
    virtual void
    Visit(TestCase&);
    virtual void
    Visit(TestSuite&);
};
} /* namespace eut */

#endif /* BASETESTRUNNER_H_ */
