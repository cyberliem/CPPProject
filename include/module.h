#ifndef MODULE_H
#define MODULE_H
#include "miscFunc.h"
#include <string>
#include <stdlib.h>
#include <sstream>
#include <ctype.h>
#include <iostream>


class module
{
    public:
        module();
        module(std::string line);
        std::string Name;
        std::string mCode;
        int coef[4];
        virtual ~module();

    protected:

    private:
};

#endif // MODULE_H
