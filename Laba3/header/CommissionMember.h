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

    void addAutobiographyLine(const char* line);
    int getAutobiographyLinesCount() const { return autobiographyLines; }
    const char* getAutobiographyLine(int index) const;
    void updateAutobiographyLine(int index,const char* newLine);
private:
    CommissionMember(const CommissionMember&) = delete;
    CommissionMember& operator=(const CommissionMember&) = delete;
};

#endif