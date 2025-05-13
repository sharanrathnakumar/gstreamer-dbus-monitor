#ifndef DBUS_MONITOR_H
#define DBUS_MONITOR_H

#include <string>

class DBusMonitor {
public:
    DBusMonitor();
    ~DBusMonitor();

    void connect(const std::string& busName);
    void disconnect();
    void listenForSignals();

private:
    // Add private members for DBus connection and state management
};

#endif // DBUS_MONITOR_H