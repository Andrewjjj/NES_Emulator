//
// Created by Andrew Park on 2020-07-03.
//
#pragma once

#ifndef NES_EMULATOR_BUS_H
#define NES_EMULATOR_BUS_H

#include <cstdint>
#include "C6502.h"
#include "P2C02.h"
#include "Cartridge.h"
#include <vector>

class Bus {

public:
    Bus();
    ~Bus();

public: // Sets up the devices for bus
    C6502 cpu;

    P2C02 ppu;

    std::vector<uint8_t> cpuRam = std::vector<uint8_t>(2048, 0);

    std::shared_ptr<Cartridge> cart;

public: //Bus Read & Write
    void cpuWrite(uint16_t address, uint8_t data);
    uint8_t cpuRead(uint16_t address, bool bReadOnly = false);

public: // System Interface
    void insertCartridge(const std::shared_ptr<Cartridge>& cartridge);
    void reset();
    void clock();

private:
    uint32_t nSystemClockCounter = 0; // Count of how many clock cycle has passed.
};


#endif //NES_EMULATOR_BUS_H
