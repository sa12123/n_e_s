#pragma once

#include "nes/core/ines_controller.h"

namespace n_e_s::core {

class NesController : public INesController {
public:
    NesController() {}

    void set(const Button button, const bool state) {
        switch (button) {
        case Button::A:
            a_ = state;
            break;
        case Button::B:
            b_ = state;
            break;
        case Button::Select:
            select_ = state;
            break;
        case Button::Start:
            start_ = state;
            break;
        case Button::Up:
            up_ = state;
            break;
        case Button::Down:
            down_ = state;
            break;
        case Button::Left:
            left_ = state;
            break;
        case Button::Right:
            right_ = state;
            break;
        }
    }

    void set(const bool a,
            const bool b,
            const bool select,
            const bool start,
            const bool up,
            const bool down,
            const bool left,
            const bool right) {
        a_ = a;
        b_ = b;
        select_ = select;
        start_ = start;
        up_ = up;
        down_ = down;
        left_ = left;
        right_ = right;
    }

    bool get(const Button button) {
        switch (button) {
        case Button::A:
            return a_;
            break;
        case Button::B:
            return b_;
            break;
        case Button::Select:
            return select_;
            break;
        case Button::Start:
            return start_;
            break;
        case Button::Up:
            return up_;
            break;
        case Button::Down:
            return down_;
            break;
        case Button::Left:
            return left_;
            break;
        case Button::Right:
            return right_;
            break;
        default:
            return false;
        }
    }

private:
    bool a_{false};
    bool b_{false};
    bool select_{false};
    bool start_{false};
    bool up_{false};
    bool down_{false};
    bool left_{false};
    bool right_{false};
};

} // namespace n_e_s::core