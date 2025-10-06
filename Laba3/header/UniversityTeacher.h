#ifndef UNIVERSITYTEACHER_H
#define UNIVERSITYTEACHER_H

#include "Human.h"

class UniversityTeacher: virtual public Human {
protected:
    char* position;
    char* academicDegree;
    char* specialty;
    char** scientificWorks;
    int worksCount;
    int worksCapacity;

public:
    UniversityTeacher();
    UniversityTeacher(const char* fName,const char* lName,const char* pat,int year,
                     const char* pos,const char* degree,const char* spec);
    virtual ~UniversityTeacher();

    void display() const override;
    void input() override;

    // Методы для работы с научными трудами
    void addScientificWork(const char* work);
    void removeScientificWork(int index);
    void updateScientificWork(int index,const char* newWork);
    const char* getScientificWork(int index) const;
    int getScientificWorksCount() const { return worksCount; }

    // Геттеры и сеттеры
    const char* getPosition() const { return position; }
    const char* getAcademicDegree() const { return academicDegree; }
    const char* getSpecialty() const { return specialty; }

    void setPosition(const char* pos);
    void setAcademicDegree(const char* degree);
    void setSpecialty(const char* spec);
};

#endif