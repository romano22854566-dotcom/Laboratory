#pragma once
#ifndef MENUFUNCTIONS_H
#define MENUFUNCTIONS_H

#include "UniversityTeacher.h"
#include "CommissionMember.h"
#include "TeacherCommissionMember.h"

void displayMenu();
void initializePeople(Human**& people,int& capacity);
void cleanup(Human** people,int peopleCount);
void createUniversityTeacher(Human**& people,int& peopleCount,int& capacity);
void createCommissionMember(Human**& people,int& peopleCount,int& capacity);
void createTeacherCommissionMember(Human**& people,int& peopleCount,int& capacity);
void displayAllPeople(Human** people,int peopleCount);

#endif