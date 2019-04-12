#include "FileInputManager.h"
#include "RegistrarOffice.h"

using namespace std;

FileInputManager::FileInputManager() { //default constructor

}

FileInputManager::~FileInputManager() { //destuctor

}

//reads each line in the file and feed it into SyntaxMachine to check syntax
void FileInputManager::ScanThroughFile(char const *commandLineArguments[], int argumentCount) {

  if (argumentCount < 2) { //user did not enter the name of a file as a command line argument

    cout<<"I detected that you did not insert the name of a file to read. Exiting"<<endl;
    return;

  }

  string fileName = commandLineArguments[1];

  ifstream fileToReadFrom(fileName);

  if (fileToReadFrom.is_open()) {

    //file successfully opened

    string line; //the current line being read, will be fed into syntaxMachine
    currentLineNumber = 0;

    RegistrarOffice office; //handles the running of the simulation
    int arrivalTime = -1; //the time someone arrived at
    int expectedNumberOfStudents = 0; //the number of students set to arrive at this time
    int lineWhereFirstStudentToArriveIs; //the spot where the first student to arrive is at

    while (getline(fileToReadFrom, line)) {

      //there are still lines to read:

      if (currentLineNumber == 0) {

        //this is the line with the number of windows that need to exist in the office:
        int numberOfWindows = stoi(line);
        while (numberOfWindows <= 0) {

          //there has to be at least 1 window in the office, otherwise the simulation might run on forever since students would just be waiting in line but there are no windows to take them in
          cout<<"There needs to be at least 1 window open, please enter a valid number of windows:"<<endl;
          cin>>numberOfWindows;

        }
        //office.openWindows(stoi(line));
        office.openWindows(numberOfWindows);

      }
      else if (arrivalTime < 0){

        arrivalTime = stoi(line);

      }
      else if (expectedNumberOfStudents == 0) {

        lineWhereFirstStudentToArriveIs = currentLineNumber + 1; //next line is the line representing the first student to arrive at this time

        expectedNumberOfStudents = stoi(line);

      }
      else {

        //put a new student in line:
        office.addStudentToLine(arrivalTime, stoi(line));

        if (((currentLineNumber + 1) - lineWhereFirstStudentToArriveIs) >= expectedNumberOfStudents) {

          //next line is another arrival time:
          arrivalTime = -1;
          lineWhereFirstStudentToArriveIs = 0;
          expectedNumberOfStudents = 0;

        }

      }

      currentLineNumber++;

    }

    fileToReadFrom.close();
    office.beginSimulation();

  }
  else {

    cout<<"The file you entered could not be found"<<endl;

  }

}
