#include "Menu.hpp"
#include<locale.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0,"rus");
    Menu::run();
    return 0;
}