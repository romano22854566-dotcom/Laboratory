#ifndef TEACHERCOMMISSIONMEMBER_H
#define TEACHERCOMMISSIONMEMBER_H

#include "UniversityTeacher.h"
#include "CommissionMember.h"

class TeacherCommissionMember: public UniversityTeacher,public CommissionMember {
private:
    char** commissionWorks;
    int commissionWorksCount = 0;
    int commissionWorksCapacity = 5;

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

    using CommissionMember::setCommissionName;
    using CommissionMember::setAppointmentYear;
    using CommissionMember::setCertificateNumber;

    TeacherCommissionMember(const TeacherCommissionMember&) = delete;
    TeacherCommissionMember& operator=(const TeacherCommissionMember&) = delete;
};

#endif