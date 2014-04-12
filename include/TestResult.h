/*
 * TestResult.h
 *
 *  Created on: Apr 13, 2014
 *      Author: josephx
 */

#ifndef TESTRESULT_H_
#define TESTRESULT_H_

#include <ostream>

namespace eutest
{
class TestResult
{
public:
    TestResult();
    virtual
    ~TestResult();
public:
    friend std::ostream&
    operator << (
        std::ostream& oStr,
        TestResult&
        );
protected:
    virtual
    void
    ToString() = 0;
};
} /* namespace eutest */

#endif /* TESTRESULT_H_ */
