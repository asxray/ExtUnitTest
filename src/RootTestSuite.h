/*
 * RootTestSuite.h
 *
 *  Created on: Apr 23, 2014
 *      Author: josephx
 */

#ifndef ROOTTESTSUITE_H_
#define ROOTTESTSUITE_H_

#include "Singleton.hpp"
#include "TestSuite.h"

namespace eut
{
class RootTestSuite
    : public dp::Singleton<RootTestSuite>,
      public TestSuite
{
    SINGLETON(RootTestSuite);
};
} /* namespace eut */

#endif /* ROOTTESTSUITE_H_ */
