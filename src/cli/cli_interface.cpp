#include "cli_interface.h"
#include <iostream>
#include <string>

// CLIInterface::CLIInterface() {
//     // Constructor implementation
// }

void CLIInterface::displayStatus(const std::string& status) {
    std::cout << "Current Status: " << status << std::endl;
}

void CLIInterface::parseCommand(const std::string& command) {
    // Simple command parsing logic
    if (command == "help") {
        showHelp();
    } else if (command == "status") {
        std::cout << "Fetching status..." << std::endl;
    } else {
        std::cout << "Unknown command. Type 'help' for a list of commands." << std::endl;
    }
}

void CLIInterface::showHelp() {
    std::cout << "Available commands:" << std::endl;
    std::cout << "  status - Display the current status" << std::endl;
    std::cout << "  exit - Exit the application" << std::endl;
    std::cout << "  help - Show this help message" << std::endl;
}