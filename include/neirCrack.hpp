#ifndef NEIRCRACK_HPP
#define NEIRCRACK_HPP

#include "gameValueCrack.hpp"


class NeirCrack : public GameValueCrack
{
    NeirCrack();
    ~NeirCrack();
    bool WriteValue(GameValueMemoryOffset &newValue);
    bool ReadValue(GameValueMemoryOffset& newValue);
};


#endif