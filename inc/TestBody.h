/*
 * TestBody.h
 *
 *  Created on: Apr 22, 2014
 *      Author: josephx
 */

#ifndef TESTBODY_H_
#define TESTBODY_H_

namespace eut
{
class TestBody
{
public:
    TestBody();
    virtual
    ~TestBody();
    virtual
    void
    Run() = 0;
};
} /* namespace eut */

#endif /* TESTBODY_H_ */
