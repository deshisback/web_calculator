#include <iostream>

using namespace std;

class LinkedListNode
{

public:

	int value;
	LinkedListNode* next;

	LinkedListNode(int _value)
	{
		value = _value;
		next = nullptr;
	}

};

class OneLinkLinkedList
{

private:

	LinkedListNode* head;
	LinkedListNode* tail;

public:

	OneLinkLinkedList()
	{
		head = tail = nullptr;
	}

	void PushBack(int _value)
	{

		LinkedListNode* NewNode = new LinkedListNode(_value);

		if (head == nullptr)
		{
			head = tail = NewNode;
			head->next = tail;
			tail->next = head;
		}

		else
		{
			tail->next = NewNode;
			tail = NewNode;
			tail->next = head;
		}

	}

	void PushFront(int _value)
	{

		LinkedListNode* NewNode = new LinkedListNode(_value);

		if (head == nullptr)
		{
			head = tail = NewNode;
			head->next = tail;
			tail->next = head;
		}

		else
		{
			NewNode->next = head;
			head = NewNode;
			tail->next = head;
		}

	}

	void Print()
	{

		LinkedListNode* temp = head;
		if (temp == nullptr) return;

		do
		{
			cout << temp->value << " ";
			temp = temp->next;
		} while (temp != head);
		cout << endl;
	}

	void PopBack()
	{

		if (head == nullptr) return;

		else if (head == tail)
		{
			head->next = nullptr;
			tail->next = nullptr;
			delete head;
			return;
		}

		else
		{
			LinkedListNode* temp = head;

			while (temp->next != tail)
			{
				temp = temp->next;
			}

			temp->next = nullptr;
			tail->next = nullptr;
			delete tail;
			tail = temp;
			tail->next = head;
		}

	}

	void PopFront()
	{

		if (head == nullptr) return;

		if (head == tail)
		{
			head->next = nullptr;
			tail->next = nullptr;
			delete head;
			return;
		}

		else 
		{
			LinkedListNode* temp = head->next;
			head->next = nullptr;
			tail->next = nullptr;
			delete head;
			head = temp;
			tail->next = head;
		}

	}

	LinkedListNode* Get(int _value)
	{

		if (head == nullptr) return nullptr;

		LinkedListNode* temp = head;

		do
		{
			if (temp->value == _value) return temp;
			temp = temp->next;
		} while (temp != head);

		return nullptr;

	}

	void Insert(int place, int _value)
	{

		if (head == nullptr || place <= 0) PushBack(_value);

		else
		{
			LinkedListNode* NewNode = new LinkedListNode(_value);
			LinkedListNode* left = head;
			int currentplace = 1;

			while (currentplace != place)
			{
				left = left->next;
				currentplace++;
			}


			if (left == tail)
			{
				left->next = NewNode;
				tail = NewNode;
				tail->next = head;
			}

			else
			{
				LinkedListNode* right = left->next;
				left->next = NewNode;
				NewNode->next = right;
			}
		}

	}

	void Erase(int place)
	{

		if (head == nullptr) return;

		if (place <= 1) PopFront();

		else
		{

			int currentplace = 2;
			LinkedListNode* temp = head->next;
			LinkedListNode* left = head;

			while (currentplace != place)
			{
				currentplace++;
				temp = temp->next;
				left = left->next;
			}

			if (temp == head)
			{
				PopFront();
				return;
			}

			else if (temp == tail)
			{
				PopBack();
				return;
			}

			else
			{
				LinkedListNode* right = temp->next;
				left->next = right;
				temp->next = nullptr;
				delete temp;
			}

		}

	}

};

int main()
{
	OneLinkLinkedList lst;

	for (int i = 1; i <= 5; i++)
	{
		lst.PushBack(-1 * i);
		lst.PushFront(i);
	}
	lst.Print();
	lst.Erase(-1);
	lst.Print();
	lst.Erase(3);
	lst.Print();
	lst.Erase(31);
	lst.Print();
}