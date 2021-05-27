#include "StatisticsManager.h"
using namespace std;

//default constructor
StatisticsManager::StatisticsManager() {

  valuesToComputeStatsFor = NULL;
  sizeOfListToComputeStatsFor = 0;

}

//overloaded constructor: takes in the list of numerical data to compute stats for
StatisticsManager::StatisticsManager(DoubleLinkedList<int>& listOfValuesToComputeStatsFor) {

  valuesToComputeStatsFor = new float[listOfValuesToComputeStatsFor.getSize()];
  sizeOfListToComputeStatsFor = listOfValuesToComputeStatsFor.getSize();

  for (int i = 0; i < listOfValuesToComputeStatsFor.getSize(); i++) {

    valuesToComputeStatsFor[i] = listOfValuesToComputeStatsFor.findAt(i);

  }

  sortListFromLeastToGreatest(valuesToComputeStatsFor);

}

//destructor
StatisticsManager::~StatisticsManager() {

  if (valuesToComputeStatsFor != NULL) {

    delete[] valuesToComputeStatsFor;

  }

}

//Bubble sort from least to greatest, info on this algorithm is from: https://www.geeksforgeeks.org/bubble-sort/
void StatisticsManager::sortListFromLeastToGreatest(float* arrayToSortFromLeastToGreatest) {

  for (int i = 0; i < sizeOfListToComputeStatsFor; i++) {

    for (int b = 0; b < (sizeOfListToComputeStatsFor - 1); b++) {

      if (arrayToSortFromLeastToGreatest[b] > arrayToSortFromLeastToGreatest[b + 1]) {

        //swap the greater value with the smaller value
        float smallerValue = arrayToSortFromLeastToGreatest[b + 1];
        arrayToSortFromLeastToGreatest[b + 1] = arrayToSortFromLeastToGreatest[b];
        arrayToSortFromLeastToGreatest[b] = smallerValue;

      }

    }

  }

}

//for DEBUGGING
void StatisticsManager::printArray() {

  for (int i = 0; i < sizeOfListToComputeStatsFor; i++) {

    cout<<valuesToComputeStatsFor[i]<<endl;

  }

}

//gets the mean of the array of numerical data to compute stats for
float StatisticsManager::getMean() {

  float mean = 0;

  for (int i = 0; i < sizeOfListToComputeStatsFor; i++) {

    mean += float(valuesToComputeStatsFor[i]);

  }

  return (mean / float(sizeOfListToComputeStatsFor));

}

//gets the median of the array of numerical data to compute stats for
float StatisticsManager::getMedian() {

  if ((sizeOfListToComputeStatsFor % 2) != 0) {

    //there will only be 1 number in the middle since the list contains an odd number of entries:
    int front = 0;
    int back = sizeOfListToComputeStatsFor - 1;

    while (front != back) {

      front++;
      back--;

    }

    return valuesToComputeStatsFor[front];

  }
  else {

    //there will be 2 numbers in the middle, add both and devide by 2:
    return (float((valuesToComputeStatsFor[(sizeOfListToComputeStatsFor / 2) - 1] + valuesToComputeStatsFor[(sizeOfListToComputeStatsFor / 2)])) / 2);

  }

}

//gets the maximum value in the array of numerical data to compute stats for
int StatisticsManager::getMaximum() {

  //since the array is sorted from least to greatest, the max is at the end:
  return valuesToComputeStatsFor[sizeOfListToComputeStatsFor - 1];

}

//gets the amount of times a value greater than the specified value is in the list of numerical data
int StatisticsManager::getFrequencyOfValuesGreaterThan(const int& value) {

  int frequency = 0;

  for (int i = 0; i < sizeOfListToComputeStatsFor; i++) {

    if (valuesToComputeStatsFor[i] > value) {

      frequency++;

    }

  }

  return frequency;

}
