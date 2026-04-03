// logger.hpp - Declaration of the Logger class
// Logging helps us see what the server is doing while it runs.
// We'll print messages like:
//   [INFO]  Server started on port 8080
//   [ERROR] Failed to open socket

#ifndef LOGGER_HPP
#define LOGGER_HPP

class Logger {
public:
    Logger();
    ~Logger();
};

#endif // LOGGER_HPP
