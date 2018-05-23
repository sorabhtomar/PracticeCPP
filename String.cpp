#include <iostream>     // std::cout
#include"String.h"




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

String::~String() {
	if (capacity == 1)
		delete start;
	if (capacity > 1)
		delete[] start;
}
