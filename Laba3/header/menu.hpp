#pragma once
#include "person.hpp"

class Menu {
private:
    Person** people;
    int count;

public:
    Menu();
    ~Menu();
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;

    Menu(Menu&&) noexcept = default;
    Menu& operator=(Menu&&) noexcept = default;

    void createTeacher();
    void createCommissionMember();
    void createTeacherCommissionMember();
    void showAllPeople() const;
    void addWorkToTeacher();
    void addBioToCommissionMember();
    void addCommissionWorkToTCM();
};
