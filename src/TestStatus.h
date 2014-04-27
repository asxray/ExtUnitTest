/*
 * TestStatus.h
 *
 *  Created on: Apr 21, 2014
 *      Author: josephx
 */

#ifndef TESTSTATUS_H_
#define TESTSTATUS_H_

namespace eut {
class TestStatus {
 public:
  enum STATUS {
    WAITING,
    START,
    SETUP,
    RUNNING,
    TEARDOWN,
    END
  };
  TestStatus();
  virtual ~TestStatus();
  STATUS
  getStatus() const;
  void setStatus(STATUS status);

 protected:
  STATUS status;
};
} /* namespace eut */

#endif /* TESTSTATUS_H_ */
