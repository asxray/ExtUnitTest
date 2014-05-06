/*
 * RootTestSuite_test.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: josephx
 */

#include "RootTestSuite.h"
#include <boost/test/unit_test.hpp>

namespace eut {} /* namespace eut */

BOOST_AUTO_TEST_CASE(name) {
  BOOST_CHECK_EQUAL(eut::RootTestSuite::Instance()->getName(), "Root");
  BOOST_CHECK_EQUAL(eut::RootTestSuite::Instance()->getParent(),
                    static_cast<const dp::Component*>(0));
}
