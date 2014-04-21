/*
 * TestResult.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: josephx
 */

#include "TestResult.h"
#include <sstream>

namespace eut
{
TestResult::TestResult()
    : passed(false)
{
    // TODO Auto-generated constructor stub
}

TestResult::~TestResult()
{
    // TODO Auto-generated destructor stub
}

const std::string&
TestResult::ToString()
{
    std::ostringstream outstr;
    outstr << (passed ? "PASSED" : "FAILED") << std::endl
           << errorlog;
    outlog = outstr.str();
    return(outlog);
}

std::ostream&
operator << (
    std::ostream& ostr,
    TestResult&   res
    )
{
    ostr << res.ToString();
    return(ostr);
}

TestResult&
operator << (
    TestResult& testresult,
    std::string str
    )
{
    testresult.errorlog += str;
    return(testresult);
}

bool
TestResult::isPassed() const
{
    return(passed);
}

void
TestResult::setPassed(bool passed)
{
    this->passed = passed;
}
} /* namespace eut */
