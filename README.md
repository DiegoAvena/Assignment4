# Assignment4
Simulates the window idle times and student wait times in a registrar office. Time used here can be in any unit, but in this assignment the time is printed out as minutes.  

-To run with makefile, do: make run file=nameOfFileToReadOver

-change nameOfFileToReadOver with the name of the file to be inputed as a command line argument

References:

1.) For bubble sort: //Bubble sort from least to greatest, info on this algorithm is from: https://www.geeksforgeeks.org/bubble-sort/

Important things to take note of:

1.) If a student has just left a window at a specfic time, say at time 3, and there is a student in line who is ready to be taken in, the student in the line will go to this window that has opened at time 3 and will not wait for the next minute. In other words, swaps between students and windows happen simultaneously. 

2.) When the registrar office closes, if there are still windows helping students (these may be students were still at the window when the line becomes empty or the last students in line to go to a window) but other windows that have become idle (windows that are not helping students) at this time of closure, the idle times for these idle windows will not be incremented because the office has already closed at this point. In other words, windows that have become idle at the time the office closes will not be considered as idle and they will not be factored into the window stats. Think of it as when the office closes, idle windows will also close.

3.) Since idle windows close when the office closes, than windows that were idle prior to the time of closing and are still idle at the time of closing in cases where there are still windows with students will no longer have their idle times incremented. Instead, the idle times for these windows will be placed into a list for stats.

4.) Windows are handled from top to bottom, or from index 0 to index n - 1, where n is the number of windows in the array of windows. This means that if 2 windows open up at a specific time and one of these windows is at index 0 in the array of windows and another is at index 1 in the same array of windows, the window at index 0 will take the student in line, and the window at index 1 will become idle until another student arrives, provided that the office has not closed during this time. As another example, there are 2 windows: 1 window is at index 0 and is helping a student and the other window is at index 1 and is idle. If at a certain time, the window at index 0 reopens and the window at index 1 is still idle, and new student arrives at this same time, than the window at index 0 will take that student and the window at index 1 will continue to be idle, since windows are handled from index 0 to n - 1.
