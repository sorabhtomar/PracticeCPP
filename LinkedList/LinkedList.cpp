#include <iostream>
#include "LinkedList.h"

using namespace std;

int DoublyList::LinkedList::DoublySize;
int SinglyList::LinkedList::SinglySize;

void SinglyList::LinkedList::createnode(int _value)
{
	node* temp = new node;
	temp->value = _value;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	SinglySize++;
}

void SinglyList::LinkedList::display()
{
	node *temp = new node;
	for (temp = head; temp != NULL; temp = temp->next)
		cout << temp->value << "\t";
	cout << endl;
}

void SinglyList::LinkedList::insert_start(int _value)
{
	node* temp = new node;
	temp->value = _value;
	temp->next = head;
	head = temp;
	SinglySize++;
}

void SinglyList::LinkedList::insert_back(int _value)
{
	createnode(_value);
}

void SinglyList::LinkedList::insert_position(int _value, int _pos)
{
	node *prev = new node;
	node *cur = new node;
	node *temp = new node;

	cur = head;

	for (int i = 0; i < _pos; i++)
	{
		prev = cur;
		cur = cur->next;
	}
	temp->value = _value;
	prev->next = temp;
	temp->next = cur;
	SinglySize++;

}

void SinglyList::LinkedList::delete_last()
{
	if (SinglySize > 0)
	{
		node* temp = head;
		for (int i = 0; i <= SinglySize; i++)
		{
			temp = temp->next;
		}
		temp->next = NULL;
		tail = temp;
		SinglySize--;
	}
	else cerr << "Invalid Operation... Check your list and try again." << endl;
}

void SinglyList::LinkedList::delete_start()
{
	if (head)
	{
		head = head->next;
		SinglySize--;
	}
	else cerr << "Invalid Operation... Check your list and try again." << endl;
}

void SinglyList::LinkedList::delete_position(int n)
{
	if (n < SinglySize - 1)
	{
		node* temp = head;
		for (int i = 0; i < n - 1; i++)
		{
			temp = temp->next;
		}

		node*temp2 = temp->next;

		temp->next = temp2->next;
		SinglySize--;
	}
	else cerr << "Invalid Operation... Check your list and try again." << endl;
}

void SinglyList::LinkedList::delete_position_from_last(int n)
{
	if (n < SinglySize - 1)
	{
		delete_position(SinglySize - (n - 1));
	}
	else cerr << "Invalid Operation... Check your list and try again." << endl;
}

void DoublyList::LinkedList::createnode(int _value)
{
	node* temp = new node;
	temp->value = _value;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}

	DoublySize++;

}

void DoublyList::LinkedList::display()
{
	node* temp = new node;
	temp = head;
	while (temp != NULL)
	{
		cout << temp->value << "\t";
		temp = temp->next;
	}
	cout << endl;
}

void DoublyList::LinkedList::insert_back(int _value)
{
	DoublyList::LinkedList::createnode(_value);
}

void DoublyList::LinkedList::insert_start(int _value)
{
	node* temp = new node;
	temp->value = _value;
	temp->prev = NULL;
	temp->next = head;
	head->prev = temp;
	head = temp;
	temp = NULL;
	DoublySize++;

}

void DoublyList::LinkedList::insert_position(int _value, int _pos)
{
	node* pre = new node;
	node* cur = new node;
	node* temp = new node;
	temp->value = _value;
	cur = head;
	for (int i = 0; i < _pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	pre->next = temp;
	temp->next = cur;
	cur->prev = temp;
	temp->prev = pre;
	DoublySize++;

}

void DoublyList::LinkedList::display_reverse()
{
	node* temp = new node;
	temp = tail;
	while (temp != NULL)
	{
		cout << temp->value << "\t";
		temp = temp->prev;
	}
	cout << endl;
}

void DoublyList::LinkedList::delete_last()
{
	tail = tail->prev;
	DoublySize--;
}

void DoublyList::LinkedList::delete_start()
{
	head = head->next;
	DoublySize--;
}

void DoublyList::LinkedList::delete_position_from_start(int n)
{
	if (n < DoublySize - 1)
	{
		node* temp = head;
		for (int i = 0; i < n; i++)
		{
			temp = temp->next;
		}
		node* temp2 = temp->next;
		temp = temp2->next;
		DoublySize--;
	}
}

void DoublyList::LinkedList::delete_position_from_last(int n)
{
	if (n < DoublySize - 1)
	{
		node* temp = tail;
		for (int i = 0; i < n; i++)
		{
			temp = temp->prev;
		}
		node* temp2 = temp->prev;
		temp = temp2->prev;
		DoublySize--;
	}
}

void DoublyList::LinkedList::delete_position(int n)
{
	if (0 == n)
		delete_start();
	else if (DoublySize - 1 == n)
		delete_last();
	else if (n <= (DoublySize - 1) / 2)
		delete_position_from_start(n);
	else if (n > (DoublySize - 1) / 2)
		delete_position_from_last(DoublySize - n);
}

