/*

-Window contains information related to a Window in an office that helps people, such as
if the window is open, keeping track of its idle time, how long it needs to help a client, and the time
it began helping the client

*/
class Window {

private:
  bool isOpen; //keeps track of whether or not this window is open
  unsigned int timeWindowHasBeenIdleFor; //keeps track of how long this window has been open without a client to help
  int timeWindowNeedsForClient; //stores how long this window will need for a client
  unsigned int timeWindowBeganHelpingClient; //stores the exact time the window began helping a client, so that the window knows when to move on
  bool windowHasBeenIdleForMoreThanMaxIdleTime; //keeps track of whether or not this window was idle for over a specific idle time, so that the number of windows that waited for more than this time can be counted correctly

public:
  Window(); //default constructor
  ~Window(); //destructor
  const bool& getWindowIsOpen(); //accessor method for determining when the window is open or not
  void setIsOpen(bool isOpen); //mutator method for opening or closing this window
  void setTimeWindowHasBeenIdleFor(unsigned int timeWindowHasBeenIdleFor); //mutator method for setting the amount of time this window has been idle for
  unsigned int getTimeWindowHasBeenIdleFor(); //accessor method for getting the time this window has been idle for
  void incrementTimeWindowHasBeenIdleFor(); //increments the time this window has been idle for by 1 when called
  void setTimeWindowBeganHelpingClient(unsigned int timeWindowBeganHelpingClient); //mutator method that allows for the time this window began helping a client to be set
  unsigned int getTimeWindowBeganHelpingClient(); //accessor method for getting the time this window closed to help a client

  //mutator method for setting windowHasBeenIdleForMoreThanMaxIdleTime
  void setWindowHasBeenIdleForMoreThanMaxIdleTime(bool windowHasBeenIdleForMoreThanMaxIdleTime);

  //accessor method for seeing the value of windowHasBeenIdleForMoreThanMaxIdleTime
  const bool& getWindowHasBeenIdleForMoreThanMaxIdleTime();

  void setTimeWindowNeedsForClient(int timeWindowNeedsForClient); //mutator method for setting the amount of time this window will need to take for helping a client
  int getTimeWindowNeedsForClient(); //accessor method for getting the amount of time this window needs for current client

};
