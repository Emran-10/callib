#pragma once
#include "core/interfaces/i_image_capturer.h"

namespace features::image_capture {

class ImageCapturer : public core::interfaces::IImageCapturer {
public:
    QString captureImage() override;
};

} // namespace features::image_capture
