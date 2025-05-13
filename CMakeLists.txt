cmake_minimum_required(VERSION 3.10)
project(gstreamer-dbus-monitor)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find dependencies using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED glib-2.0)
pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)
pkg_check_modules(DBUS REQUIRED dbus-1)

# Add the executable
add_executable(gst_dbus_monitor
    src/main.cpp
    src/dbus/dbus_monitor.cpp
    src/cli/cli_interface.cpp
    src/gstreamer/gst_pipeline_monitor.cpp
    src/utils/logger.cpp
)

# Include directories
target_include_directories(gst_dbus_monitor PRIVATE
    ${GLIB_INCLUDE_DIRS}
    ${GSTREAMER_INCLUDE_DIRS}
    ${DBUS_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
)

# Link libraries
target_link_libraries(gst_dbus_monitor PRIVATE
    ${GLIB_LIBRARIES}
    ${GSTREAMER_LIBRARIES}
    ${DBUS_LIBRARIES}
)

# Compiler flags
target_compile_options(gst_dbus_monitor PRIVATE
    ${GLIB_CFLAGS_OTHER}
    ${GSTREAMER_CFLAGS_OTHER}
    ${DBUS_CFLAGS_OTHER}
)

# Linker flags (if needed)
target_link_directories(gst_dbus_monitor PRIVATE
    ${GLIB_LIBRARY_DIRS}
    ${GSTREAMER_LIBRARY_DIRS}
    ${DBUS_LIBRARY_DIRS}
)