/*
Jose Miguel D. Bravo
Nathaniel Francis S. Filoteo
GDPARCM X22
Problem Set 1
*/

#include <iostream>
#include"PrimeChecker.h"

int main()
{
	int numToCheck = 2147483647;
	int threadCount = 1;

	PrimeChecker* checker = new PrimeChecker(threadCount);
	checker->checkPrime(numToCheck);

	return 0;
}