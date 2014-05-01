include $(top_srcdir)/common.am

#libtools target
lib_LTLIBRARIES = libextunittest.la

AM_CXXFLAGS +=\
-I $(top_srcdir)/soci/src/core\
-I /usr/include/mysql/

libextunittest_la_SOURCES = \
BaseTestObserver.cpp\
BaseTestRunner.cpp\
Composite.cpp\
ConsoleTestLogger.cpp\
DatabaseLog.cpp\
MultiThreadTestRunner.cpp\
RootTestSuite.cpp\
TestBody.cpp\
TestCase.cpp\
TestResource.cpp\
TestResult.cpp\
TestStatus.cpp\
TestSuite.cpp

nobase_include_HEADERS =\
BaseTestObserver.h\
BaseTestRunner.h\
Cloneable.hpp\
Composite.hpp\
ConsoleTestLogger.h\
DatabaseLog.h\
MultiThreadTestRunner.h\
Observer.hpp\
RootTestSuite.h\
Singleton.hpp\
TestBody.h\
TestCase.h\
TestResource.h\
TestResult.h\
TestStatus.h\
TestSuite.h\
Visitor.hpp

#flags
#libextunittest_la_LDFLAGS =
#libextunittest_la_LIBADD =
