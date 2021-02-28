#pragma once

#include "nes/core/imembank.h"
#include "nes/core/ines_controller.h"

namespace n_e_s::core {

class MemBankControllerIO : public IMemBank {
public:
    MemBankControllerIO(uint8_t slot, INesController *controller)
            : controller_(controller),
              controller_addr_{
                      slot == 0 ? uint16_t(0x4016) : uint16_t(0x4017)} {}

    bool is_address_in_range(uint16_t addr) const override {
        return addr == controller_addr_;
    }

    uint8_t read_byte(uint16_t addr) const override {
        if (addr == controller_addr_) {
            // uint8_t data = data_;
            uint8_t data = 0x40;
            uint8_t btn = 0x00;

            switch (read_cnt_++) {
            case 0:
                btn = controller_->get(INesController::Button::A) ? 0x01 : 0x00;
                break;
            case 1:
                btn = controller_->get(INesController::Button::B) ? 0x01 : 0x00;
                break;
            case 2:
                btn = controller_->get(INesController::Button::Select) ? 0x01
                                                                       : 0x00;
                break;
            case 3:
                btn = controller_->get(INesController::Button::Start) ? 0x01
                                                                      : 0x00;
                break;
            case 4:
                btn = controller_->get(INesController::Button::Up) ? 0x01
                                                                   : 0x00;
                break;
            case 5:
                btn = controller_->get(INesController::Button::Down) ? 0x01
                                                                     : 0x00;
                break;
            case 6:
                btn = controller_->get(INesController::Button::Left) ? 0x01
                                                                     : 0x00;
                break;
            case 7:
                btn = controller_->get(INesController::Button::Right) ? 0x01
                                                                      : 0x00;
                break;
            }
            data = (data & 0xFE) | btn;
            return data;
        }
        return 0x00;
    }

    void write_byte(uint16_t addr, uint8_t data) override {
        if (addr == controller_addr_) {
            if (((data_ & 0x01) == 0x01) && ((data & 0x01) == 0x00)) {
                // Neg flank on bit 0 should latch controller button states -
                // here just make sure counter is reset
                read_cnt_ = 0;
            }
            data_ = data;
        }
    }

private:
    INesController *controller_;
    uint16_t controller_addr_;
    mutable uint8_t read_cnt_{0};
    uint8_t data_{0};
};

} // namespace n_e_s::core