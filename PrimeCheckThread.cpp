#include "PrimeCheckThread.h"

PrimeCheckThread::PrimeCheckThread(int numberToCheck, int threadIndex, int threadCount, bool* fullIsPrime, AExecutionEvent* execEvent) {
	numToCheck = numberToCheck;
	index = threadIndex;
	count = threadCount;
	totalIsPrime = fullIsPrime;
	event = execEvent;
}

void PrimeCheckThread::stopThread() {
	delete this;
}

void PrimeCheckThread::run() {
	// Sets the denominator for determining interval size as (thread count - 1), so the last thread only handles the last few remaining numbers.
	int denominator = count - 1;
	if (denominator == 0) denominator = 1;	// Avoids a divide by zero error.
	int intervalSize = numToCheck / denominator;

	// Sets the inclusive lower limit and exclusive upper limit of the for loop.
	int lowerLimit = index * intervalSize;
	if (lowerLimit >= numToCheck) delete this;	// Deletes thread entirely if the lower limit is equal to the number being checked or higher; should only ever happen at count = 2.
	if (index == 0) lowerLimit = 2;	// Makes first thread start at 2.

	int upperLimit = (index + 1) * intervalSize;
	if (index == count - 1) upperLimit = numToCheck;	// Makes last thread end at the number itself.

	// Goes through every number in this interval to check divisibility.
	for (int i = lowerLimit; i < upperLimit; i++) {
		if (numToCheck % i == 0) {
			isPrime = false;
			break;
		}
	}

	// Changes value of main isPrime flag to (main isPrime AND thread isPrime).
	// By boolean operations, main isPrime flag will become false if even a single one of these threads has a false isPrime flag.
	*totalIsPrime = *totalIsPrime && isPrime;
	event->onFinish();
	delete this;
}