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
        : is_h264(ish264)
    {
        if (ish264)
        {
            this->h264data = H264(std::vector<uint8_t>{}, (int64_t)std::time(nullptr));
        }
        else
        {
            this->ocvdata = cv::Mat(DEFAULT_HEIGHT, DEFAULT_WIDTH, CV_8UC3, cv::Scalar(0, 0, 0));
        }
    }

    Frame::Frame(const cv::Mat &mat)
        : is_h264(false)
    {
        this->ocvdata = mat.clone();
    }

    Frame::Frame(const H264 &h)
        : is_h264(true)
    {
        this->h264data = h;
    }

    Frame::Frame(const Frame &other)
        : is_h264(other.is_h264)
    {
        if (other.is_h264)
        {
            this->h264data = other.h264();
        }
        else
        {
            this->ocvdata = other.ocv();
        }
    }

    Frame::~Frame()
    {
        // Nothing to do
    }

    Frame& Frame::operator=(const Frame &rhs)
    {
        if (this != &rhs)
        {
            this->is_h264 = rhs.is_h264;
            if (this->is_h264)
            {
                this->h264data = rhs.h264data;
            }
            else
            {
                this->ocvdata = rhs.ocvdata;
            }
        }

        return *this;
    }

    Frame Frame::clone() const
    {
        if (this->is_h264)
        {
            return std::move(Frame(this->h264data));
        }
        else
        {
            return std::move(Frame(this->ocvdata.clone()));
        }
    }

    bool Frame::ish264() const
    {
        return this->is_h264;
    }

    cv::Mat Frame::ocv() const
    {
        return this->ocvdata;
    }

    H264 Frame::h264() const
    {
        return this->h264data;
    }

} // namespace rtsp