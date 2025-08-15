//
// Created by patel on 2025-08-14.
//
#include "DMGMemory.hpp"
#include <stdexcept>
#include <iostream>

DMGMemory::DMGMemory() {
    data.fill(0); // Initialize memory to zero
}

Memory::Byte DMGMemory::read(Addr addr) const {
    if (addr >= MEMORY_SIZE) {
        throw std::out_of_range("DMGMemory read: Address out of range");
    }

    // Handle mirrored region (Echo RAM)
    if (addr >= ECHO_START && addr <= ECHO_END) {
        addr = mirrorAddress(addr);
    }

    // TODO: Add memory-mapped I/O handling here (IO_START–IO_END)
    return data[addr];
}

void DMGMemory::write(Addr addr, Byte value) {
    if (addr >= MEMORY_SIZE) {
        throw std::out_of_range("DMGMemory write: Address out of range");
    }

    // Handle mirrored region (Echo RAM)
    if (addr >= ECHO_START && addr <= ECHO_END) {
        addr = mirrorAddress(addr);
    }

    // TODO: Add memory-mapped I/O handling here (IO_START–IO_END)
    data[addr] = value;
}

void DMGMemory::loadROM(const std::vector<Byte>& romData) {
    for (size_t i = 0; i < romData.size() && i < 0x8000; ++i) {
        data[i] = romData[i];
    }
}

// Map echo RAM to normal work RAM
DMGMemory::Addr DMGMemory::mirrorAddress(Addr addr) const {
    return addr - 0x2000; // Echo RAM mirrors C000–DDFF
}
