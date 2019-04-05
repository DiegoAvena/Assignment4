#include "RunTimeException.h"

/*

An exception that can be thrown when a queue datastructure is found to be empty

*/
class QueueEmptyException: public RunTimeException {

public:
  QueueEmptyException(); //default constructor
  QueueEmptyException(std::string message); //overloaded constructor, allows for a more detailed message to be set for this exception
  ~QueueEmptyException(); //destructor

};
