#ifndef GAMEVALUECRACK_HPP
#define GAMEVALUECRACK_HPP
#include "ValueCrack/gameDataMemory.hpp"
#include "ValueCrack/gameValueMemoryOffset.hpp"
#include "exception"

#include <optional>


using ValueAddrOffset=GameValueMemoryOffset ;

/// @brief Класс для модификации игровых значений
/// 
class GameValueCrack : public GameDataMemory
///Класс реализует 2 основных методов - Получение данных и Запись нового значения
/*
    Порядок вызова методов 
    GetWindow()
    OpenGameProcces()
    GetBaseAddress()
    FindDMAAddy()
    GetModuleBaseAddress()
    
*/
{
public:

    virtual ~GameValueCrack();

    //TODO  Как передавать через шаблон ссылки
    //Проверить передачу указателя
    template <typename TGameValueType>
    std::optional<TGameValueType> ReadGameValue(const LPCVOID valueAddress, TGameValueType* gameValue);

    virtual bool ReadGameValue(ValueAddrOffset &valueMemoryOffset) = 0;

    template <typename TGameValueType>
    bool WriteGameValue(const  LPCVOID valueAddress,  TGameValueType *newValue);

    virtual bool WriteGameValue(ValueAddrOffset &valueMemoryOffset) = 0;


protected:
    DWORD pid =0;
    HWND hwnd;
    HANDLE ghProcces;
    uintptr_t baseAdderess;
    virtual uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets) override;
    virtual uintptr_t GetModuleBaseAddress(DWORD pid, const wchar_t *modName) override;
    /// @brief Метод для получения деструктора приложения по имени
    /// @param nameGame Название игры
    /// @return Возвращает истину при успешном нахождении  
    bool GetWindow(const char * nameGame);
    bool OpenGameProcces();
    void GetBaseAddress(const wchar_t * nameApplication);
};




#endif

