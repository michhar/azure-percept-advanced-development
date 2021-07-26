// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

// Standard library includes
#include <ctime>
#include <vector>

// Third party includes

// Local includes
#include "frame.hpp"
#include "h264.hpp"
#include "resolution.hpp"

namespace rtsp {
    Frame::Frame()
        : Frame(false)
    {
    }

    Frame::Frame(bool ish264)
        : is_this_h264(ish264), data(cv::Mat())
    {
        if (ish264)
        {
            this->data = {H264(std::vector<uint8_t>{}, (int64_t)std::time(nullptr))};
        }
        else
        {
            this->data = {cv::Mat(DEFAULT_HEIGHT, DEFAULT_WIDTH, CV_8UC3, cv::Scalar(0, 0, 0))};
        }
    }

    Frame::Frame(const cv::Mat &mat)
        : is_this_h264(false)
    {
        // TODO
    }

    Frame::Frame(const H264 &h)
        : is_this_h264(true)
    {
        // TODO
    }

    bool Frame::ish264() const
    {
        return this->is_this_h264;
    }

} // namespace rtsp