/*
Jose Miguel D. Bravo
Nathaniel Francis S. Filoteo
GDPARCM X22
Problem Set 1
*/

#include<iostream>
#include<vector>
#include<chrono>
#include"PrimeCheckThread.h"

int main()
{
	auto start = std::chrono::high_resolution_clock::now();

	int numberToCheck = 2147483647;
	int threadCount = 1;

	bool isPrime = true;
	std::vector<PrimeCheckThread*> threadList{};

	for (int i = 0; i < threadCount; i++) {
		PrimeCheckThread* thread = new PrimeCheckThread(numberToCheck, i, threadCount);
		thread->start();
		threadList.push_back(thread);
	}

	while (!threadList.empty()) {
		for (int i = 0; i < threadList.size(); i++) {
			PrimeCheckThread* currentThread = threadList[i];
			if (!currentThread->isRunning) {
				if (!currentThread->isPrime) isPrime = false;
				threadList.erase(threadList.begin() + i);
				delete currentThread;
			}
		}
	}

	if (isPrime) std::cout << "The number is prime." << std::endl;
	else std::cout << "The number is not prime." << std::endl;

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "Execution time: " << duration << std::endl;

	return 0;
}