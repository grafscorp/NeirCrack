#ifndef GAMEVALUECRACK_HPP
#define GAMEVALUECRACK_HPP
#include "gameDataMemory.hpp"
#include "exception"

#include <optional>

struct GameValueMemoryOffset{
    GameValueMemoryOffset(const uintptr_t _staticOffset,const std::vector<unsigned int> _offsets) noexcept :staticOffset(_staticOffset),offsets(_offsets)
     {}
    GameValueMemoryOffset(const uintptr_t _staticOffset,const std::vector<unsigned int> _offsets,  char * _name)noexcept :staticOffset(_staticOffset),offsets(_offsets),nameGameValue(_name)
    {}
    uintptr_t getGameValueAddress() noexcept{return this->gameValueAddress;}
    void setGameValueAddress(uintptr_t gameAddress) noexcept{
        this->gameValueAddress = gameAddress + this->staticOffset;
    }
private:
    uintptr_t staticOffset;
    std::vector<unsigned int> offsets={0};
    uintptr_t gameValueAddress;
    char * nameGameValue;

};



#endif

