/*
 * TestResult.h
 *
 *  Created on: Apr 21, 2014
 *      Author: josephx
 */

#ifndef TESTRESULT_H_
#define TESTRESULT_H_

#include <map>
#include <ostream>
#include <string>

namespace eut
{
class TestResult
{
public:
    enum RET
    {
        PASSED,
        FAILED,
        ERROR,
        WAIVED
    };
    static std::map<RET, std::string> ret2Str;
    TestResult();
    virtual
    ~TestResult();
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
    RET
    getRet() const;
    void
    setRet(RET);
    const std::string&
    getErrorlog() const;

protected:
    std::string errorlog;
    RET         ret;
};
} /* namespace eut */

#endif /* TESTRESULT_H_ */
