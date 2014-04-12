/*
 * TestVisitor.h
 *
 *  Created on: Apr 13, 2014
 *      Author: josephx
 */

#ifndef TESTVISITOR_H_
#define TESTVISITOR_H_

#include "TestBase.h"
#include <boost/shared_ptr.hpp>
namespace eutest
{
template<typename T>
class TestVisitor
{
public:
    TestVisitor();
    virtual
    ~TestVisitor();
protected:
    virtual bool
    preVisit(T&)  = 0;
    virtual void
    visit(T&)     = 0;
    virtual void
    postVisit(T&) = 0;
};
} /* namespace eutest */

#endif /* TESTVISITOR_H_ */
