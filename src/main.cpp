#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>
#include <iostream>
#include <vector>
#include "memory/DMGMemory.hpp"

int main() {
    DMGMemory memory;

    // Create a fake ROM: 16 bytes with values 0x00, 0x01, ..., 0x0F
    std::vector<DMGMemory::Byte> fakeROM(16);
    for (int i = 0; i < 16; ++i) {
        fakeROM[i] = static_cast<DMGMemory::Byte>(i);
    }

    // Load the ROM into memory starting at 0x0000
    memory.loadROM(fakeROM);

    // Read back ROM bytes and print
    std::cout << "ROM bytes at 0x0000-0x000F:\n";
    for (int addr = 0; addr < 16; ++addr) {
        std::cout << "0x" << std::hex << addr << ": 0x"
                  << std::hex << static_cast<int>(memory.read(addr)) << "\n";
    }

    // Test writing to RAM and reading it back
    memory.write(0xC000, 0x42);
    std::cout << "RAM test at 0xC000: 0x"
              << std::hex << static_cast<int>(memory.read(0xC000)) << "\n";

    // Test echo RAM mirroring (0xE000 mirrors 0xC000)
    std::cout << "Echo RAM test at 0xE000 (should mirror 0xC000): 0x"
              << std::hex << static_cast<int>(memory.read(0xE000)) << "\n";

    return 0;
}