#ifndef GST_PIPELINE_MONITOR_H
#define GST_PIPELINE_MONITOR_H

#include <gst/gst.h>
#include <string>

class GStreamerPipelineMonitor {
public:
    GStreamerPipelineMonitor();
    ~GStreamerPipelineMonitor();

    std::string getPipelineState(const std::string& pipelineName);
    void sendCommand(const std::string& pipelineName, const std::string& command);
    void handleError(const std::string& errorMessage);

private:
    // Private members for managing GStreamer pipelines can be added here
};

#endif // GST_PIPELINE_MONITOR_H