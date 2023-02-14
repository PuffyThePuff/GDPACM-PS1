#include "PrimeChecker.h"

PrimeChecker::PrimeChecker(int threadCount) {
	count = threadCount;
}

bool PrimeChecker::checkPrime(int numberToCheck) {
	isPrime = true;
}

void PrimeChecker::onFinish() {
	if (!isPrime) {

	}
}