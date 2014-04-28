include $(top_srcdir)/common.am
# libtools target
lib_LTLIBRARIES = libextunittest.la

AM_LDFLAGS = $(top_srcdir)/soci/lib/libsoci_core.a 
AM_LDFLAGS +=$(top_srcdir)/soci/lib/libsoci_mysql.a


AM_CXXFLAGS += -I $(top_srcdir)/soci/core

libextunittest_la_SOURCES = \
Composite.cpp\
BaseTestLogger.cpp\
BaseTestRunner.cpp\
RootTestSuite.cpp\
TestBody.cpp\
TestCase.cpp\
TestResource.cpp\
TestResult.cpp\
TestStatus.cpp\
TestSuite.cpp\
DatabaseLog.cpp

nobase_include_HEADERS = \
Cloneable.hpp\
BaseTestLogger.h\
BaseTestRunner.h\
Composite.hpp\
Observer.hpp\
RootTestSuite.h\
Singleton.hpp\
TestBody.h\
TestCase.h\
TestResource.h\
TestResult.h\
TestStatus.h\
TestSuite.h\
Visitor.hpp\
DatabaseLog.h

# flags
# libextunittest_la_LDFLAGS =
# libextunittest_la_LIBADD =
