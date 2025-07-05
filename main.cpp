



#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <vector>


int main() {
    // Получаем PID
    DWORD pid = 0;
    HWND hwnd = FindWindowW(nullptr, L"NieR:Automata");
    if (!hwnd) {
        std::cerr << "Game window not found!" << std::endl;
        return 1;
    }
    GetWindowThreadProcessId(hwnd, &pid);

    // Открываем процесс
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (!hProcess) {
        std::cerr << "OpenProcess failed. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // Получаем базовый адрес
    uintptr_t baseAddress = GetModuleBaseAddress(pid, L"NieRAutomataCompat.exe");
    if (!baseAddress) {
        std::cerr << "Module not found!" << std::endl;
        CloseHandle(hProcess);
        return 1;
    }

    // Статическое смещение из PointerScan (пример)
    uintptr_t staticOffset = 0x00F15D60; // Замените на ваше значение!
    
    // Смещения (в вашем случае {0})
    std::vector<unsigned int> offsets = {0};

    // Рассчитываем адрес денег
    uintptr_t moneyAddress = baseAddress + staticOffset;
    moneyAddress = FindDMAAddy(hProcess, moneyAddress, offsets);

    // Работа с деньгами
    int currentMoney = 0;
    while (true) {
        // Читаем текущее значение
        if (ReadProcessMemory(hProcess, (LPCVOID)moneyAddress, &currentMoney, sizeof(currentMoney), 0)) {
            std::cout << "Current money: " << currentMoney << std::endl;
        }

        // Устанавливаем новое значение (например, 99999)
        int newMoney = 99999;
        if (WriteProcessMemory(hProcess, (LPVOID)moneyAddress, &newMoney, sizeof(newMoney), 0)) {
            std::cout << "Money set to: " << newMoney << std::endl;
        }

        Sleep(5000); // Обновляем каждые 5 секунд
    }

    CloseHandle(hProcess);
    return 0;
}