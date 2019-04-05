#include "Student.h"
#include "Window.h"
#include "Queue.h"
#include "DoubleLinkedList.h"

/*

Simulates the waiting and helping of students in a registrar office

*/
class RegistrarOffice {

private:
  Window* windows; //an array of all the windows that exist for this office

  Queue<Student> line; //the line students will wait in to get help

  DoubleLinkedList<int> studentWaitTimes; //stores all of the waiting times for each student for calculating statistics later
  DoubleLinkedList<int> windowIdleTimes; //stores all of the idle times for each window for calculating statistics later on

  unsigned int currentMinute; //keeps track of how much time has passed (in minutes)
  unsigned int numberOfWindows; //keeps track of the number of windows that exist in the office

  void sendStudentToWindow(Window& window); //simulates the sending of a student to the provided open window
  void checkIfWindowShouldBeOpened(Window& window); //checks and opens the provided window if it is current closed and needs to be opened due to being finished with helping a student
  void getStats(); //uses the StatisticsManager to print out stats on window idle times and student wait times

public:
  RegistrarOffice(); //default constructor
  ~RegistrarOffice(); //destructor

  void openWindows(int numberOfWindowsToOpen); //allocates the windows array with the correct number of window objects
  void addStudentToLine(unsigned int arrivalTime, unsigned int timeNeededAtWindow); //creates Student objects with the given arrival and needed help times, and places them in the line in the order that they are in the input file
  void beginSimulation(); //launches the simulation, this is where the while loop is placed so that students can be helped until there is no more students in line

};
