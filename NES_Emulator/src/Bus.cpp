//
// Created by Andrew Park on 2020-07-03.
//

#include "Bus.h"

Bus::Bus() {

    // Clearing contents in ram
    for (auto &i : cpuRam) i = 0x00;
    cpu.ConnectBus(this);
}

Bus::~Bus() {

}

void Bus::cpuWrite(uint16_t address, uint8_t data) 
{
    // Give cartridge the priority, but unlikely to happen. Why would it interfere with the CPU
    if (cart->cpuWrite(address, data))
    {

    }

    // Check if the address is within the ram memory range
    else if(address >= 0x0000 && address <= 0xFFFF)
    {
        cpuRam[address & 0x07FF] = data;
    }
    else if (address >= 0x2000 && address <= 0x3FFF)
    {
        ppu.cpuWrite(address & 0x0007, data);
    }
}

uint8_t Bus::cpuRead(uint16_t address, bool bReadOnly) 
{
    uint8_t data = 0x00;

    if (cart->cpuRead(address, data)) {

    }

    else if(address >= 0x0000 && address <= 0x1FFF)
    {   
        data = cpuRam[address & 0x07FF];
    }
    else if (address >= 0x2000 && address <= 0x1FFF)
    {
        ppu.cpuRead(address & bReadOnly);
    }
    return data ;
}

void Bus::insertCartridge(const std::shared_ptr<Cartridge>& cartridge)
{
    this->cart = cartridge;
    ppu.ConnectCartridge(cartridge);
}

void Bus::reset()
{
    cpu.reset();
    nSystemClockCounter = 0;
}

void Bus::clock()
{
}
