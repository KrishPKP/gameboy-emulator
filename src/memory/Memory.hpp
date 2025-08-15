//
// Created by patel on 2025-08-14.
//

#ifndef GAMEBOY_EMULATOR_MEMORY_HPP
#define GAMEBOY_EMULATOR_MEMORY_HPP

#include <cstdint>
#include <array>


class Memory {
public:
    using Byte = uint8_t;
    using Addr = uint32_t;
    static constexpr uint32_t MEMORY_SIZE = 0x10000;

    Memory();  // Declaration
    virtual ~Memory() = default;

    virtual Byte read(Addr addr) const = 0;
    virtual void write(Addr addr, Byte value) = 0;

protected:
    std::array<Byte, MEMORY_SIZE> data{};
};

#endif //GAMEBOY_EMULATOR_MEMORY_HPP
