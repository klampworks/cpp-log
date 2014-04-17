#ifndef CPP_LOG
#define CPP_LOG

#include <ostream>
struct logger {

	std::ostream &ss;
	logger(std::ostream &s) : ss(s) {}

	template <typename t>
	logger& operator<<(const t s)
	{
		ss << s;
		return *this;
	}
};

#endif
