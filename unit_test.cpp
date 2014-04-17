#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>
#include "cpp_log.hpp"
#include <iostream>

BOOST_AUTO_TEST_CASE(a)
{
	logger log(std::cout);
	log << "hello " << 6;

}
