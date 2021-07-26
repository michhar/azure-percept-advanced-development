// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

// Standard library includes
#include <cstdint>
#include <vector>

#pragma once

namespace rtsp {

/** A struct to represent an H264 frame. */
typedef struct {
   /** The actual data in the frame. */
   std::vector<uint8_t> data;

   /** The timestamp for this frame. */
   int64_t timestamp;
} H264;

} // namespace rtsp