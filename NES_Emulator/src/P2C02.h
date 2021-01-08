#pragma once

#include <cstdint>
#include <memory>
#include "Cartridge.h"

class P2C02
{
public:
	P2C02();
	~P2C02();

	// Communicate with the Main Bus
	uint8_t cpuRead(uint16_t address, bool readOnly = false);
	void cpuWrite(uint16_t address, uint8_t data);

	// Communicate with PPU bus
	uint8_t ppuRead(uint16_t address, bool readOnly = false);
	void ppuWrite(uint16_t address, uint8_t data);

private:
	std::shared_ptr<Cartridge> cart;

	uint8_t tableName[2][1024]; 
	uint8_t tablePalette[32];
	uint8_t tablePattern[2][4096];


public: // System Interface
	void ConnectCartridge(const std::shared_ptr<Cartridge>& cartridge);
	void clock();

};

