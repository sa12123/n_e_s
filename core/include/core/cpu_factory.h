// Copyright 2018 Evil Corp contributors
// Copyright 2018 Robin Linden <dev@robinlinden.eu>

#pragma once

#include "core/icpu.h"
#include "core/immu.h"

#include <memory>

namespace n_e_s::core {

class CpuFactory {
public:
    static std::unique_ptr<ICpu> create(Registers *registers, IMmu *mmu);
};

} // namespace n_e_s::core
