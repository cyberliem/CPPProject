#include "miscFunc.h"

std::string trimStr(std::string totrim){
    std::string temp;

    while (isspace(totrim[0])){
        temp=totrim.substr(1,totrim.length());
        totrim=temp;

    }
    while (isspace(totrim[(totrim.length()-1)])){

        temp=totrim.substr(0,totrim.length()-2);
        totrim=temp;
    }
    return(totrim);
}


