#pragma once
#include "AThread.h"
#include"AExecutionEvent.h"

class PrimeCheckThread : public AThread
{
public:
	PrimeCheckThread(int numberToCheck, int threadIndex, int threadCount, bool* fullIsPrime, AExecutionEvent* execEvent);
	void stopThread();
	
private:
	void run() override;

	AExecutionEvent* event;
	int numToCheck;
	int index;
	int count;
	bool* totalIsPrime;
	bool isPrime = true;
};