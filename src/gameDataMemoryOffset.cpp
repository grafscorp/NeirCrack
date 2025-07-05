#include "ValueCrack/gameValueMemoryOffset.hpp"
#include "gameValueMemoryOffset.hpp"


GameValueMemoryOffset::GameValueMemoryOffset(const uintptr_t _staticOffset, const std::vector<unsigned int> _offsets) noexcept:staticOffset(_staticOffset),offsets(_offsets)
{}


GameValueMemoryOffset::GameValueMemoryOffset(const uintptr_t _staticOffset, const std::vector<unsigned int> _offsets, char *_name) noexcept:staticOffset(_staticOffset),offsets(_offsets),nameGameValue(_name)
{}

void GameValueMemoryOffset::setGameValueAddress(uintptr_t gameAddress) noexcept
{
        this->gameValueAddress =  gameAddress + this->staticOffset;
}
