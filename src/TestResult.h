/*
 * TestResult.h
 *
 *  Created on: Apr 21, 2014
 *      Author: josephx
 */

#ifndef TESTRESULT_H_
#define TESTRESULT_H_

#include <map>
#include <ostream>
#include <string>

namespace eut {
class TestResult {
 public:
  enum RET {
    PASSED,
    FAILED,
    ERROR,
    WAIVED
  };
  TestResult();
  virtual ~TestResult();
  friend std::ostream& operator<<(std::ostream&, TestResult&);
  friend TestResult& operator<<(TestResult&, std::string);
  RET getRet() const;
  void setRet(RET);
  const std::string& getLog() const;
  const std::string& getRetStr() const;
  const double& getTimer(const std::string&) const;
  void setTimer(const std::string&, const double&);

 protected:
  static std::map<RET, std::string> ret2Str;
  std::string errorlog;
  RET ret;
  std::map<std::string, double> timer;
};
} /* namespace eut */

#endif /* TESTRESULT_H_ */
