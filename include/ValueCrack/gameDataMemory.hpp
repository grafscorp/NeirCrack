#ifndef GAMEDATAMEMORY_HPP
#define GAMEDATAMEMORY_HPP


#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <vector>

class GameDataMemory
{
protected:

    virtual uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets) = 0;
    virtual uintptr_t GetModuleBaseAddress(const  DWORD pid, const wchar_t* modName) = 0;
};





#endif