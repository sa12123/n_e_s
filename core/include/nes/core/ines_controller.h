#pragma once

namespace n_e_s::core {

class INesController {
public:
    enum class Button { A, B, Select, Start, Up, Down, Left, Right };

    virtual ~INesController() = default;

    virtual void set(const Button button, const bool state) = 0;
    virtual void set(const bool a,
            const bool b,
            const bool select,
            const bool start,
            const bool up,
            const bool down,
            const bool left,
            const bool right) = 0;
    virtual bool get(const Button button) = 0;
};

} // namespace n_e_s::core