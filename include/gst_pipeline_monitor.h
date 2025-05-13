#ifndef GST_PIPELINE_MONITOR_H
#define GST_PIPELINE_MONITOR_H

#include <string>

class GStreamerPipelineMonitor {
public:
    GStreamerPipelineMonitor();
    ~GStreamerPipelineMonitor();

    std::string getPipelineState(const std::string& pipelineName);
    void sendCommand(const std::string& pipelineName, const std::string& command);
    void handleError(const std::string& errorMessage);
};

#endif // GST_PIPELINE_MONITOR_H