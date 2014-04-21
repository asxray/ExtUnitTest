/*
 * TestStatus.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: josephx
 */

#include "TestStatus.h"

namespace eut
{
TestStatus::TestStatus()
    : status(TestStatus::WAITING)
{}

TestStatus::~TestStatus()
{}

TestStatus::STATUS
TestStatus::getStatus() const
{
    return(status);
}

void
TestStatus::setStatus(TestStatus::STATUS status)
{
    this->status = status;
}
} /* namespace eut */
