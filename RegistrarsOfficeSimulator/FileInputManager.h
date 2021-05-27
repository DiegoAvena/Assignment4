#include <iostream>
#include <fstream>

/*
-InputManager is responsible for
allowing the user to decide which file they want
to check and to feed each line in that file to SyntaxMachine
in order to syntax checking to occur
*/
class FileInputManager {

private:
  unsigned int currentLineNumber; //keeps track of the number of the line being read

public:
  FileInputManager(); //default constructor
  ~FileInputManager(); //destuctor
  void ScanThroughFile(char const *commandLineArguments[], int argumentCount); //reads each line in the file and feed it into SyntaxMachine to check syntax

};
