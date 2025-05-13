#ifndef DBUS_MONITOR_H
#define DBUS_MONITOR_H

#include <glib.h>
#include <gio/gio.h>
#include <string>

class DBusMonitor {
public:
    DBusMonitor();
    ~DBusMonitor();

    bool connect(const std::string& busName);
    void disconnect();
    void listenForSignals();

private:
    // Add private members for DBus connection and state management
    GDBusConnection *connection;
};

#endif // DBUS_MONITOR_H