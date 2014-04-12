/*
 * TestBase.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: josephx
 */

#include "TestBase.h"

namespace eutest
{
TestBase::TestBase()
{
    // TODO Auto-generated constructor stub
}

TestBase::~TestBase()
{
    // TODO Auto-generated destructor stub
}

const std::string&
TestBase::getDescription() const
{
    return(description);
}

void
TestBase::setDescription(const std::string& description)
{
    this->description = description;
}

const std::string&
TestBase::getName() const
{
    return(name);
}

void
TestBase::setName(const std::string& name)
{
    this->name = name;
}

const TestBase* const
TestBase::getParent() const
{
    return(parent);
}

void
TestBase::setParent(TestBase* const parent)
{
    this->parent = parent;
}
} /* namespace eutest */
