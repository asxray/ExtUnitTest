/*
 * BaseTestLogger.h
 *
 *  Created on: Apr 25, 2014
 *      Author: josephx
 */

#ifndef BASETESTLOGGER_H_
#define BASETESTLOGGER_H_

#include "Observer.hpp"
#include "TestCase.h"
#include <functional>
#include <map>
namespace eut {
class BaseTestObserver : public dp::Observer<TestCase> {
 public:
  BaseTestObserver();
  virtual ~BaseTestObserver();
  virtual void Update(TestCase const* const);

 protected:
  std::map<TestStatus::STATUS, std::function<void(TestCase const* const)> >
      funcMap;
};
} /* namespace eut */

#endif /* BASETESTLOGGER_H_ */
