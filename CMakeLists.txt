cmake_minimum_required(VERSION 3.10)
project(gameboy_emulator)

set(CMAKE_CXX_STANDARD 17)

# SDL2 include and library paths
include_directories("D:/Libraries/SDL2-2.32.6/x86_64-w64-mingw32/include")
link_directories("D:/Libraries/SDL2-2.32.6/x86_64-w64-mingw32/lib")

# Add your source file
add_executable(gameboy_emulator src/main.cpp
        src/memory/Memory.hpp
        src/memory/DMGMemory.hpp
        src/memory/DMGMemory.cpp
        src/memory/Memory.cpp)

# Link against SDL2
target_link_libraries(gameboy_emulator SDL2main SDL2)
