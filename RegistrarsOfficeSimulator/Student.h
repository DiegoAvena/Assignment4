/*

Student contains the data specific to a student as they wait in the registrar office, such as
the time they need help for, when they arrived, etc.

*/
class Student {

private:
  unsigned int arrivalTime; //the time this student arrived
  unsigned int timeNeededAtWindow; //the time this student needs help for
  
public:
  Student(); //default constructor
  Student(int timeOfArrival, int timeNeededAtWindow); //overloaded constructor, allows for a custom arrival time and help time to be set for this student
  ~Student(); //destructor

  int getTimeNeededAtWindow(); //accessor method for the time this student needs help for variable
  int getArrivalTime(); //accessor method for the time this student arrives at

};
