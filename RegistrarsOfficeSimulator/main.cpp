#include "FileInputManager.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  FileInputManager fileReader;
  fileReader.ScanThroughFile(argv, argc); //handles the reading of a file, if given

}
