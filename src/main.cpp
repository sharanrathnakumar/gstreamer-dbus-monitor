#include <iostream>
#include "dbus/dbus_monitor.h"
#include "gstreamer/gst_pipeline_monitor.h"
#include "cli/cli_interface.h"
#include "utils/logger.h"
#include <string>

std::string path = "/home/sharan/logfile.log";

int main(int argc, char* argv[]) {
    Logger logger(path);
    DBusMonitor dbusMonitor;
    GStreamerPipelineMonitor pipelineMonitor;
    CLIInterface cliInterface;

    logger.logInfo("Starting GStreamer DBus Monitor...");

    if (!dbusMonitor.connect("session")) {
        logger.logError("Failed to connect to DBus.");
        return 1;
    }

    dbusMonitor.listenForSignals();

    cliInterface.showHelp();
    std::string pipeline_;

    while (true) {
        std::string command;
        std::cin >> command;
     
        cliInterface.parseCommand(command);
        if (command == "exit") {
            break;
        }
        pipelineMonitor.sendCommand(pipeline_, command);
        cliInterface.displayStatus(pipelineMonitor.getPipelineState(pipeline_));
    }

    dbusMonitor.disconnect();
    logger.logInfo("Exiting GStreamer DBus Monitor.");
    return 0;
}