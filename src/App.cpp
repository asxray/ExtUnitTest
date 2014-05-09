#include "App.h"
//
#include <string>
#include <vector>
//
#include "BaseTestRunner.h"
#include "ListTestRunner.h"
#include "MultiThreadTestRunner.h"
//
#include "RootTestSuite.h"
//
#include "ConsoleTestLogger.h"
#include "SqlTestLogger.h"

namespace eut {
App::App(const int argc, char const* const* const argv)
    : options("allowed options") {
  this->options.add_options()             //
      ("help,h", "produce help message")  //
      ("filter", boost::program_options::value<std::vector<std::string> >(),
       "filter keywords, only the matched tests will be run.")  //
      ("job,j", boost::program_options::value<int>()->default_value(8),
       "specifies the number of jobs (tests) to run simultaneously.")  //
      ("list", "list all tests.")                                      //
      ("log", boost::program_options::value<std::string>()->default_value(
                  "testlog.txt"),
       "filename of plain format log")  //
      ("sql", boost::program_options::value<std::string>()->default_value(
                  "testlog.sql"),
       "filename of sql format log")  //
      ("db",
       boost::program_options::value<std::string>()->default_value("DBNAME"),
       "SQL Database name")  //
      ("table",
       boost::program_options::value<std::string>()->default_value("TABLENAME"),
       "SQL Table name")  //
      ;
  boost::program_options::store(
      boost::program_options::parse_command_line(argc, argv, this->options),
      this->vmap);
  boost::program_options::notify(this->vmap);
};
App::~App() {};
int App::Exec() {
  try {
    this->SetUp();
    this->Run();
    this->TearDown();
  }
  catch (int& n) {
    return n;
  }
  return 0;
};
void App::SetUp() {
  if (this->vmap.count("help")) {
    std::cout << this->options << std::endl;
    throw 0;
  }
}
void App::Run() {
  std::shared_ptr<BaseTestRunner> runner;
  if (this->vmap.count("list")) {
    runner.reset(new ListTestRunner);
  } else if (this->vmap.at("job").as<int>() > 1) {
    runner.reset(new MultiThreadTestRunner(this->vmap.at("job").as<int>()));
    runner->Attach(ConsoleTestLogger::Instance());
    runner->Attach(SqlTestLogger::Instance());
  } else {
    runner.reset(new BaseTestRunner);
    runner->Attach(ConsoleTestLogger::Instance());
    runner->Attach(SqlTestLogger::Instance());
  }
  RootTestSuite::Instance()->Accept(runner.get());
};
void App::TearDown() {};
}
