cmake_minimum_required(VERSION 3.13)
project(NES_emulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(NES_emulator "NES_Emulator/src/main.cpp" "NES_Emulator/src/Bus.cpp" "NES_Emulator/src/Bus.h" "NES_Emulator/src/C6502.cpp" "NES_Emulator/src/C6502.h")