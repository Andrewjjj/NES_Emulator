#include "P2C02.h"



P2C02::P2C02()
{
}

P2C02::~P2C02()
{
}

uint8_t P2C02::cpuRead(uint16_t address, bool readOnly)
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

	return uint8_t();
}

void P2C02::cpuWrite(uint16_t address, uint8_t data)
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

uint8_t P2C02::ppuRead(uint16_t address, bool readOnly)
{
	uint8_t data = 0x00;
	address &= 0x3FFF;

	if (cart->ppuRead(address, data))
	{

	}
	return data;
}

void P2C02::ppuWrite(uint16_t address, uint8_t data)
{
	address &= 0x3FFF;
	if (cart->ppuWrite(address, data))
	{

	}
}

void P2C02::ConnectCartridge(const std::shared_ptr<Cartridge>& cartridge)
{
	this->cart = cartridge;
}

void P2C02::clock()
{
}
