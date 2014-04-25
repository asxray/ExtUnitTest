/*
 * TestSuite.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: josephx
 */

#include "TestSuite.h"

namespace eut
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
TestSuite::Accept(dp::BaseVisitor* const guest)
{
    return(Traverse(this, guest));
}
} /* namespace eut */
