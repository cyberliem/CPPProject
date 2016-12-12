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
    getline(ss, temp, ','); sID=trimStr(temp);
    getline(ss, temp, ','); Name=trimStr(temp);
    getline(ss, temp, ','); mCode=trimStr(temp);
    for (int i=0; i<10; i++) {
        getline(ss, temp, ',');
        temp=trimStr(temp);
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
        //sum=scores[i]/baseCoef[i])
        sum+=(float(scores[i])/float(baseCoef[i])*100)*coEf[i];

    }
    avgScore=sum/100;
}

void student::setMIndex(module (&modules)[100], int nModule) {

    for (int i=0; i<nModule; i++) {
        std::size_t lookUp = mCode.find(modules[i].mCode);
        if (lookUp!=std::string::npos){
            moduleIndex=i;
            return;
        }
    }
}


