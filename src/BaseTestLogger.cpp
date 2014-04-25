/*
 * BaseTestLogger.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: josephx
 */

#include "BaseTestLogger.h"

namespace eut
{
BaseTestLogger::BaseTestLogger()
{}

BaseTestLogger::~BaseTestLogger()
{}

void
BaseTestLogger::Update(TestCase const* const aCase)
{
    if (funcMap.count(aCase->getStatus()))
        funcMap.at(aCase->getStatus()) (aCase);
}
} /* namespace eut */
