#include<iostream>
#include"myTimer.h"

myTimer::myTimer() {
	begin = std::chrono::steady_clock::now();
}

myTimer::~myTimer() {
	end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "Micro Secs " << std::endl;
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << " Nano Secs " << std::endl;
}