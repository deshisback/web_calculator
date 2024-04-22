#include <iostream>

using namespace std;

class LinkedListNode
{

public:

	int value;
	LinkedListNode* next;
	LinkedListNode* prev;

	LinkedListNode(int _value)
	{
		value = _value;
		next = nullptr;
		prev = nullptr;
	}

};

class TwoLinkLinkedList
{

private:

	LinkedListNode* head;
	LinkedListNode* tail;

public:

	TwoLinkLinkedList()
	{
		head = tail = nullptr;
	}

	void PushBack(int _value)
	{

		LinkedListNode* NewNode = new LinkedListNode(_value);

		if (head == nullptr)
		{
			head = tail = NewNode;
			head->next = head->prev = tail;
			tail->next = tail->prev = head;
		}

		else
		{
			tail->next = NewNode;
			NewNode->prev = tail;
			tail = NewNode;
			tail->next = head;
			head->prev = tail;
		}

	}

	void PushFront(int _value)
	{

		LinkedListNode* NewNode = new LinkedListNode(_value);

		if (head == nullptr)
		{
			head = tail = NewNode;
			head->next = head->prev = tail;
			tail->next = tail->prev = head;
		}

		else
		{
			NewNode->next = head;
			head->prev = NewNode;
			head = NewNode;
			head->prev = tail;
			tail->next = head;
		}

	}

	void Print()
	{

		if (head == nullptr) return;

		else
		{

			LinkedListNode* temp = head;

			do
			{
				cout << temp->value << " ";
				temp = temp->next;
			} while (temp != head);
		}

		cout << endl;

	}

	void PopBack()
	{

		if (head == nullptr) return;

		if (head == tail)
		{
			head->next = head->prev = nullptr;
			tail->next = tail->prev = nullptr;
			delete head;
		}

		else
		{
			LinkedListNode* temp = tail->prev;
			temp->next = nullptr;
			tail->next = tail->prev = nullptr;
			head->prev = nullptr;
			delete tail;
			tail = temp;
			tail->next = head;
			head->prev = tail;
		}

	}

	void PopFront()
	{

		if (head == nullptr) return;

		if (head == tail)
		{
			head->next = head->prev = nullptr;
			tail->next = tail->prev = nullptr;
			delete head;
		}

		else
		{
			LinkedListNode* temp = head->next;
			temp->prev = nullptr;
			head->next = head->prev = nullptr;
			tail->next = nullptr;
			delete head;
			head = temp;
			head->prev = tail;
			tail->next = head;
		}

	}

	LinkedListNode* Get(int _value)
	{

		if (head == nullptr) return nullptr;

		else
		{

			LinkedListNode* temp = head;
			do
			{
				if (temp->value == _value) return temp;
				temp = temp->next;
			} while (temp != head);

		}

		return nullptr;

	}

	void Insert(int place, int _value)
	{

		if (head == nullptr || place <= 0) PushFront(_value);

		else
		{
			
			LinkedListNode* left = head;
			int currentplace = 1;

			while (currentplace != place)
			{
				left = left->next;
				currentplace++;
			}

			if (left == tail) PushBack(_value);

			else
			{

				LinkedListNode* right = left->next;
				LinkedListNode* NewNode = new LinkedListNode(_value);

				left->next = NewNode;
				NewNode->prev = left;
				NewNode->next = right;
				right->prev = NewNode;

			}

		}

	}

	void Erase(int place)
	{

		if (head == nullptr) return;

		else if (place <= 1) PopFront();

		else
		{

			int currentplace = 2;
			LinkedListNode* erased = head->next;
			LinkedListNode* left = head;

			while (currentplace != place)
			{
				erased = erased->next;
				left = left->next;
				currentplace++;
			}

			if (erased == head) PopFront();

			else if (erased == tail)PopBack();

			else
			{
				LinkedListNode* right = erased->next;
				left->next = right;
				right->prev = left;
				erased->next = erased->prev = nullptr;
				delete erased;
			}

		}

	}

};

int main()
{
	
	TwoLinkLinkedList lst;

	for (int i = 1; i <= 5; i++)
	{
		lst.PushBack(-1 * i);
		lst.PushFront(i);
	}

	lst.Print();
	lst.Erase(-2);
	lst.Print();
	lst.Erase(3);
	lst.Print();
	lst.Erase(23);
	lst.Print();
	
}