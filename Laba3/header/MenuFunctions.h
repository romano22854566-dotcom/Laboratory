#ifndef MENUFUNCTIONS_H
#define MENUFUNCTIONS_H

#include "UniversityTeacher.h"
#include "CommissionMember.h"
#include "TeacherCommissionMember.h"

void displayMenu();
void createUniversityTeacher(Human**& people,int& peopleCount,int& capacity);
void createCommissionMember(Human**& people,int& peopleCount,int& capacity);
void createTeacherCommissionMember(Human**& people,int& peopleCount,int& capacity);
void displayAllPeople(Human** people,int peopleCount);
void addScientificWork(Human** people,int peopleCount);
void addAutobiographyLine(Human** people,int peopleCount);
void addCommissionWork(Human** people,int peopleCount);
void cleanup(Human** people,int peopleCount);

#endif