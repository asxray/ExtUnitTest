/*
 * BaseTestRunner.h
 *
 *  Created on: Apr 23, 2014
 *      Author: josephx
 */

#ifndef BASETESTRUNNER_H_
#define BASETESTRUNNER_H_

#include "Observer.hpp"
#include "TestCase.h"
#include "TestSuite.h"
#include "Visitor.hpp"

namespace eut {
class BaseTestRunner : public dp::Visitor<TestCase>,
                       public dp::Visitor<TestSuite>,
                       public dp::Subject {
 public:
  BaseTestRunner();
  virtual ~BaseTestRunner();
  virtual void Visit(TestCase* const);
  virtual void Visit(TestSuite* const);
  virtual void PostVisit(TestCase* const);
  virtual void PostVisit(TestSuite* const);

 protected:
  virtual void Notify() const;
  virtual void VisitImpl(TestCase* const);
};
} /* namespace eut */

#endif /* BASETESTRUNNER_H_ */
