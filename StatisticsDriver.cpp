//Kirollos Gerges, ME Student, T00271723
//Basic Sort file provided by professor
//This program is to find the statistics of the mean, median, and mode.
//the values for which the statisitcs will be calculated will be read
//from an array of an unknown size in a txt file.
//Build : g++ -c StatisticsDriver.cpp Statistics.cpp BasicSort.cpp
//		: g++ -o StatisticsDriver.exe StatisticsDriver.o Statistics.o BasicSort.o

#include <iostream>
#include "Basicsort.h"
#include "Statistics.h"

using namespace std;

int main ()
{
	//variables
	int *numbers;
	char *filename = new char[20]; 			//the filename is assigned to be on heap.
	int actualSize = 0;						//intialzing the actualsize in the first line of the txt file to be zero
	
	cout << "Welcome to the statistics program." <<endl;	
	
	cout << " " <<endl;

	numbers = readData(filename, actualSize);  		   //calling a function to to read in the data from the txt file
	
	insertionSort(numbers, actualSize); 			   // caling a function to sort the data in an ascending order
	
	float mean = findMean(numbers, actualSize);		   //calling a function to evaluate the mean

	float median = findMedian(numbers, actualSize);    //calling a function to evaluate the median

	int mode = findMode(numbers, actualSize);		   //calling a function to evaluate the mode
	
	//printing the outputs
	
	cout << " " << endl;

	cout << "The statistics for the " << actualSize << " read in values are : " << endl;

	cout << " " << endl;

	displayInformation ( mean , median, mode);        //calling a function to displayInformations
		
	
}