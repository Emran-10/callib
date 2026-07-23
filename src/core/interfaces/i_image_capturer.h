#pragma once
#include <QString>

namespace core::interfaces {

class IImageCapturer {
public:
    virtual ~IImageCapturer() = default;
    virtual bool captureRegion() = 0;
    virtual QString getCapturedImagePath() const = 0;
};

} // namespace core::interfaces
