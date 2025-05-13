#include "gst_pipeline_monitor.h"
#include <iostream>

GStreamerPipelineMonitor::GStreamerPipelineMonitor() {
    // Initialization code if needed
}

GStreamerPipelineMonitor::~GStreamerPipelineMonitor() {
    // Cleanup code if needed
}

std::string GStreamerPipelineMonitor::getPipelineState(const std::string& pipelineName) {
    // Logic to retrieve the pipeline state using GStreamer API
    GstElement* pipeline = gst_element_factory_make(pipelineName.c_str(), nullptr);
    GstState state;
    std::string result = "UNKNOWN";

    if (pipeline) {
        gst_element_get_state(pipeline, &state, nullptr, GST_CLOCK_TIME_NONE);
        const gchar* state_str = gst_element_state_get_name(state);
        result = state_str ? state_str : "UNKNOWN";
        gst_object_unref(pipeline);
    } else {
        std::cerr << "Pipeline not found: " << pipelineName << std::endl;
    }
    return result;
}

void GStreamerPipelineMonitor::sendCommand(const std::string& pipelineName, GstMessageType command) {
    // Logic to send control commands to the GStreamer pipeline
    GstElement* pipeline = gst_element_factory_make(pipelineName.c_str(), nullptr);
    if (pipeline) {
        // Send command logic here
        gst_object_unref(pipeline);
    } else {
        std::cerr << "Pipeline not found: " << pipelineName << std::endl;
    }
}

void GStreamerPipelineMonitor::handleError(GstMessage* msg) {
    // Logic to handle errors from GStreamer
    GError* err;
    gchar* debug_info;
    gst_message_parse_error(msg, &err, &debug_info);
    std::cerr << "Error received from element " << GST_OBJECT_NAME(msg->src) << ": " << err->message << std::endl;
    std::cerr << "Debugging information: " << (debug_info ? debug_info : "none") << std::endl;
    g_clear_error(&err);
    g_free(debug_info);
}