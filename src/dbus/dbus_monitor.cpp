#include "dbus_monitor.h"
#include <iostream>

DBusMonitor::DBusMonitor() : connection(nullptr) {}

bool DBusMonitor::connect(const std::string& busName) {
    GError *error = nullptr;
    connection = g_bus_get_sync(G_BUS_TYPE_SESSION, nullptr, &error);
    if (error) {
        std::cerr << "Failed to connect to DBus: " << error->message << std::endl;
        g_error_free(error);
        return false;
    }
    return true;
}

void DBusMonitor::disconnect() {
    if (connection) {
        g_object_unref(connection);
        connection = nullptr;
    }
}

void DBusMonitor::listenForSignals() {
    // Implementation for listening to GStreamer signals
    // This would typically involve setting up a signal handler
}