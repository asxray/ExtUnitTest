/*
 * TestSuite.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: josephx
 */

#include "TestSuite.h"

namespace eutest
{
TestSuite::TestSuite()
{
    // TODO Auto-generated constructor stub
}

TestSuite::~TestSuite()
{
    // TODO Auto-generated destructor stub
}

void
TestSuite::add(TestBase* TestBase)
{
#pragma omp critical
    TestBase->setParent(this);
    this->myList.push_back(TestBase);
}

void
TestSuite::clear()
{
#pragma omp critical
    this->myList.clear();
}
} /* namespace eutest */
