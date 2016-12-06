#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <stdlib.h>
#include <sstream>

class student
{
    public:
        student();
        student(std::string line);
        virtual ~student();
        std::string sID;
        std::string Name;
        std::string mCode;
        std::string atdn[10];
        float atdnPercentage=0;
        float avgScore;
        int scores[4];
        std::string toString();
        void calculateAvgScr(int *coEf);
    protected:


    private:
};

#endif // STUDENT_H
