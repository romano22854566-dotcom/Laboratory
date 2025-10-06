#ifndef COMMISSIONMEMBER_H
#define COMMISSIONMEMBER_H

#include "Human.h"

class CommissionMember: virtual public Human {
protected:
    char* commissionName;
    int appointmentYear;
    char* certificateNumber;
    char** autobiography;
    int autobiographyLines;
    int autobiographyCapacity;

public:
    CommissionMember();
    CommissionMember(const char* fName,const char* lName,const char* pat,int year,
                    const char* commName,int appYear,const char* certNum);
    virtual ~CommissionMember();

    void display() const override;
    void input() override;

    // Методы для работы с автобиографией
    void addAutobiographyLine(const char* line);
    void removeAutobiographyLine(int index);
    void updateAutobiographyLine(int index,const char* newLine);
    const char* getAutobiographyLine(int index) const;
    int getAutobiographyLinesCount() const { return autobiographyLines; }

    // Геттеры и сеттеры
    const char* getCommissionName() const { return commissionName; }
    int getAppointmentYear() const { return appointmentYear; }
    const char* getCertificateNumber() const { return certificateNumber; }

    void setCommissionName(const char* commName);
    void setAppointmentYear(int year);
    void setCertificateNumber(const char* certNum);
};

#endif