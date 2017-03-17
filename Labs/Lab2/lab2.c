// lab2.c - measure execution time of C code

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main ()
{
	const int MaxSize = 75000;
	int i, j, temp;


	// Part one: processing a statically allocated array

	clock_t staticBegin = clock();
	int staticArray[MaxSize];		// declare an array 

	for (i=0; i<MaxSize; i++)		// initialize the array with a
		staticArray[i] = MaxSize-i;	// descending sequence of values

	for (i=0; i<MaxSize-1; i++)		// bubble sort data in the array
		for (j=MaxSize-1; j>i; j--)
			if (staticArray[j-1] > staticArray[j])
			{
				temp = staticArray[j-1];
				staticArray[j-1] = staticArray[j];
				staticArray[j] = temp;
			}
	clock_t staticEnd = clock();
	double staticTime = (double)(staticEnd-staticBegin)/CLOCKS_PER_SEC;


	// Part two: processing a dynamically allocated array
	int *a, *b, *tmp;
	

	clock_t dynamicBegin = clock();
	int *dynamicArray = (int*)malloc(sizeof(int) * MaxSize); // declare array

	for(i=0; i<MaxSize; i++){
		*(dynamicArray+i) = MaxSize-i;	// populate array
	}

	for (a=dynamicArray; a<dynamicArray+MaxSize-1; a++)		// bubble sort data in the array
		for (b=dynamicArray+MaxSize-1; b>a; b--)
			if (*(b-1) > *b)
			{
				//temp = staticArray[j-1];
				//staticArray[j-1] = staticArray[j];
				//staticArray[j] = temp;
				tmp = b-1;
				*(b-1) = *b;
				b = tmp;
			}

	clock_t dynamicEnd = clock();
	double dynamicTime = (double)(dynamicEnd-dynamicBegin)/CLOCKS_PER_SEC;

	free(dynamicArray);



	// Display the amount of time used for each part above
	printf("Static time: %f\n", staticTime);
	printf("Dynamic time: %f\n", dynamicTime);



	return 0;
}
