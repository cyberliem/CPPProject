#include "student.h"

student::student(std::string line)
{
    //constructor
    stringstream ss;
    ss << line;
    std::string temp;
    getline(ss, temp, ','); sID=temp;
    getline(ss, temp, ','); name=temp;
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
        score[i]=atoi(temp.c_str());
    }

}

student::~student()
{
    //destructor

    int sum=0;
    for (int i=0; i<4; i++) {
        sum+=student.scores[i]*module.scoreC[i];
    }
    float avg=sum/100;

}

std::string student:toString() {
    std::string res='';
    return(res);
}

float student::calculateAvgScr() {
    float avg=0;
    return(avg)
}

