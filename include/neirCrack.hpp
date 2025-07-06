#ifndef NEIRCRACK_HPP
#define NEIRCRACK_HPP

#include "gameValueCrack.hpp"


class NeirCrack : public GameValueCrack
{
    NeirCrack();
    ~NeirCrack();
    virtual bool WriteGameValue(ValueAddrOffset &newValue) override;
    virtual bool ReadGameValue(ValueAddrOffset& newValue) override;
};


#endif