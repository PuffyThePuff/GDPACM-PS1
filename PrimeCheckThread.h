#pragma once
#include "AThread.h"

class PrimeCheckThread : public AThread
{
public:
	PrimeCheckThread(int numberToCheck, int threadIndex, int threadCount);
	
	bool isRunning = true;
	bool isPrime;

protected:
	void run() override;

	int numToCheck;
	int index;
	int count;
};