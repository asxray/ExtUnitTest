/*
 * TestResult.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: josephx
 */

#include "TestResult.h"

namespace eutest
{
TestResult::TestResult()
{
    // TODO Auto-generated constructor stub
}

TestResult::~TestResult()
{
    // TODO Auto-generated destructor stub
}

std::ostream&
operator << (
    std::ostream& oStr,
    TestResult&   aResult
    )
{
    oStr << aResult.ToString();
    return(oStr);
}
} /* namespace eutest */
