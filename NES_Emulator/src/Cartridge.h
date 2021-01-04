#pragma once

#include <cstdint>

class Cartridge
{
public:
	Cartridge();
	~Cartridge();

	uint8_t cpuRead(uint16_t address, bool readOnly = false);
	void cpuWrite(uint16_t address, uint8_t data);

	uint8_t ppuRead(uint16_t address, bool readOnly = false);
	void ppuWrite(uint16_t address, uint8_t data);

};

