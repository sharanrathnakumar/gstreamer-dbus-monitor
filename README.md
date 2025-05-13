# GStreamer DBus Monitor/Debugger Tool

## Overview
The GStreamer DBus Monitor/Debugger Tool is a utility designed to connect to running GStreamer-based applications. It monitors their pipeline states and element statuses, allowing users to visualize and log these states directly in the command line interface (CLI). Additionally, the tool provides the capability to send control commands to the GStreamer pipelines.

## Features
- Connects to GStreamer applications via DBus.
- Monitors and logs pipeline states and element statuses.
- Sends control commands to GStreamer pipelines.
- CLI interface for user interaction and command parsing.
- Logging functionality for errors, warnings, and informational messages.

## Project Structure
```
gstreamer-dbus-monitor
├── src
│   ├── main.cpp
│   ├── dbus
│   │   ├── dbus_monitor.cpp
│   │   └── dbus_monitor.h
│   ├── gstreamer
│   │   ├── gst_pipeline_monitor.cpp
│   │   └── gst_pipeline_monitor.h
│   ├── cli
│   │   ├── cli_interface.cpp
│   │   └── cli_interface.h
│   └── utils
│       ├── logger.cpp
│       └── logger.h
├── include
│   └── gstreamer-dbus-monitor
│       ├── dbus_monitor.h
│       ├── gst_pipeline_monitor.h
│       ├── cli_interface.h
│       └── logger.h
├── CMakeLists.txt
└── README.md
```

## Setup Instructions
1. **Clone the repository:**
   ```
   git clone <repository-url>
   cd gstreamer-dbus-monitor
   ```

2. **Install dependencies:**
   Ensure you have GStreamer and DBus development packages installed on your system.

3. **Build the project:**
   ```
   mkdir build
   cd build
   cmake ..
   make
   ```

## Usage
To run the GStreamer DBus Monitor/Debugger Tool, execute the following command in the terminal:
```
./gstreamer-dbus-monitor
```

You can use various commands in the CLI to interact with the GStreamer pipelines. Type `help` to see the list of available commands.

## Contribution Guidelines
Contributions are welcome! Please follow these steps:
1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them.
4. Push your branch and create a pull request.

## License
This project is licensed under the MIT License. See the LICENSE file for details.