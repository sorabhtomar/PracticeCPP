// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <chrono>

class String {
private:
	char* start;
	int capacity;

public:
	//Constructors
	String();
	String(char _c);
	String(const char* _pc);
	String(const String& s); // Copy Constructor

	//Info Methods
	int len() const;
	//int Index(char) const;

	//Operators
	char& operator[](int Index) const;
};

//Constructor with No Parameter ## Usage String s; 
String::String() :start(nullptr), capacity(0) {}

//Constructor with Single Parameter ## Usage String s = 'a'; 
String::String(char _c) {
	start = new char();
	*start = _c;
	capacity = 1;
}

//Constructor with Single Parameter ## Usage String s = "Hello World"; 
String::String(const char* _pc) :capacity(1) {
	const char* buffer = _pc;

	while (*(buffer++))
		capacity++;

	int temp_capacity = capacity;
	if (temp_capacity)
		start = new char[temp_capacity];

	while (temp_capacity--) {
		start[temp_capacity] = *(--buffer);
	}
}
char& String::operator[](int index) const {
	if (index == 0)return *start;
	if (index < capacity) return start[index];
	std::cout << "Out of Bound Error \n Returning First character" << std::endl;
	return *start;
}
String::String(const String& s) {
	capacity = s.len() + 1;

	int i = 0;
	start = new char[capacity];
	while (i < capacity) {
		start[i] = s[i];
		i++;
	}
}

int String::len() const {
	return capacity - 1;
}



class Elapse {
	std::chrono::steady_clock::time_point begin, end;
public:
	Elapse() {
		begin = std::chrono::steady_clock::now();
	}

	~Elapse() {
		end = std::chrono::steady_clock::now();
		std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "Micro Secs " << std::endl;
		std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << " Nano Secs " << std::endl;
	}
};

int main() {
	{
		Elapse e;
		String s;
		s = "Hello World";
		std::cout << s[0] << std::endl;
		s[0] = 'h';
		std::cout << s[0] << std::endl;
		String s2 = s;
		std::cout << s[0] << std::endl;

	}
	std::cin.get();
	return 0;
}