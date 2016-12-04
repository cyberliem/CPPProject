#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <stdlib.h>

class student
{
    public:
        student(std::string line);
        virtual ~student();
        std::string sID;
        std::string Name;
        std::string mCode;
        std::string atdn[10];
        float atdnPercentage=0;
        int scores[4];
        std::string tostring();
    protected:


    private:
};

#endif // STUDENT_H
