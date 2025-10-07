#include "Human.h"

char* Human::safeCopy(const char* source) {
    // Если source равен nullptr или пустая строка
    if (source == nullptr) {
        char* empty = new char[1];
        empty[0] = '\0';
        return empty;
    }

    // Если пустая строка
    if (std::strlen(source) == 0) {
        char* empty = new char[1];
        empty[0] = '\0';
        return empty;
    }

    // Вычисляем длину строки
    size_t len = 0;
    while (source[len] != '\0') {
        len++;
    }

    // Выделяем память для новой строки
    char* dest = new char[len + 1];

    // Копируем символы вручную
    for (size_t i = 0; i < len; i++) {
        dest[i] = source[i];
    }

    // Добавляем нулевой терминатор
    dest[len] = '\0';

    return dest;
}

Human::Human():
    firstName(safeCopy("")),
    lastName(safeCopy("")),
    patronymic(safeCopy("")),
    birthYear(0) {
}

Human::Human(const char* fName,const char* lName,const char* pat,int year):
    birthYear(year) {
    firstName = safeCopy(fName);
    lastName = safeCopy(lName);
    patronymic = safeCopy(pat);
}

Human::~Human() {
    delete[] firstName;
    delete[] lastName;
    delete[] patronymic;
}

void Human::setFirstName(const char* fName) {
    delete[] firstName;
    firstName = safeCopy(fName);
}

void Human::setLastName(const char* lName) {
    delete[] lastName;
    lastName = safeCopy(lName);
}

void Human::setPatronymic(const char* pat) {
    delete[] patronymic;
    patronymic = safeCopy(pat);
}

void Human::setBirthYear(int year) {
    birthYear = year;
}