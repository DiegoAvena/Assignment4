#include "QueueEmptyException.h"
#include "DoubleLinkedList.h"

template <typename dataType>

/*

A FIFO data structure: items at are inserted at the rear and items at the front are removed.

*/
class Queue {

private:
  DoubleLinkedList<dataType> listOfQueueItems; //the container that will hold all of the items put into the queue

public:

  //constructor
  Queue() {

  }

  //overloaded constructor
  ~Queue() {

  }

  //returns the item at the front of the queue
  dataType front() throw(QueueEmptyException){

    if (empty()) {

      //there is nothing to return:
      throw QueueEmptyException("Queue empty");

    }

    return listOfQueueItems.getFront();

  }

  //adds an item to the back of the queue
  void enqueue(dataType element) {

    listOfQueueItems.addBack(element);

  }

  //removes the item at the front of the queue if the queue is not empty
  void dequeue() throw(QueueEmptyException){

    if (empty()) {

      //nothing to remove:
      throw QueueEmptyException("Queue empty");

    }

    listOfQueueItems.removeFront();

  }

  //checks if the queue is empty
  bool empty() {

    return (listOfQueueItems.empty());

  }

};
