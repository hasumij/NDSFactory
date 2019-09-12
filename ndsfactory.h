#ifndef NDSFACTORY_H
#define NDSFACTORY_H

#include <string>
#include <vector>
#include <cstdint>
#include "ndsheader.h"



class NDSFactory
{
public:
    NDSFactory();
    bool loadRomHeader(const std::string& romPath, std::vector<char>& header);
    bool dumpDataFromFile(const std::string& romPath, const std::string& savePath, uint32_t startAddr, uint32_t size);
    bool readBytesFromFile(std::vector<char>& byteBuffer, const std::string& romPath, uint32_t startAddr, uint32_t size);
    bool writeSectionToFile(const std::string& sectionPath, const std::string& savePath, uint32_t startAddr, uint32_t size);
    bool writeBytesToFile(std::vector<char>& byteBuffer, const std::string& savePath, uint32_t startAddr, uint32_t size);
    bool writePaddingToFile(char paddingChar, const std::string& savePath, uint32_t startAddr, uint32_t size);
    int getCardSizeInBytes(int cardType);
    bool checkArm9FooterPresence(const std::string& sectionPath, uint32_t size);
    bool patchFat(const std::string& sectionPath, uint32_t shiftSize, const std::string& savePath);

private:

};

#endif // NDSFACTORY_H
