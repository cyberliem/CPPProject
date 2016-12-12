#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <math.h>
#include "projectFile.h"
#include "module.h"
#include "student.h"
#include "miscFunc.h"

int nStudent=0;
int nModule=0;

projectFile * inputRequest(std::string message){
    static projectFile *sInFile;
    do
    {   //system("cls");
        std::cout <<message<< std::endl;
        delete sInFile;
        sInFile=new projectFile();
        if (!sInFile->fileStatus) {
            std::cout <<"There was error opening the file \n";
            std::cout <<"Please retry";
            //system("pause");
        }
    } while (!sInFile->fileStatus);
   return(sInFile);
}

void attemptOpenFile() {
    //creating an object of project file will invoke the constructor
    //which will require user input and call file open.
    projectFile sInFile;
    if (sInFile.fileStatus) {
        std::cout <<"The file has been open successfully \n";
    }
    else {
        std::cout <<"There was error opening the file \n";
    }
    //destruct files
}

void validateInput() {
    /*first there must be an input file object
    sInFile=inputRequest("get student record file name.... \n");

    //create error file and correct file object
    errFile= projectFile(1,"errFile.csv");
    corFile= projectFile(1,"corFile.csv");

    //create validator object.
    validatorClass validator;

    //loop line by line, validate and put the line to output files accordingly
    while (!eof(sInFile)) {

        //create array object from the line of sInfile.
        tokens=tokenArray(sInFile);

        //call validate method to get result.
        //put to correct file if the result is true
        //put to error file if the result is false.
        if (validator.validate(tokens)) {
            corFile << tokens.toString();
        }
        else {
            errFile << tokens.toString();
        }
    }

    //notify user.
    std::cout <<"The valid records are now in corFile.csv \n";
    std::cout <<"The invalid records are now in errFile.csv \n";
    //destruct all the object.
    destruct(validator);    destruct(errFile);    destruct(corFile);  destruct(tokens);
    */
}

void readModule(module (&modules)[100]) {
    //first there must be an input file object
    nModule=0;
    projectFile *sInFile;
    std::string line;
    sInFile=inputRequest("\n Get Module record file name.... \n");
    while (std::getline(sInFile->file,line)) {
        //create array object from the line of sInfile.
        modules[nModule]=module(line);

        nModule++;
    }
}

void displayModules(module modules[1000]) {
    std::cout<<"The modules read from files are: ";
    for (int i=0; i<nModule; i++) {
        std::cout<<modules[i].mCode<<" "<<modules[i].Name<<"\n";
    }
}

void readStudent(student (&students)[1000]) {
    //first there must be an input file object
    nStudent=0;
    projectFile *sInFile;
    sInFile=inputRequest("\n Get valid Student record file name.... \n");
    std::string line;
    while (std::getline(sInFile->file,line)) {
        //create array object from the line of sInfile.
        students[nStudent]=student(line);
        nStudent++;
    }
}

void displayAttendance(student students[1000]) {
    std::cout<< std::setprecision( 2 );
    for (int i=0; i<nStudent; i++) {

        std::cout <<"student name:"<<students[i].Name<<" module code "<<students[i].mCode<<"\n"<<"   Attendance "<< students[i].atdnPercentage << "%"
                <<" Average score:"<<students[i].avgScore<<"%\n";
    }
}

void checkDuplicate(student students[1000]) {
    bool control[nStudent];
    int currentDup[nStudent];
    bool thereisDup=false;
    int nDup=0;
    int i; int j;
    for (i=0; i<nStudent; i++) {
        control[i]=true;
    }

    for (i=0; i<nStudent-1; i++) {
        if (control[i]) {
            nDup=0;
            currentDup[0]=i;
            for (j=i+1; j<nStudent; j++)
                if ((students[i].sID.compare(students[j].sID)==0) && ((students[i].mCode.compare(students[j].mCode)==0))) {
                    nDup++;
                    currentDup[nDup]=j;
                    control[j]=false;
                }
            if (nDup>0) {
                thereisDup=true;
                for (int l=0; l<nDup; l++) {
                    std::cout <<students[currentDup[l]].toString() << std::endl;
                }
                std::cout<< std::endl;
            }
        }

    }
    if (thereisDup) {
        std::cout <<"The records above are duplicated, please check \n";
    }
    else {
        std::cout <<"There is no duplicate in the records \n";
    }
}

