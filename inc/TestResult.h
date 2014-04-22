/*
 * TestResult.h
 *
 *  Created on: Apr 21, 2014
 *      Author: josephx
 */

#ifndef TESTRESULT_H_
#define TESTRESULT_H_

#include <ostream>
#include <string>

namespace eut
{
class TestResult
{
public:
    TestResult();
    virtual
    ~TestResult();
    bool
    isPassed() const;
    void
    setPassed(bool passed);
    virtual
    const std::string&
    ToString();
    friend std::ostream&
    operator << (
        std::ostream&,
        TestResult&
        );
    friend TestResult&
    operator << (
        TestResult&,
        std::string
        );
protected:
    bool        passed;
    std::string outlog;
    std::string errorlog;
};
} /* namespace eut */

#endif /* TESTRESULT_H_ */
