include $(top_srcdir)/common.am

AM_DEFAULT_SOURCE_EXT = .cpp
AM_CXXFLAGS += -D BOOST_TEST_DYN_LINK -D BOOST_TEST_MAIN -I$(top_srcdir)/src
AM_LDFLAGS = -lboost_unit_test_framework \
	../src/libextunittest.la \
	-lsoci_core \
	-lsoci_mysql

AM_CXXFLAGS += -I $(top_srcdir)/soci/core
	

TESTS_ENVIRONMENT = valgrind -q

TESTS =\
Cloneable_test\
BaseTestObserver_test\
BaseTestRunner_test\
Composite_test\
Observer_test\
RootTestSuite_test\
Singleton_test\
TestBody_test\
TestCase_test\
TestResource_test\
TestResult_test\
TestStatus_test\
TestSuite_test\
Visitor_test\
DatabaseLog_test

check_PROGRAMS = $(TESTS)
