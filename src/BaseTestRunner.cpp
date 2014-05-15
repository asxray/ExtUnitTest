/*
 * BaseTestRunner.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: josephx
 */

#include "BaseTestRunner.h"
//
#include "TestException.h"
#include <assert.h>

namespace eut {
BaseTestRunner::BaseTestRunner() {}
BaseTestRunner::~BaseTestRunner() {}
void BaseTestRunner::Notify() const {}
void BaseTestRunner::Visit(TestCase* const t) {
  assert(t);
  return (VisitImpl(t));
}
void BaseTestRunner::VisitImpl(TestCase* const t) {
  assert(t);
  bool hasSetUp = false;
  t->setStatus(TestStatus::START);
  NotifyImpl(t);
  try {
    t->setStatus(TestStatus::SETUP);
    NotifyImpl(t);
    t->SetUp();
    hasSetUp = true;
  }
  catch (TestException& e) {
    t->setRet(TestResult::RET::ERROR);
    t->setErrorLog(boost::diagnostic_information(e));
  }
  if (hasSetUp) try {
      t->setStatus(TestStatus::RUNNING);
      NotifyImpl(t);
      t->Run();
      t->setRet(TestResult::RET::PASSED);
    }
  catch (TestException& e) {
    t->setRet(TestResult::RET::FAILED);
    t->setErrorLog(boost::diagnostic_information(e));
  }
  try {
    t->TearDown();
    t->setStatus(TestStatus::TEARDOWN);
    NotifyImpl(t);
  }
  catch (TestException& e) {
    t->setRet(TestResult::RET::ERROR);
    t->setErrorLog(boost::diagnostic_information(e));
  }
  t->setStatus(TestStatus::END);
  NotifyImpl(t);
}
void BaseTestRunner::Visit(TestSuite* const) {}
void BaseTestRunner::Wait() {};
} /* namespace eut */
