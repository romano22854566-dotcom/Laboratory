#ifndef UNIVERSITYTEACHER_H
#define UNIVERSITYTEACHER_H

#include "Human.h"
#include <cstring>  // Добавлено

class UniversityTeacher: virtual public Human {
protected:
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
    virtual ~UniversityTeacher();

    void display() const override;
    void input() override;

    void addScientificWork(const char* work);
    int getScientificWorksCount() const { return worksCount; }
    const char* getScientificWork(int index) const;
    void updateScientificWork(int index,const char* newWork);

    const char* getPosition() const { return position ? position : ""; }
    const char* getAcademicDegree() const { return academicDegree ? academicDegree : ""; }
    const char* getSpecialty() const { return specialty ? specialty : ""; }

    void setPosition(const char* pos);
    void setAcademicDegree(const char* degree);
    void setSpecialty(const char* spec);

private:
    UniversityTeacher(const UniversityTeacher&) = delete;
    UniversityTeacher& operator=(const UniversityTeacher&) = delete;
};

#endif