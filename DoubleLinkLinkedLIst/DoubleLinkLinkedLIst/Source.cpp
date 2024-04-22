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

class TwoLinksLinkedList
{

private:

	LinkedListNode* head;
	LinkedListNode* tail;

public:

	TwoLinksLinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	~TwoLinksLinkedList()
	{
		while (head != nullptr)
		{
			PopFront();
		}
	}

	void PushFront(int _value)
	{

		LinkedListNode* NewNode = new LinkedListNode(_value);

		if (head == nullptr)
		{
			head = tail = NewNode;
		}

		else
		{
			NewNode->next = head;
			head->prev = NewNode;
			head = NewNode;
		}

	}

	void PushBack(int _value)
	{

		LinkedListNode* NewNode = new LinkedListNode(_value);

		if (head == nullptr)
		{
			head = tail = NewNode;
		}

		else
		{
			tail->next = NewNode;
			NewNode->prev = tail;
			tail = NewNode;
		}

	}

	void PopFront()
	{

		if (head == nullptr) return;

		else if (head == tail)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}

		else
		{
			LinkedListNode* temp = head->next;
			temp->prev = nullptr;
			head->next = nullptr;
			delete head;
			head = temp;
		}

	}

	void PopBack()
	{

		if (head == nullptr) return;

		else if (head == tail)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}

		else
		{
			LinkedListNode* temp = tail->prev;
			temp->next = nullptr;
			tail->prev = nullptr;
			delete tail;
			tail = temp;
		}

	}

	LinkedListNode* Get(int _value)
	{

		if (head == nullptr) return nullptr;

		else
		{
			LinkedListNode* temp = head;

			while (temp != nullptr)
			{
				if (temp->value == _value) return temp;
				temp = temp->next;
			}

			return temp;
		}

	}

	void Print()
	{

		LinkedListNode* temp = head;

		while (temp != nullptr)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}

		cout << endl;
	}

	void Insert(int place, int _value)
	{
		if (head == nullptr || place <= 0) PushFront(_value);
		
		else
		{
			int currentplace = 1;
			LinkedListNode* NewNode = new LinkedListNode(_value);
			LinkedListNode* left = head;

			while (currentplace != place && left != nullptr)
			{
				left = left->next;
				currentplace++;
			}

			if (left == nullptr || left->next == nullptr) PushBack(_value);
			LinkedListNode* right = left->next;

			left->next = NewNode;
			NewNode->next = right;
			right->prev = NewNode;
			NewNode->prev = left;
		}

	}

	void Erase(int place)
	{

		if (head == nullptr) return;

		else if (place <= 1) PopFront();

		else
		{
			int currentplace = 2;
			LinkedListNode* temp = head->next;

			while (currentplace != place && temp != nullptr)
			{
				currentplace++;
				temp = temp->next;
			}

			if (temp == nullptr) PopBack();
			else if (temp->next == nullptr)PopBack();

			else
			{
				LinkedListNode* left = temp->prev;
				LinkedListNode* right = temp->next;
				left->next = right;
				right->prev = left;
				temp->next = nullptr;
				temp->prev = nullptr;
				delete temp;
			}
		}
	}

};

int main()
{
	TwoLinksLinkedList lst;

	for (int i = 1; i <= 5; i++)
	{
		lst.PushFront(i);
		lst.PushBack(-1 * i);
	}
	lst.Print();
	
	lst.Insert(1, 155);
	lst.Insert(4, 200);
	lst.Print();

	lst.Erase(1);
	lst.Print();
	lst.Erase(6);
	lst.Print();
	lst.Erase(100);
	lst.Print();
}