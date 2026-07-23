#include "image_capturer.h"

namespace features::image_capture {

bool ImageCapturer::captureRegion() {
    m_lastPath = "/tmp/captured_image.png";
    return true;
}

QString ImageCapturer::getCapturedImagePath() const {
    return m_lastPath;
}

} // namespace features::image_capture
