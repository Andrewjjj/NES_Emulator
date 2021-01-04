#include "Cartridge.h"

uint8_t Cartridge::cpuRead(uint16_t address, bool readOnly)
{
    uint8_t data = 0x00;

    switch (address)
    {
    case 0x0000: // Control
        break;
    case 0x0001: // Mask
        break;
    case 0x0002: // Status
        break;
    case 0x0003: // OAM Address
        break;
    case 0x0004: // OAM Data
        break;
    case 0x0005: // Scroll
        break;
    case 0x0006: // PPU Address
        break;
    case 0x0007: // PPU Data
        break;

    }

    return data;
}

void Cartridge::cpuWrite(uint16_t address, uint8_t data)
{
    switch (address)
    {
    case 0x0000: // Control
        break;
    case 0x0001: // Mask
        break;
    case 0x0002: // Status
        break;
    case 0x0003: // OAM Address
        break;
    case 0x0004: // OAM Data
        break;
    case 0x0005: // Scroll
        break;
    case 0x0006: // PPU Address
        break;
    case 0x0007: // PPU Data
        break;

    }
}

uint8_t Cartridge::ppuRead(uint16_t address, bool readOnly)
{ 
    // Do nothing for now
    uint8_t data = 0x00;
    address &= 0x3FFF;
    return data;
}

void Cartridge::ppuWrite(uint16_t address, uint8_t data)
{
    // Mask it in case the ppu decides to write above it's allowable range
    address &= 0x3FFF;
}
