#ifndef CPP_LOG
#define CPP_LOG

#include <ostream>
#include <iostream>

struct logger {

	#ifdef CPP_LOG_FILE
	std::ofstream ofs;
	#endif

	logger()
	{
		#ifdef CPP_LOG_FILE
		ofs.open(CPP_LOG_FILE);
		#endif
	}

	~logger()
	{
		#ifdef CPP_LOG_FILE
		ofs.close();
		#endif
	}

	template <typename t>
	logger& operator<<(const t s)
	{
		#ifdef CPP_LOG_FILE
		ofs << s;
		#endif

		//ss[0] << s;
		return *this;
	}
};

#endif
