#pragma once
#include "person.hpp"

class Menu {
private:
    Person** people{nullptr};
    int count{0};

public:
    ~Menu();

    void createTeacher();
    void createCommissionMember();
    void createTeacherCommissionMember();
    void showAllPeople() const;
    void addWorkToTeacher();
    void addBioToCommissionMember();
    void addCommissionWorkToTCM();
};
