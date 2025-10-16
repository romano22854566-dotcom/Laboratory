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
    int getCommissionWorksCount() const;
    const char* getCommissionWork(int index) const;
    void updateCommissionWork(int index,const char* newWork);

    // ������ ��� ���������� ���������������
    const char* getFirstName() const;
    const char* getLastName() const;
    const char* getPatronymic() const;
    int getBirthYear() const;

    void setFirstName(const char* fName);
    void setLastName(const char* lName);
    void setPatronymic(const char* pat);
    void setBirthYear(int year);

    TeacherCommissionMember(const TeacherCommissionMember&) = delete;
    TeacherCommissionMember& operator=(const TeacherCommissionMember&) = delete;
};

#endif