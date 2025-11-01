#include "Menu.hpp"
#include<locale.h>
#include<windows.h>
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0,"rus");
    Menu::run();
    return 0;
}