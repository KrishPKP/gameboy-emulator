//
// Created by patel on 2025-08-14.
//

#ifndef GAMEBOY_EMULATOR_MEMORY_HPP
#define GAMEBOY_EMULATOR_MEMORY_HPP

#include <cstdint>
#include <array>


class Memory {
public:
    static constexpr uint16_t MEMORY_SIZE = 0x10000; // 64KB total memory

    Memory();

    uint8_t read(uint16_t addr) const;  // Read a byte from memory
    void write(uint16_t addr, uint8_t value);  // Write a byte to memory

private:
    std::array<uint8_t, MEMORY_SIZE> data;  // The actual memory
};


#endif //GAMEBOY_EMULATOR_MEMORY_HPP
