/*
	Statistics.h / Read Data, Mean,  Median, Mode /
	Statistics.h
	Functions to read date from a text file, find the mean, median and mode
	3.29.19
*/

#if !defined STATISTICS_H
#define STATISTICS_H

/******************************************************************
 *
 * Desc : this function is to read in data from a file
 * Pre  : a char pointer of a file name and an addressed value of size,
 *	      the txt file should have every element on a new line with the
 *		  first element being the size
 * Post : returns an integer pointer of the data array. the array size 
 *		  is size, the second parameter in the function
 *
 ******************************************************************/

int* readData (char* filename, int& size);

/******************************************************************
 *
 * Desc : this function is to calculate the mean of numbers
 * Pre  : inputs are pointer to numbers integer array and its size
 * Post : Returns float mean of the given numbers
 *
 ******************************************************************/

float findMean (int* numbers, int size);

/******************************************************************
 *
 * Desc : this functon is to calculate the median of numbers
 * Pre  : a pointer to array of integers *numbers and its size
 * Post : Returns float median of the given numbers
 *
 ******************************************************************/

float findMedian (int* numbers, int size);

/******************************************************************
 *
 * this function is to calculate mode of numbers
 * Pre  : a pointer to array of integers *numbers and its size
 * Post : Returns int mode of the given numbers
 *
 ******************************************************************/

int findMode (int* numbers, int size);

/******************************************************************
 *
 * Desc : this function is to output the information of the calucalted mean,
 *        median, and mode
 * Pre  : a float value of mean and median and an integer value of mode
 * Post : prints out the value of a float mean and median with a precision
 *        of 1 and an integer of mode
 *
 ******************************************************************/

void displayInformation (float mean, float median, int mode);


#endif // Statistics