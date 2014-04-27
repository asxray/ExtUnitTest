/*
 * BaseTestLogger.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: josephx
 */

#include "BaseTestObserver.h"

namespace eut {
BaseTestObserver::BaseTestObserver() {}

BaseTestObserver::~BaseTestObserver() {}

void BaseTestObserver::Update(TestCase const* const aCase) {
  assert(aCase);
  if (funcMap.count(aCase->getStatus())) funcMap.at(aCase->getStatus())(aCase);
}
} /* namespace eut */
