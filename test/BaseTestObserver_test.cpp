/*
 * BaseTestLogger_test.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: josephx
 */

#include "BaseTestObserver.h"
#include "TestCase.h"
#include <boost/test/unit_test.hpp>
#include "CaseOne.h"

namespace eut {
class ConsoleLogger : public BaseTestObserver {
 public:
  ConsoleLogger() {
    this->Register(TestStatus::STATUS::START, [&](TestCase const* const t) {
      std::cout << "START " << t->getFullname() << std::endl;
      BOOST_CHECK_EQUAL("abc", t->getName());
    });
  };
  virtual ~ConsoleLogger() {};
};
} /* namespace eut */

BOOST_AUTO_TEST_CASE(name) {
  CaseOne ac;
  ac.setName("abc");
  eut::ConsoleLogger logger;
  logger.Update(&ac);
  ac.setStatus(eut::TestStatus::START);
  logger.Update(&ac);
}
