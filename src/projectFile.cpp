#include "projectFile.h"

projectFile::projectFile()
{
    //constructor for infile;
    std::cout << "Please enter a file name";
    std::getline(std::cin, fileName);
    file.open(fileName.c_str(), std::ios::in);
    fileStatus=file.is_open();
}

projectFile::projectFile(int truncMode, std::string oFileName);
{
    /*constructor for out file
     *parameter: int truncMode: 1 if the file is to be overwritten
                                0 if the file is to be appended.
                 string oFileName: the filename Desired
     */
    fileName=oFileName;
    if (truncMode==1) {
        file.open(fileName.c_str(),std::ios:out | std::ios::trunc)
    }
    else {
        file.open(fileName.c_str(),std::ios::out)
    }
    fileStatus=file.is_open();
}

projectFile::~projectFile()
{
    //destructor
    file.close();
}
