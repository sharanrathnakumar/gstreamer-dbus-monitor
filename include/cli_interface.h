#ifndef CLI_INTERFACE_H
#define CLI_INTERFACE_H

#include <string>

class CLIInterface {
public:
    void displayStatus(const std::string& status);
    void parseCommand(const std::string& command);
    void showHelp();
};

#endif // CLI_INTERFACE_H