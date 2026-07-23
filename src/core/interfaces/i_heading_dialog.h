#pragma once

namespace core::interfaces {

class IHeadingDialog {
public:
    virtual ~IHeadingDialog() = default;
    virtual void showDialog() = 0;
};

} // namespace core::interfaces
