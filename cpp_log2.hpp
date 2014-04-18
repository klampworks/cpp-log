#ifndef CPP_LOG2
#define CPP_LOG2

#include <sstream>
#include <iostream>
#include <chrono>
#include <ctime>

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
		out << level << ": " << now() << " Prefix " 
			<< ss.str() << std::endl;
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

struct error : public logger2 {

	#ifdef CPP_LOG_ERR_FILE
	std::ofstream ofs;
	#endif

	error() : logger2("Error") {
		#ifdef CPP_LOG_ERR_FILE
		ofs.open(CPP_LOG_ERR_FILE, 
			std::ios_base::app | std::ios_base::out);
		#endif
	};

	~error() {
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

struct warning : public logger2 {

	#ifdef CPP_LOG_WARN_FILE
	std::ofstream ofs;
	#endif

	warning() : logger2("Warning") {
		#ifdef CPP_LOG_WARN_FILE
		ofs.open(CPP_LOG_WARN_FILE, 
			std::ios_base::app | std::ios_base::out);
		#endif
	};

	~warning() {
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

#endif
