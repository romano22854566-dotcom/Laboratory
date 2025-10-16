#ifndef UNIVERSITYTEACHER_H
#define UNIVERSITYTEACHER_H

#include "Human.h"

class UniversityTeacher: virtual public Human {
private:
    char* position;
    char* academicDegree;
    char* specialty;
    char** scientificWorks;
    int worksCount;
    int worksCapacity;

    void resizeWorks();

public:
    UniversityTeacher();
    UniversityTeacher(const char* fName,const char* lName,const char* pat,int year,
                     const char* pos,const char* degree,const char* spec);
    ~UniversityTeacher() override;

    void display() const override;
    void input() override;

    void addScientificWork(const char* work);
    int getScientificWorksCount() const;
    const char* getScientificWork(int index) const;
    void updateScientificWork(int index,const char* newWork);

    const char* getPosition() const;
    const char* getAcademicDegree() const;
    const char* getSpecialty() const;

    void setPosition(const char* pos);
    void setAcademicDegree(const char* degree);
    void setSpecialty(const char* spec);

    UniversityTeacher(const UniversityTeacher&) = delete;
    UniversityTeacher& operator=(const UniversityTeacher&) = delete;
};

#endif