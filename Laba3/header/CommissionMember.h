#ifndef COMMISSIONMEMBER_H
#define COMMISSIONMEMBER_H

#include "Human.h"
#include <cstring>

class CommissionMember: virtual public Human {
protected:
    char* commissionName;
    int appointmentYear;
    char* certificateNumber;
    char** autobiography;
    int autobiographyLines = 0;
    int autobiographyCapacity = 5;

    void resizeAutobiography();

public:
    CommissionMember();
    CommissionMember(const char* fName,const char* lName,const char* pat,int year,
                    const char* commName,int appYear,const char* certNum);
    ~CommissionMember() override;

    void display() const override;
    void input() override;

    void addAutobiographyLine(const char* line);
    int getAutobiographyLinesCount() const { return autobiographyLines; }
    const char* getAutobiographyLine(int index) const;
    void updateAutobiographyLine(int index,const char* newLine);

    const char* getCommissionName() const { return commissionName ? commissionName : ""; }
    int getAppointmentYear() const { return appointmentYear; }
    const char* getCertificateNumber() const { return certificateNumber ? certificateNumber : ""; }

    void setCommissionName(const char* commName);
    void setAppointmentYear(int year);
    void setCertificateNumber(const char* certNum);

    CommissionMember(const CommissionMember&) = delete;
    CommissionMember& operator=(const CommissionMember&) = delete;
};

#endif