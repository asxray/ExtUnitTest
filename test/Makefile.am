include $(top_srcdir)/common.am

AM_DEFAULT_SOURCE_EXT = .cpp

AM_CXXFLAGS +=\
-D BOOST_TEST_DYN_LINK\
-D BOOST_TEST_MAIN\
-I $(top_srcdir)/src

AM_LDFLAGS=\
../src/libextunittest.la\
-lboost_program_options\
-lboost_system\
-lboost_thread\
-lboost_unit_test_framework

TESTS_ENVIRONMENT = valgrind -q

TESTS =\
App_test\
BaseTestObserver_test\
BaseTestRunner_test\
Cloneable_test\
Composite_test\
ConsoleTestLogger_test\
ListTestRunner_test\
MultiThreadTestRunner_test\
Observer_test\
RootTestSuite_test\
Singleton_test\
SqlTestLogger_test\
TestBody_test\
TestCase_test\
TestResource_test\
TestResult_test\
TestStatus_test\
TestSuite_test\
Visitor_test

check_PROGRAMS = $(TESTS)
