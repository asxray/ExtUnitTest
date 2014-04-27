/*
 * TestBody_test.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: josephx
 */

#include "TestBody.h"
#include <boost/test/unit_test.hpp>

class Body : public eut::TestBody {
 public:
  int n;
  Body() : n(0) {}
  virtual ~Body() {}
  virtual void Run() { n = 1; }
};

BOOST_AUTO_TEST_CASE(testbody) {
  std::shared_ptr<Body> pBody(new Body);
  BOOST_CHECK_EQUAL(0, pBody->n);
  auto p = dynamic_cast<eut::TestBody*>(pBody.get());
  BOOST_REQUIRE(p);
  p->Run();
  BOOST_CHECK_EQUAL(1, pBody->n);
}
