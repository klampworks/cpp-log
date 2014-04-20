#ifndef CPP_LOG2
#define CPP_LOG2

#include <sstream>
#include <iostream>
#include <ctime>
#include <string>
#include <mutex>

/* TODO symbol log is already defined in mathcalls.h. */
namespace clog {

std::mutex m;

struct logger2 {

	std::stringstream ss;
	const char *level;

	std::string now()
	{
		time_t t = time(NULL);
		struct tm *tm_info;
		tm_info = localtime(&t);

		char buf[20];
		strftime(buf, 20, "%F %T", tm_info);
		return std::string(buf);
	}

	logger2(const char *llevel)
	{
		level = llevel;
	}

	void flush(std::ostream &out)
	{
		m.lock();
		out << level << ": " << now() << " " 
			<< ss.str() << std::endl;
		m.unlock();
	}

	virtual ~logger2()
	{
	}

	template <typename t>
	logger2& operator<<(const t s)
	{
		ss << s;
		return *this;
	}
};

/* TODO Copy and pasted code. */
struct err : public logger2 {

	#ifdef CPP_LOG_ERR_FILE
	std::ofstream ofs;
	#endif

	err() : logger2("Error") {
		#ifdef CPP_LOG_ERR_FILE
		ofs.open(CPP_LOG_ERR_FILE, 
			std::ios_base::app | std::ios_base::out);
		#endif
	};

	~err() {
		#ifdef CPP_LOG_ERR_COUT
		flush(std::cout);
		#endif

		#ifdef CPP_LOG_ERR_CERR
		flush(std::cerr);
		#endif

		#ifdef CPP_LOG_ERR_FILE
		flush(ofs);
		ofs.close();
		#endif
	}
};

struct warn : public logger2 {

	#ifdef CPP_LOG_WARN_FILE
	std::ofstream ofs;
	#endif

	warn() : logger2("Warning") {
		#ifdef CPP_LOG_WARN_FILE
		ofs.open(CPP_LOG_WARN_FILE, 
			std::ios_base::app | std::ios_base::out);
		#endif
	};

	~warn() {
		#ifdef CPP_LOG_WARN_COUT
		flush(std::cout);
		#endif

		#ifdef CPP_LOG_WARN_CERR
		flush(std::cerr);
		#endif

		#ifdef CPP_LOG_WARN_FILE
		flush(ofs);
		ofs.close();
		#endif
	}
};

struct info : public logger2 {

	#ifdef CPP_LOG_INFO_FILE
	std::ofstream ofs;
	#endif

	info() : logger2("Info") {
		#ifdef CPP_LOG_INFO_FILE
		ofs.open(CPP_LOG_INFO_FILE, 
			std::ios_base::app | std::ios_base::out);
		#endif
	};

	~info() {
		#ifdef CPP_LOG_INFO_COUT
		flush(std::cout);
		#endif

		#ifdef CPP_LOG_INFO_CERR
		flush(std::cerr);
		#endif

		#ifdef CPP_LOG_INFO_FILE
		flush(ofs);
		ofs.close();
		#endif
	}
};

}
#endif
