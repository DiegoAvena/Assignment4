#include "QueueEmptyException.h"
using namespace std;

//default constructor
QueueEmptyException::QueueEmptyException():RunTimeException(){}

//overloaded constructor, allows for a more detailed message to be set for this exception
QueueEmptyException::QueueEmptyException(string message):RunTimeException(message){}

//destructor
QueueEmptyException::~QueueEmptyException(){

}
