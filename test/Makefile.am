include $(top_srcdir)/common.am

AM_DEFAULT_SOURCE_EXT = .cpp
AM_CXXFLAGS += -D BOOST_TEST_DYN_LINK -D BOOST_TEST_MAIN
AM_LDFLAGS = -lboost_unit_test_framework \
	../src/libextunittest.la

TESTS_ENVIRONMENT = valgrind -q

TESTS = \
Cloneable_test \
Composite_test \
Observer_test \
Singleton_test \
TestBody_test \
TestCase_test \
TestResource_test \
TestResult_test \
TestStatus_test \
Visitor_test

check_PROGRAMS = $(TESTS)
