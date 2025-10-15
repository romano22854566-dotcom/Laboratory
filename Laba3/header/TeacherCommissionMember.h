#ifndef TEACHERCOMMISSIONMEMBER_H
#define TEACHERCOMMISSIONMEMBER_H

#include "UniversityTeacher.h"
#include "CommissionMember.h"

class TeacherCommissionMember: public UniversityTeacher,public CommissionMember {
private:
    char** commissionWorks;
    int commissionWorksCount;
    int commissionWorksCapacity;

    void resizeCommissionWorks();

public:
    TeacherCommissionMember();
    TeacherCommissionMember(const char* fName,const char* lName,const char* pat,int year,
                          const char* pos,const char* degree,const char* spec,
                          const char* commName,int appYear,const char* certNum);
    ~TeacherCommissionMember() override;

    void display() const override;
    void input() override;

    void addCommissionWork(const char* work);
    int getCommissionWorksCount() const { return commissionWorksCount; }
    const char* getCommissionWork(int index) const;
    void updateCommissionWork(int index,const char* newWork);

    // Методы для разрешения неоднозначности
    const char* getFirstName() const { return UniversityTeacher::getFirstName(); }
    const char* getLastName() const { return UniversityTeacher::getLastName(); }
    const char* getPatronymic() const { return UniversityTeacher::getPatronymic(); }
    int getBirthYear() const { return UniversityTeacher::getBirthYear(); }

    void setFirstName(const char* fName) { UniversityTeacher::setFirstName(fName); }
    void setLastName(const char* lName) { UniversityTeacher::setLastName(lName); }
    void setPatronymic(const char* pat) { UniversityTeacher::setPatronymic(pat); }
    void setBirthYear(int year) {
        UniversityTeacher::setBirthYear(year);
        CommissionMember::setBirthYear(year);
    }

    TeacherCommissionMember(const TeacherCommissionMember&) = delete;
    TeacherCommissionMember& operator=(const TeacherCommissionMember&) = delete;
};

#endif