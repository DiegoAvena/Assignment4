#include "DoubleLinkedList.h"
#include <iostream>

/*

-StatisticsManager contains all the methods needed for calculating stats, such as mean, median, max, etc., provided
it is given a list of numerical data to compute these stats for

*/
class StatisticsManager {

private:
  float* valuesToComputeStatsFor; //an array of all the numerical data that will be used for statistics, this makes things such as finding the median more simplistic
  unsigned int sizeOfListToComputeStatsFor; //the number of items in the array
  void sortListFromLeastToGreatest(float* arrayToSortFromLeastToGreatest); //sorts the array of numerical data from least to greatest, which is needed to find the median.

public:
  StatisticsManager(); //default constructor
  StatisticsManager(DoubleLinkedList<int>& listOfValuesToComputeMeanOf); //overloaded constructor: takes in the list of numerical data to compute stats for
  ~StatisticsManager(); //destructor
  void printArray(); //for DEBUGGING
  float getMean(); //gets the mean of the array of numerical data to compute stats for
  float getMedian(); //gets the median of the array of numerical data to compute stats for
  int getMaximum(); //gets the maximum value in the array of numerical data to compute stats for
  int getFrequencyOfValuesGreaterThan(const int& value); //gets the amount of times a value greater than the specified value is in the list of numerical data

};
