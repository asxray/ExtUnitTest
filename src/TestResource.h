/*
 * TestResource.h
 *
 *  Created on: Apr 22, 2014
 *      Author: josephx
 */

#ifndef TESTRESOURCE_H_
#define TESTRESOURCE_H_

namespace eut {
class TestResource {
 public:
  TestResource();
  virtual ~TestResource();
  virtual void SetUp() = 0;
  virtual void TearDown() = 0;
};
} /* namespace eut */

#endif /* TESTRESOURCE_H_ */
