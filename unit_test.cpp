#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>

#define CPP_LOG_FILE "output"
#define CPP_LOG_COUT 
#define CPP_LOG_CERR 

#include "cpp_log.hpp"

BOOST_AUTO_TEST_CASE(a)
{
	logger log;
	log << "hello " << 6;

}
