#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>

class Logger {
public:
    Logger(const std::string& logFile);
    // static void logError(const std::string& message);
    // static void logWarning(const std::string& message);
    // static void logInfo(const std::string& message);
    void logError(const std::string& message);
    void logWarning(const std::string& message);
    void logInfo(const std::string& message);
    void log(const std::string& level, const std::string& message);


private:
    std::string currentDateTime();
    std::string logFileName;
};

#endif // LOGGER_H