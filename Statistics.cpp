#include <fstream>
#include <iostream>
#include <iomanip>
#include "Statistics.h"


using namespace std;

int* readData (char* filename, int& size)
{
	int index = 0;
	int* numbers;
	ifstream infile;
	
	do{

		cout << "Please enter the file name containing the values, \n" <<
				"the program will prompt to ask you again for the file name if not valid " << endl;
			
		cin >> filename;				//input of the file name

		infile.open(filename);			//opening the file
		
	} while (!infile);					//will keep the loop while the file doesn't exist

	infile >> size;						//for reading or inputing the first element in the text file which is the size
	
	numbers = new int [size];			//memory allocation on heap
	
	while(!infile.eof())				//while the file is not read till the end of it
	{

		infile >> numbers[index];		//will read the array of the data

		index++;						//increment index

	}
	return numbers;

}

float findMean (int* numbers, int size)
{
	float sum = 0;									//initialzing sum to zero
	float mean =0;									//initialzing mean to zero
	
	for(int i = 0; i < size; i++)					
	{
		sum += *(numbers + i);						//sum is equal to the current element plus the following till the end of the array
	}
	mean = (sum / size);							//Mean equals the summition divided by the size
	
	return mean;									//will return the mean
}


float findMedian (int* numbers, int size)
{
	float median = 0;								//initialzing median to zero
	int firstMed = 0;								//initialzing first median element to zero
	int secMed = 0;									//initialzing second median element to zero
	
	if( size % 2 != 0)								//saying if the array size is odd
	{

		return *(numbers + (size/2) );				//we will get the middle term

	}

	else											//if the array size is even
	{
		
		firstMed = (size / 2) -1;										//we will get the first mid element
		secMed = ( size / 2 );											//we will get the second mid element
		
		median = static_cast<float> ( *( numbers + firstMed ) + *( numbers +secMed ) )/ 2;		//we will get the average of the two middle terms

		return median;																			//will return the median

	}	
}


int findMode (int* numbers, int size)
{
	// intializing the variables 
	
	int mode = numbers[0];
	int number = numbers[0];
	int repeat = 0;
	int modeCount = 1;

	for (int i=1; i < size; i++) 
	{

		if ( number == *(numbers+i)) 	// saying if the following element is equal to the current one
		{

			repeat++; 					//increment the occurence

		}

		else
		{

			if (repeat > modeCount)		// if the following number is different
			{
				
				modeCount = repeat;		//mode is the highest happeness of the number

				mode = number;

			}

			repeat = 1;				    //reseting occurence

			number = *(numbers + i);

		}

	}

	return mode;						//returning the mode

}


void displayInformation (float mean, float median, int mode)
{
	cout<< setprecision(1) << fixed;
	 
	cout << "The mean of the data set provided is: " << mean << endl;			//printing the mean

	cout << "The median of the data set provided is: " << median << endl;		//printing the median

	cout << "The mode of the data set provided is: " << mode << endl;			//printing the mode
	
	cout << " " << endl;

	cout << "Thank you and have a nice day. "  << endl;

}

