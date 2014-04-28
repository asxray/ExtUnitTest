/*
 * TestStatus.h
 *
 *  Created on: Apr 21, 2014
 *      Author: josephx
 */

#ifndef TESTSTATUS_H_
#define TESTSTATUS_H_

#include <string>
#include <map>

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
  std::string& toString(void) const;

 private:
  STATUS status;
  static std::map<STATUS, std::string> stat2str;
};
} /* namespace eut */

#endif /* TESTSTATUS_H_ */
