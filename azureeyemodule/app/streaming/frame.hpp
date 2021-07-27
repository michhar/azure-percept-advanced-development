// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

#pragma once

// Standard library includes

// Local includes
#include "h264.hpp"

// Third party includes
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>


namespace rtsp {

/** The underlying data in a Frame object can be either an OpenCV Mat buffer or an H264 struct. */
union FrameData {
};

/** A Frame represents ah H.264 frame or an OpenCV Frame object. */
class Frame {
public:
    /** Constructor for a Frame object. */
    Frame();

    /** Constructor for a Frame object. */
    Frame(bool ish264);

    /** Constructor for a Frame object that is an OpenCV Mat object under the hood. */
    Frame(const cv::Mat &mat);

    /** Constructor for a Frame object taht is an H.264 frame under the hood. */
    Frame(const H264 &h);

    /** Copy constructor. */
    Frame(const Frame &other);

    /** Destructor. */
    ~Frame();

    /** Clone this object (deep copy). */
    Frame clone() const;

    /** Returns whether this Frame represents an H.264 frame or not. */
    bool ish264() const;

    /** Interpret this Frame object's data as an OpenCV Mat. */
    cv::Mat ocv() const;

    /** Interpret this Frame object as an H.264 frame. */
    H264 h264() const;

private:
    /** Is this frame an H.264 frame? */
    const bool is_h264;

    /** The data. */
    union {
        cv::Mat ocvdata;
        H264 h264data;
    };

};

} // namespace rtsp