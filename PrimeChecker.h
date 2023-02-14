#pragma once
#include "AExecutionEvent.h"
#include"PrimeCheckThread.h"

class PrimeChecker : public AExecutionEvent
{
public:
	PrimeChecker(int threadCount);
	bool checkPrime(int numberToCheck);
	void onFinish() override;

private:
	
	int count;
	bool isPrime = true;
};