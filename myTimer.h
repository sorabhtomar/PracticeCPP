#include<chrono>
class myTimer {
	std::chrono::steady_clock::time_point begin, end;
public:
	myTimer();
	~myTimer();
};