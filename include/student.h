#ifndef STUDENT_H
#define STUDENT_H
#include "miscFunc.h"
#include "module.h"
#include <string>
#include <stdlib.h>
#include <sstream>
#include <ctype.h>
#include <iostream>

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
        int moduleIndex;
        void setMIndex(module (&modules)[100], int nModule);
        std::string toString();
        void calculateAvgScr(int *coEf);
    protected:


    private:
};


#endif // STUDENT_H


