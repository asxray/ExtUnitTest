/*
 * TestResult.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: josephx
 */

#include "TestResult.h"
#include <ostream>

namespace eut
{
std::map<TestResult::RET, std::string>
TestResult::ret2Str;

TestResult::TestResult()
    : ret(RET::WAIVED)
{
    if (ret2Str.empty())
    {
        ret2Str[TestResult::RET::PASSED] = "PASSED";
        ret2Str[TestResult::RET::FAILED] = "FAILED";
        ret2Str[TestResult::RET::ERROR]  = "ERROR";
        ret2Str[TestResult::RET::WAIVED] = "WAIVED";
    }
}

TestResult::~TestResult()
{}

std::ostream&
operator << (
    std::ostream& ostr,
    TestResult&   res
    )
{
    ostr
    << TestResult::ret2Str.at(res.ret) << std::endl
    << res.errorlog;
    return(ostr);
}

TestResult&
operator << (
    TestResult& r,
    std::string str
    )
{
    r.errorlog += str;
    return(r);
}

TestResult::RET
TestResult::getRet() const
{
    return(ret);
}

void
TestResult::setRet(RET result)
{
    this->ret = result;
}

const std::string&
TestResult::getLog() const
{
    return(errorlog);
}
const std::string&
TestResult::getRetStr() const
{
    return(ret2Str.at(this->ret));
}

const double&
TestResult::getTimer(const std::string& s) const
{
    return(timer.at(s));
}

void
TestResult::setTimer(
    const std::string& s,
    const double&      n
    )
{
    this->timer[s] = n;
}
} /* namespace eut */
