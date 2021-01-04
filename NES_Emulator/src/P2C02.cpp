#include "P2C02.h"

uint8_t P2C02::cpuRead(uint16_t address, bool readOnly)
{
	return uint8_t();
}

void P2C02::cpuWrite(uint16_t address, uint8_t data)
{
}

uint8_t P2C02::ppuRead(uint16_t address, bool readOnly)
{
	return uint8_t();
}

void P2C02::ppuWrite(uint16_t address, uint8_t data)
{
}

void P2C02::ConnectCartridge(const std::shared_ptr<Cartridge>& cartridge)
{
	this->cart = cartridge;
}

void P2C02::clock()
{
}
