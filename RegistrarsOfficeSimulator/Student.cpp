#include "Student.h"

Student::Student() { //default constructor

  this->arrivalTime = 1;
  this->timeNeededAtWindow = 1;
  
}

Student::Student(int arrivalTime, int timeNeededAtWindow) { //overloaded constructor, allows for a custom arrival time and help time to be set for this student

  this->arrivalTime = arrivalTime;
  this->timeNeededAtWindow = timeNeededAtWindow;

}

Student::~Student() { //destructor

}

int Student::getArrivalTime(){ //accessor method for the time this student arrives at

  return this->arrivalTime;

}

int Student::getTimeNeededAtWindow() { //accessor method for the time this student needs help for variable

  return this->timeNeededAtWindow;

}
