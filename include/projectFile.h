#ifndef PROJECTFILE_H
#define PROJECTFILE_H
#include <fstream>
#include <stdlib.h>
#include <iostream>
class projectFile
{
    public:
        //constructor for inFile
        projectFile();
        //constructor for outFile with file name and trunc mode
        projectFile(int truncMode, std::string oFileName);

        //destructor
        virtual ~projectFile();

        std::fstream file;
        std::string fileName;
        bool fileStatus;

    protected:


    private:

};

#endif // PROJECTFILE_H

