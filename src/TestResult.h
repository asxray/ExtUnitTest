/*
 * TestResult.h
 *
 *  Created on: Apr 21, 2014
 *      Author: josephx
 */

#ifndef TESTRESULT_H_
#define TESTRESULT_H_

#include <map>
#include <string>

namespace eut {
class TestResult {
 public:
  enum RET {
    PASSED = 1,
    FAILED = 0,
    ERROR = -1,
    WAIVED = -2
  };
  TestResult();
  virtual ~TestResult();

  RET getRet() const;
  void setRet(RET);
  const std::string& getRetStr() const;

  const double& getTimer(const std::string&) const;
  void setTimer(const std::string&, const double&);

  const std::string& getErrorLog(void) const;
  void setErrorLog(const std::string& slog);

 private:
  RET ret;
  static std::map<RET, std::string> ret2Str;
  std::map<std::string, double> timer;
  std::string ErrorLog;
};
} /* namespace eut */

#endif /* TESTRESULT_H_ */
