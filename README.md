cpp-log
=======

A simple ostream based header only logging library.

Logging is configured at compile time through preprocessor directives.

    #define CPP_LOG_ERR_COUT
    #define CPP_LOG_ERR_CERR
    #define CPP_LOG_ERR_FILE "output.log"
    #include <cpp_log.hpp>

    clog::err() << "hello " << 66 << " " << std::hex << 66;

Output:

	Error: 2014-04-19 10:03:48 hello 66 42

Printed to standard out, standard error and appended to the file output.log.

There are currently 3 level of logging, err, warn and info.

