/*
 * BaseTestRunner.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: josephx
 */

#include "BaseTestRunner.h"

namespace eut
{
BaseTestRunner::BaseTestRunner()
{}

BaseTestRunner::~BaseTestRunner()
{}
void
BaseTestRunner::Visit(TestCase& t)
{
    t.setStatus(TestStatus::START);
    try
    {
        t.SetUp();
        t.setStatus(TestStatus::SETUP);
    }
    catch (...)
    {
        t.setRet(TestResult::RET::ERROR);
    }
    try
    {
        t.setStatus(TestStatus::RUNNING);
        t.Run();
        t.setRet(TestResult::RET::PASSED);
    }
    catch (...)
    {
        t.setRet(TestResult::RET::FAILED);
    }
    try
    {
        t.TearDown();
        t.setStatus(TestStatus::TEARDOWN);
    }
    catch (...)
    {}

    t.setStatus(TestStatus::END);
}
void
BaseTestRunner::Visit(TestSuite& t)
{}
} /* namespace eut */