int getXpercent(){
    int x;
    std::string input;
    while (true) {
    //system("cls");
    std::cout << "Please choose the cut-off percentage desired";
    std::getline(std::cin, input);
    std::stringstream convertStream(input);
        if (convertStream>> x) {
            return(ceil(nStudent*x/100));
        }
        else {
            std::cout << "invalid input, please try again \n";
            //system("pause");
        }
    }
}

void displayLowest(student students[1000]) {
   /* students.sort();
    int xpercent=getXpercent();
    std::cout "the lowest x percentage of students are";
    for (int i=0; i<=xpercent; i++) {
        std::cout << students[i].toString();
    } */
}

void displayTop5(student students[1000]) {
    /*
    students.sort();
    int rPerModule[nModule];
    for (int i=0; i<nModule; i++) {
        rPerModule[i]=0;
        for (int j=0; j<=nStudent; i++) {
            if (strcmp(modules[i].mCode,student[j].mCode)==0) {
                rPerModule[i]++;
            }
        }
    }
    int toDisplayPerModule;
    for (int i=0; i<nModule; i++) {
        toDisplayPerModule=(rPerModule[i]-(rPerModule[i]*5/100));
        std::cout<< "Top 5/% of Module %s are: \n", modules[i].name;
        for (int j=0; j<=nStudent; i++) {
            if (strcmp(modules[i].mCode,student[j].mCode)==0) {
                rPermodule[i]--;
                std::cout<< (students[i].tostring())<< std::endl();
                if (rPermodule[i]<=toDisplayPerModule) {
                    break;
                }
            }
        }
    }*/
}

void join(student (&students)[1000],module (&modules)[100], int nStudent, int nModule) {
    for (int i=0; i<nStudent; i++) {
        students[i].setMIndex(modules, nModule);
    }
    for (int i=0; i<nStudent; i++) {
        students[i].calculateAvgScr(modules[students[i].moduleIndex].coef);

    }
}

void process(int choice) {
    module modules[100];
    student students[1000];
    switch (choice) {
    //open file;
    case 1:
        attemptOpenFile();
        break;
    case 2:
        //validate input;
        validateInput();
        break;
    case 3:
        //read module;
        readModule(modules);
        //display Modules
        displayModules(modules);
        break;
    case 4:
        //read student record;
        readStudent(students);
        //read module record
        readModule(modules);
        //join Student/Modules index
        join(students, modules, nStudent, nModule);
        //display Attendance;
        displayAttendance(students);
        break;
    case 5:

        //read student record;
        readStudent(students);
        ////check Duplicate;
        checkDuplicate(students);
        break;
    case 6:
         //read student record;
        readStudent(students);
        //display students record with lowest scores;
        displayLowest(students);
        break;
    case 7:
        //read student record;
        readStudent(students);
        //display students record with lowest scores;
        displayTop5(students);
        break;
        //lookup students with highest scores;
    default:
        std::cout << "Invalid choice, please try again \n";
        //system("pause");
    }

}

int main(){
    int choice=0;
    std::string input;
    while (choice!=8) {
        //system("cls");
        std::cout << "Welcome to student records management!" << std::endl;
        std::cout << "1.Open input file " << std::endl;
        std::cout << "2.Validate Input File " << std::endl;
        std::cout << "3.Retrieve Module Information " << std::endl;
        std::cout << "4.Display Attendance Percentage and final score" << std::endl;
        std::cout << "5.Check for duplicate student records " << std::endl;
        std::cout << "6.Check for students with lowest scores " << std::endl;
        std::cout << "7.Check for students with top scores " << std::endl;
        std::cout << "8.Exit " << std::endl;
        std::cout << "Please enter a number from 1 to 7 according to the menu:" << std::endl;
        std::getline(std::cin, input);
        std::stringstream convertStream(input);
        if (convertStream>> choice) {
            std::cout << "Your choice is: " << choice<< std::endl;
            //system("pause");
            process(choice);
        }
        else {
            std::cout << "Invalid choice, please try again \n";
            //system("pause");
            choice=0;
        }
    }
    return 0;
}
