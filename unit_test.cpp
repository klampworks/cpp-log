#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>

#define CPP_LOG_COUT 
#define CPP_LOG_CERR 
#define CPP_LOG_ERR_COUT
#define CPP_LOG_ERR_CERR
#define CPP_LOG_ERR_FILE "output"

#include "cpp_log.hpp"

BOOST_AUTO_TEST_CASE(a)
{
	clog::err() << "hello " << 66 << " " << std::hex << 66;
}
