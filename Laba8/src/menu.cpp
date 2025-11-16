#include "menu.hpp"
#include "Algorithms.hpp"
#include <iostream>
#include <limits>

static int read_int(const char* prompt) {
    std::cout << prompt;
    int v;
    while (!(std::cin >> v)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Ошибка ввода. Повторите: ";
    }
    return v;
}

void showMenu() {
    std::cout << "=== Меню ===\n";
    std::cout << "1. Добавить в начало\n";
    std::cout << "2. Добавить в конец\n";
    std::cout << "3. Сортировать по возрастанию\n";
    std::cout << "4. Сортировать по убыванию\n";
    std::cout << "5. Список\n";
    std::cout << "6. Очистить список\n";
    std::cout << "0. Выход\n";
    std::cout << "Выбор: ";
}

void handleAddFront(ds::SinglyLinkedList& list) {
    int v = read_int("Введите значение: ");
    list.push_front(v);
    std::cout << "Добавлено в начало.\n";
}

void handleAddBack(ds::SinglyLinkedList& list) {
    int v = read_int("Введите значение: ");
    list.push_back(v);
    std::cout << "Добавлено в конец.\n";
}

void handleSortAsc(ds::SinglyLinkedList& list) {
    ds::Algorithms::sort_ascending(list);
    std::cout << "Список отсортирован по возрастанию.\n";
}

void handleSortDesc(ds::SinglyLinkedList& list) {
    ds::Algorithms::sort_descending(list);
    std::cout << "Список отсортирован по убыванию.\n";
}

void handlePrintList(const ds::SinglyLinkedList& list) {
    if (list.empty()) {
        std::cout << "[пусто]\n";
        return;
    }
    std::cout << "Список: ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\nРазмер: " << list.size() << "\n";
}

void handleClearList(ds::SinglyLinkedList& list) {
    list.clear();
    std::cout << "Список очищен.\n";
}
