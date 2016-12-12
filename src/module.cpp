#include "module.h"

module::module()
{
    //ctor
}

module::module(std::string line)
{
    //constructor
    std::stringstream ss;
    ss << line;
    std::string temp;
    getline(ss, temp, ','); mCode=trimStr(temp);
    getline(ss, temp, ','); Name=trimStr(temp);
    for (int i=0; i<4; i++) {
        getline(ss, temp, ',');
        coef[i]=atoi(trimStr(temp).c_str());
    }

}



module::~module()
{
    //dtor
}
