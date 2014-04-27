/*
 * BaseTestRunner.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: josephx
 */

#include "BaseTestRunner.h"
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
  try {
    t->setStatus(TestStatus::START);
    NotifyImpl(t);
    try {
      t->SetUp();
      t->setStatus(TestStatus::SETUP);
      NotifyImpl(t);
    }
    catch (...) {
      t->setRet(TestResult::RET::ERROR);
      throw;
    }
    try {
      t->setStatus(TestStatus::RUNNING);
      NotifyImpl(t);
      t->Run();
      t->setRet(TestResult::RET::PASSED);
    }
    catch (...) {
      t->setRet(TestResult::RET::FAILED);
      throw;
    }
    try {
      t->TearDown();
      t->setStatus(TestStatus::TEARDOWN);
      NotifyImpl(t);
    }
    catch (...) {
      throw;
    }
  }
  catch (...) {
  }
  t->setStatus(TestStatus::END);
  NotifyImpl(t);
}

void BaseTestRunner::Visit(TestSuite* const t) { assert(t); }
} /* namespace eut */
