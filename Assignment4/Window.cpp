#include "Window.h"

//default constructor
Window::Window() {

  isOpen = true;
  timeWindowHasBeenIdleFor = 0;
  timeWindowNeedsForClient = 0;
  windowHasBeenIdleForMoreThanMaxIdleTime = false;

}

//destructor
Window::~Window() {

}

//accessor method for determining when the window is open or not
const bool& Window::getWindowIsOpen() {

  return isOpen;

}

//mutator method for opening or closing this window
void Window::setIsOpen(bool isOpen) { //mutator method for opening or closing this window

  this->isOpen = isOpen;

}

//increments the time this window has been idle for by 1 when called
void Window::incrementTimeWindowHasBeenIdleFor() {

  this->timeWindowHasBeenIdleFor++;

}

//mutator method that allows for the time this window began helping a client to be set
void Window::setTimeWindowBeganHelpingClient(unsigned int timeWindowBeganHelpingClient) {

  this->timeWindowBeganHelpingClient = timeWindowBeganHelpingClient;

}

//accessor method for getting the time this window closed to help a client
unsigned int Window::getTimeWindowBeganHelpingClient() {

  return this->timeWindowBeganHelpingClient;

}

//mutator method for setting the amount of time this window has been idle for
void Window::setTimeWindowHasBeenIdleFor(unsigned int timeWindowHasBeenIdleFor) {

  this->timeWindowHasBeenIdleFor = timeWindowHasBeenIdleFor;

}

//accessor method for getting the time this window has been idle for
unsigned int Window::getTimeWindowHasBeenIdleFor() {

  return this->timeWindowHasBeenIdleFor;

}

//mutator method for setting the amount of time this window will need to take for helping a client
void Window::setTimeWindowNeedsForClient(int timeWindowNeedsForClient) {

  this->timeWindowNeedsForClient = timeWindowNeedsForClient;

}

//accessor method for getting the amount of time this window needs for current client
int Window::getTimeWindowNeedsForClient() {

  return this->timeWindowNeedsForClient;

}

//mutator method for setting windowHasBeenIdleForMoreThanMaxIdleTime
void Window::setWindowHasBeenIdleForMoreThanMaxIdleTime(bool windowHasBeenIdleForMoreThanMaxIdleTime) {

  this->windowHasBeenIdleForMoreThanMaxIdleTime = windowHasBeenIdleForMoreThanMaxIdleTime;

}

//accessor method for seeing the value of windowHasBeenIdleForMoreThanMaxIdleTime
const bool&  Window::getWindowHasBeenIdleForMoreThanMaxIdleTime(){

  return this->windowHasBeenIdleForMoreThanMaxIdleTime;

}
