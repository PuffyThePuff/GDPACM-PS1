#include "PrimeCheckThread.h"
#include<iostream>

PrimeCheckThread::PrimeCheckThread(int numberToCheck, int threadIndex, int threadCount) {
	numToCheck = numberToCheck;
	index = threadIndex;
	count = threadCount;
}

void PrimeCheckThread::run() {
	isRunning = true;
	isPrime = true;

	// Sets interval size of each thread.
	int intervalSize = numToCheck / count;

	// Sets the inclusive lower limit and exclusive upper limit of the for loop.
	int lowerLimit = index * intervalSize;
	if (index == 0) lowerLimit = 2;	// Makes first thread start at 2.

	int upperLimit = (index + 1) * intervalSize;
	if (index == count - 1) upperLimit = numToCheck;	// Makes last thread end right before the number itself.

	// Goes through every number in this interval to check divisibility.
	for (int i = lowerLimit; i < upperLimit; i++) {
		if (numToCheck % i == 0) {
			isPrime = false;
			break;
		}
	}

	isRunning = false;
}