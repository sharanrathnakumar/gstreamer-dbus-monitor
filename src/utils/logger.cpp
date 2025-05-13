#include "logger.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

Logger::Logger(const std::string& logFile) : logFileName(logFile) {
    std::ofstream ofs(logFileName, std::ios::app);
    if (!ofs) {
        std::cerr << "Failed to open log file: " << logFileName << std::endl;
    }
}

void Logger::logError(const std::string& message) {
    log("ERROR", message);
}

void Logger::logWarning(const std::string& message) {
    log("WARNING", message);
}

void Logger::logInfo(const std::string& message) {
    log("INFO", message);
}

void Logger::log(const std::string& level, const std::string& message) {
    std::ofstream ofs(logFileName, std::ios::app);
    if (ofs) {
        ofs << "[" << currentDateTime() << "] " << level << ": " << message << std::endl;
    }
}

std::string Logger::currentDateTime() {
    time_t now = time(0);
    char buf[80];
    struct tm tstruct;
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    return buf;
}