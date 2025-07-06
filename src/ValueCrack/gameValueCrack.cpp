#include "ValueCrack/gameValueCrack.hpp"

bool GameValueCrack::GetWindow(const char * nameGame)
{
    this->hwnd = FindWindow(nullptr,nameGame);
    return (!hwnd)?false:true;
}

bool GameValueCrack::OpenGameProcces()
{
    if (!hwnd) throw std::runtime_error("Error. HWND is undefined.");
    GetWindowThreadProcessId(this->hwnd,&this->pid);
    this->ghProcces = OpenProcess(PROCESS_ALL_ACCESS,FALSE, this->pid);
    return (!this->ghProcces)? false: true;
}

void  GameValueCrack::GetBaseAddress(const wchar_t *nameApplication)
{
    this->baseAdderess = GetModuleBaseAddress(this->pid, nameApplication);
    if(!baseAdderess)
    {
        CloseHandle(this->ghProcces);
        ghProcces = nullptr;
        throw std::runtime_error("Error. Cant get game base address.");
    }

}

uintptr_t GameValueCrack::FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets)
{
    uintptr_t addr = ptr;
    for (unsigned int i = 0; i < offsets.size(); ++i) {
        ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
        addr += offsets[i];
    }
    return addr;
}

uintptr_t GameValueCrack::GetModuleBaseAddress(const  DWORD pid, const wchar_t *modName)
{
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid);
    if (hSnapshot == INVALID_HANDLE_VALUE) return 0;

    MODULEENTRY32W modEntry;
    modEntry.dwSize = sizeof(modEntry);

    if (!Module32FirstW(hSnapshot, &modEntry)) {
        CloseHandle(hSnapshot);
        return 0;
    }

    uintptr_t result = 0;
    do {
        if (_wcsicmp(modEntry.szModule, modName) == 0) {
            result = (uintptr_t)modEntry.modBaseAddr;
            break;
        }
    } while (Module32NextW(hSnapshot, &modEntry));

    CloseHandle(hSnapshot);
    return result;
}

GameValueCrack::~GameValueCrack() {
    if(this->ghProcces){ CloseHandle(this->ghProcces); this->ghProcces = nullptr;}
}


template <typename TGameValueType>
std::optional<TGameValueType> GameValueCrack::ReadGameValue(const  LPCVOID valueAddress, TGameValueType* gameValue)
{
    if(!ghProcces) throw std::runtime_error("Game procces is undefine.");
    if(ReadProcessMemory(this->ghProcces, valueAddress, gameValue, sizeof(*gameValue),0)){
        #ifdef DEFINE
        std::cout << "Read value : "<<*gameValue << std::endl;
        #endif
        return *gameValue;
    }
    return std::nullopt;   
    //TODO Добавить optional

}

template <typename TGameValueType>
bool GameValueCrack::WriteGameValue(const  LPCVOID valueAddress,  TGameValueType* newValue)
{
    if(!ghProcces) throw std::runtime_error("Game procces is undefine.");
    if(newValue == nullptr) throw std::runtime_error("New value couldnt be null.");
    if(WriteProcessMemory(this->ghProcces,valueAddress, newValue, sizeof(*newValue), 0))
    {
        #ifdef DEFINE
        std::cout << "Write value : "<<*newValue << std::endl;
        #endif
        return true;
    }
    return false;
}