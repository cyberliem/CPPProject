#include "student.h"

student::student()
{
}

student::student(std::string line)
{
    //constructor
    std::stringstream ss;
    ss << line;
    std::string temp;
    getline(ss, temp, ','); sID=temp;
    getline(ss, temp, ','); Name=temp;
    getline(ss, temp, ','); mCode=temp;
    for (int i=0; i<10; i++) {
        getline(ss, temp, ',');
        atdn[i]=temp;
        if (temp.compare("yes")==0) {
            atdnPercentage+=10.0;
        }
    }

    for (int i=0; i<4; i++) {
        getline(ss, temp, ',');
        scores[i]=atoi(temp.c_str());
    }

}


student::~student()
{
    //destructor

}

std::string student::toString() {
    std::ostringstream oss;
    std::string res;
    oss<< sID<<', ';
    oss<< Name<<', ';
    oss<< mCode;
    res=oss.str();
    return(res);
}

void student::calculateAvgScr(int *coEf) {
    int baseCoef[4]={50,60,20,100};
    float avg=0;
    float sum=0;
    for (int i=0; i<4; i++) {
        sum+=((scores[i]/baseCoef[i])*100)*coEf[i];
    }
    avgScore=sum/100;

}

