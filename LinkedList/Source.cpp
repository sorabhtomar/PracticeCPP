#include<iostream>
#include"LinkedList.h"

using namespace std;



int main()
{
	SinglyList::LinkedList L1;
	L1.createnode(3);
	L1.insert_back(4);
	L1.insert_position(10, 1);
	L1.insert_start(5);
	L1.display();

	cout << endl;

	DoublyList::LinkedList L2;
	L2.createnode(4);
	L2.createnode(5);
	L2.insert_back(6);
	L2.insert_start(3);
	L2.insert_back(7);
	L2.insert_start(2);
	L2.display();
	cout << endl;
	L2.display_reverse();
	return 0;
}