#include "RegistrarOffice.h"
#include "StatisticsManager.h"
#include <iostream>

using namespace std;

//default constructor
RegistrarOffice::RegistrarOffice() {

  currentMinute = 0;

}

//destructor
RegistrarOffice::~RegistrarOffice() {

  delete[] windows;

}

//creates Student objects with the given arrival and needed help times, and places them in the line in the order that they are in the input file
void RegistrarOffice::addStudentToLine(unsigned int arrivalTime, unsigned int timeNeededAtWindow) {

  Student student(arrivalTime, timeNeededAtWindow);
  line.enqueue(student);

}

//simulates the sending of a student to the provided open window
void RegistrarOffice::sendStudentToWindow(Window& window) {

  window.setIsOpen(false); //this window is helping a student so it should be closed off to other students until it is done helping this one

  if (window.getTimeWindowHasBeenIdleFor() != 0) {

      //this window waited for a certain amount of minutes:
      windowIdleTimes.addFront(window.getTimeWindowHasBeenIdleFor());

  }

  window.setTimeWindowHasBeenIdleFor(0); //reset back to 0 for the next possible idle time to be calculated correctly
  window.setTimeWindowNeedsForClient(line.front().getTimeNeededAtWindow()); //This time allows for this window to be reopened once it has elapsed, so this is important to do otherwise the window might not reopen again even though it is done helping this student
  window.setTimeWindowBeganHelpingClient(currentMinute); //this will be used to calculate the amount of time a window has helped a student, so that the program knows when the window can be reopened again

}

//checks and opens the provided window if it is current closed and needs to be opened due to being finished with helping a student
void RegistrarOffice::checkIfWindowShouldBeOpened(Window& window) {

  if (window.getWindowIsOpen() == false) {

    if ((currentMinute - window.getTimeWindowBeganHelpingClient()) >= window.getTimeWindowNeedsForClient()) {

      //the window is closed and is finished helping the current student, so reopen it:
      window.setIsOpen(true);

    }

  }

}

//allocates the windows array with the correct number of window objects
void RegistrarOffice::openWindows(int numberOfWindowsToOpen) {

  windows = new Window[numberOfWindowsToOpen];
  numberOfWindows = numberOfWindowsToOpen;

  for (int i = 0; i < numberOfWindows; i++) {

    Window windowToOpen;
    windows[i] = windowToOpen;

  }

}

//checks if the current window has been idle for over the specified time, so that the number of windows idle for more than this time can be correctly counted later
void RegistrarOffice::checkIfWindowHasBeenIdleForOverMaxIdleTimeOf(unsigned int time, Window& window) {

  if ((window.getTimeWindowHasBeenIdleFor() > time) && (window.getWindowHasBeenIdleForMoreThanMaxIdleTime() == false)) {

    window.setWindowHasBeenIdleForMoreThanMaxIdleTime(true);

  }

}
//launches the simulation, this is where the while loop is placed so that students can be helped until there is no more students in line
void RegistrarOffice::beginSimulation() {

  while (line.empty() == false) {

    //check for open windows:
    for (int i = 0; i < numberOfWindows; i++) {

      checkIfWindowShouldBeOpened(windows[i]);
      checkIfWindowHasBeenIdleForOverMaxIdleTimeOf(5, windows[i]);

      if (line.empty() == false) {

        if (currentMinute >= line.front().getArrivalTime()) {

          //a student needs to be taken in at the front of the line, check if any windows are open:
          if (windows[i].getWindowIsOpen()) {

            //either a window was open, or a window just finished helping a student, "send" this student to that window:
            sendStudentToWindow(windows[i]);

            int studentWaitTime = currentMinute - line.front().getArrivalTime();

            if (studentWaitTime != 0) {

              //the student being taken in had to wait for some minutes: they had a waiting time
              studentWaitTimes.addFront(currentMinute - line.front().getArrivalTime());

            }

            line.dequeue();

          }

        }
        else if (windows[i].getWindowIsOpen()) {

          //there is currently no student to take in, and this window is open, increment its idle time:
          windows[i].incrementTimeWindowHasBeenIdleFor();

        }

      }

    }

    if (line.empty() == false) {

      //increment minute for next iteration:
      currentMinute++;

    }

  }

  //By this point the office has closed: add any window idle times that might not have been added into the list yet:
  for (int i = 0; i < numberOfWindows; i++) {

    if (windows[i].getTimeWindowHasBeenIdleFor() > 0) {

      windowIdleTimes.addFront(windows[i].getTimeWindowHasBeenIdleFor());
      windows[i].setTimeWindowHasBeenIdleFor(0);

    }

  }

  getStats();

  //FOR DEBUGGING:
  /*std::cout<<"The windows had the following idle times:"<<std::endl;
  windowIdleTimes.printList();
  std::cout<<"The students had the following wait times:"<<std::endl;
  studentWaitTimes.printList();*/

}

//uses the StatisticsManager to print out stats on window idle times and student wait times
void RegistrarOffice::getStats() {

  StatisticsManager studentStats(studentWaitTimes);
  StatisticsManager windowStats(windowIdleTimes);

  cout<<"STUDENT STATISTICS:"<<endl;
  cout<<"The mean student wait time was: "<<studentStats.getMean()<<" minutes."<<endl;
  cout<<"The median student wait time was: "<<studentStats.getMedian()<<" minutes."<<endl;
  cout<<"The longest student wait time was: "<<studentStats.getMaximum()<<" minutes."<<endl;
  cout<<"The number of students waiting over 10 minutes was: "<<studentStats.getFrequencyOfValuesGreaterThan(10)<<endl;
  cout<<endl;
  cout<<"WINDOW STATISTICS: "<<endl;
  cout<<"The mean window idle time was: "<<windowStats.getMean()<<" minutes."<<endl;
  cout<<"The median window time was: "<<windowStats.getMedian()<<" minutes."<<endl;
  cout<<"The longest window idle time was: "<<windowStats.getMaximum()<<" minutes."<<endl;
  cout<<"The number of windows idle for over 5 minutes was: "<<determineNumberOfWindowsThatWaitedOverMaxIdleTime();
  cout<<endl;

}

//determines the correct amount of windows that were idle for over 5 mins
unsigned int RegistrarOffice::determineNumberOfWindowsThatWaitedOverMaxIdleTime() {

  unsigned int frequency = 0;

  for (int i = 0; i < numberOfWindows; i++) {

    if (windows[i].getWindowHasBeenIdleForMoreThanMaxIdleTime()) {

      //this window waited for over 5 mins
      frequency++;

    }

  }

  return frequency;

}
