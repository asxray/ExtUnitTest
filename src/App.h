#ifndef APP_H
#define APP_H

#include <boost/program_options.hpp>

namespace eut {
class App {
 public:
  App(const int, char const* const* const);
  virtual ~App();
  int Exec();

 protected:
  virtual void SetUp();
  virtual void Run();
  virtual void TearDown();

 protected:
  boost::program_options::options_description options;
  boost::program_options::variables_map vmap;
};
}

#endif
