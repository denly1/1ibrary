#include <iostream>
#include <windows.h>
#include "CheckChars.h"

typedef bool (*ContainsAllCharsFunc)(const char*, const char*);

int main() {
    std::string inputString;
    std::string charsToFind;

    std::cout << "Введите строку: ";
    std::getline(std::cin, inputString);

    std::cout << "Введите что в ней искать: ";
    std::getline(std::cin, charsToFind);

    HMODULE hModule = LoadLibrary(TEXT("CheckChars.dll"));
    if (!hModule) {
        std::cerr << "Не удалось загрузить библиотеку." << std::endl;
        return 1;
    }

    ContainsAllCharsFunc containsAllChars = (ContainsAllCharsFunc)GetProcAddress(hModule, "containsAllChars");
    if (!containsAllChars) {
        std::cerr << "Не удалось найти функцию." << std::endl;
        FreeLibrary(hModule);
        return 1;
    }

    bool result = containsAllChars(inputString.c_str(), charsToFind.c_str());

    std::cout << "Содержит ли строка \"" << inputString << "\" символы \"" << charsToFind << "\"? ";
    std::cout << (result ? "Да!" : "Нет!") << std::endl;

    FreeLibrary(hModule);
    return 0;
}
