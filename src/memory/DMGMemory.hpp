//
// Created by patel on 2025-08-14.
//

#ifndef GAMEBOY_EMULATOR_DMGMEMORY_HPP
#define GAMEBOY_EMULATOR_DMGMEMORY_HPP

#include "Memory.hpp"
#include <array>
#include <vector>

class DMGMemory : public Memory {
public:
    using Byte = uint8_t;
    using Addr = uint32_t;
    static constexpr Addr MEMORY_SIZE = 0x10000; // 64KB DMG memory

    // DMG Memory Map constants
    static constexpr Addr VRAM_START  = 0x8000;
    static constexpr Addr VRAM_END    = 0x9FFF;
    static constexpr Addr WRAM_START  = 0xC000;
    static constexpr Addr WRAM_END    = 0xDFFF;
    static constexpr Addr ECHO_START  = 0xE000;
    static constexpr Addr ECHO_END    = 0xFDFF;
    static constexpr Addr IO_START    = 0xFF00;
    static constexpr Addr IO_END      = 0xFF7F;

    DMGMemory();

    Byte read(Addr addr) const override;
    void write(Addr addr, Byte value) override;

    // Loads a ROM into memory (max 32KB for DMG without banking)
    void loadROM(const std::vector<Byte>& romData);

private:
    std::array<Byte, MEMORY_SIZE> data; // actual memory storage

    // Utility for handling mirrored regions (like Echo RAM)
    Addr mirrorAddress(Addr addr) const;
};

#endif //GAMEBOY_EMULATOR_DMGMEMORY_HPP
