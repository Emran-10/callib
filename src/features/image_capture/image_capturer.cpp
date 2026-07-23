#include "image_capturer.h"
#include <QDebug>

namespace features::image_capture {

bool ImageCapturer::captureRegion() {
    qDebug() << "[ImageCapturer] Capturing image region";
    m_imagePath = "captured_image.png";
    return true;
}

QString ImageCapturer::getCapturedImagePath() const {
    return m_imagePath;
}

} // namespace features::image_capture
