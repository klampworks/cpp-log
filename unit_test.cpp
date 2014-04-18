#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>

//#define CPP_LOG_FILE "output"
#define CPP_LOG_COUT 
#define CPP_LOG_CERR 
#define CPP_LOG_ERR_COUT
#define CPP_LOG_ERR_CERR
#define CPP_LOG_ERR_FILE "output"

#include "cpp_log.hpp"
#include "cpp_log2.hpp"

BOOST_AUTO_TEST_CASE(a)
{
	logger log;
	error() << "hello " << 6 << std::hex << 666;

}
