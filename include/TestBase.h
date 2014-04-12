/*
 * TestBase.h
 *
 *  Created on: Apr 13, 2014
 *      Author: josephx
 */

#ifndef TESTBASE_H_
#define TESTBASE_H_

#include "TestVisitor.h"
#include <boost/shared_ptr.hpp>
#include <string>

namespace eutest
{
class TestBase
{
public:
    TestBase();
    virtual
    ~TestBase();
public:
    virtual void
    accept(const TestVisitor<TestBase>&) = 0;
public: // getters & setters
    const std::string&
    getDescription() const;
    void
    setDescription(const std::string&);
    const std::string&
    getName() const;
    void
    setName(const std::string&);
    const TestBase* const
    getParent() const;
    void
    setParent(TestBase* const);

protected:
    std::string     name;
    std::string     description;
    TestBase const* parent;
};

typedef boost::shared_ptr<TestBase> spTestBase;
} /* namespace eutest */

#endif /* TESTBASE_H_ */
