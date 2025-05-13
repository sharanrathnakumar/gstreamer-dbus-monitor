#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    void logError(const std::string& message);
    void logWarning(const std::string& message);
    void logInfo(const std::string& message);
};

#endif // LOGGER_H