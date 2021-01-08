#include "Cartridge.h"

Cartridge::Cartridge(const std::string& sFileName)
{
    struct sHeader
    {
        char name[4];
        uint8_t prg_rom_chunks;
        uint8_t chr_rom_chunks;
        uint8_t mapper1;
        uint8_t mapper2;
        uint8_t prg_ram_size;
        uint8_t tv_system1;
        uint8_t tv_system2;
        char unused[5];
    } header;

    std::ifstream ifs;
    ifs.open(sFileName, std::ifstream::binary);
    if (ifs.is_open()) 
    {
        ifs.read((char*)&header, sizeof(sHeader));

        if (header.mapper1 & 0x04)
            ifs.seekg(512, std::ios_base::cur);

        // Determine the mapper ID
        nMapperID = ((header.mapper2 >> 4) << 4) | (header.mapper1 >> 4);

        uint8_t nFileType = 1;

        if (nFileType == 0)
        {

        }

        if (nFileType == 1)
        {
            nPRGBanks = header.prg_rom_chunks;
            vPRGMemory.resize(nPRGBanks * 16384);
            ifs.read((char*)vPRGMemory.data(), vPRGMemory.size());

            nCHRBanks = header.chr_rom_chunks;
            vCHRMemory.resize(nCHRBanks * 8192);
            ifs.read((char*)vCHRMemory.data(), vCHRMemory.size());
        }

        ifs.close();
    }
}

Cartridge::~Cartridge()
{
}

bool Cartridge::cpuRead(uint16_t address, uint8_t &data)
{
    return false;
}

bool Cartridge::cpuWrite(uint16_t address, uint8_t data)
{
    return false;
}

bool Cartridge::ppuRead(uint16_t address, uint8_t &data)
{ 
    // Do nothing for now
    return false;
}

bool Cartridge::ppuWrite(uint16_t address, uint8_t data)
{
    // Mask it in case the ppu decides to write above it's allowable range
    return false;
}
