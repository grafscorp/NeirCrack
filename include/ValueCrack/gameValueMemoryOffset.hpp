#ifndef GAMEVALUEMEMORYOFFSET_HPP
#define GAMEVALUEMEMORYOFFSET_HPP

#include <vector>


struct GameValueMemoryOffset{
    GameValueMemoryOffset(const uintptr_t _staticOffset,const std::vector<unsigned int> _offsets) noexcept;
    GameValueMemoryOffset(const uintptr_t _staticOffset,const std::vector<unsigned int> _offsets,  char * _name)noexcept;
    uintptr_t getGameValueAddress() noexcept{return this->gameValueAddress;}
    void setGameValueAddress(uintptr_t gameAddress) noexcept;

private:
    uintptr_t staticOffset;
    std::vector<unsigned int> offsets={0};
    uintptr_t gameValueAddress;
    char * nameGameValue;

};

#endif