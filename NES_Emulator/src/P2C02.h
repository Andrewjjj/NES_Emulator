#pragma once

#include <cstdint>
#include <memory>
#include "Cartridge.h"

class P2C02
{
public:
	P2C02();
	~P2C02();

	uint8_t cpuRead(uint16_t address, bool readOnly = false);
	void cpuWrite(uint16_t address, uint8_t data);

	uint8_t ppuRead(uint16_t address, bool readOnly = false);
	void ppuWrite(uint16_t address, uint8_t data);

private:
	std::shared_ptr<Cartridge> cart;

public: // System Interface
	void ConnectCartridge(const std::shared_ptr<Cartridge>& cartridge);
	void clock();

};

