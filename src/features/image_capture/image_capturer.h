#pragma once
#include "core/interfaces/i_image_capturer.h"

namespace features::image_capture {

class ImageCapturer : public core::interfaces::IImageCapturer {
public:
    bool captureRegion() override;
    QString getCapturedImagePath() const override;

private:
    QString m_imagePath;
};

} // namespace features::image_capture
