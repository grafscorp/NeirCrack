#ifndef NEIRCRACK_HPP
#define NEIRCRACK_HPP

#include "ValueCrack/gameValueCrack.hpp"


class NeirCrack : public GameValueCrack
{
    NeirCrack();
    ~NeirCrack();
    virtual bool WriteGameValue(ValueAddrOffset &newValue) override;
    virtual bool ReadGameValue(ValueAddrOffset& newValue) override;
private:
    char * nameGame = "NeiR:Automata";
    char *nameApp = "NieRAutomataCompat.exe";
};


#endif