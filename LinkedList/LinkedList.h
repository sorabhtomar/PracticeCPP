#pragma once

namespace SinglyList {
	struct node;
	class LinkedList;
}

namespace DoublyList {
	struct node;
	class LinkedList;
}


struct SinglyList::node
{
	int value;
	node* next;
};

class SinglyList::LinkedList
{
private:
	node *head, *tail;

public:
	static int SinglySize;
	LinkedList()
	{
		head = NULL;
		tail = NULL;

	}
	void createnode(int);
	void display();
	void insert_start(int);
	void insert_back(int);
	void insert_position(int, int);

	void delete_start();
	void delete_position(int);
	void delete_last();
	void delete_position_from_last(int);
};

struct DoublyList::node {
	node* prev;
	node* next;
	int value;
};

class DoublyList::LinkedList {
private:
	node* head;
	node* tail;
public:
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	static int DoublySize;
	void createnode(int);
	void insert_start(int);
	void insert_back(int);
	void insert_position(int, int);
	void display();
	void display_reverse();

	void delete_start();
	void delete_position_from_start(int);
	void delete_last();
	void delete_position_from_last(int);
	void delete_position(int);
};
