#include <iostream>

using namespace std;

class NodeLinkedList
{

public:

	int value;
	NodeLinkedList* next;
	NodeLinkedList(int _value)
	{
		value = _value;
		next = nullptr;
	}

};

class OneLinkLinkedList
{

private:
	NodeLinkedList* head;
	NodeLinkedList* tail;

public:

	OneLinkLinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	~OneLinkLinkedList()
	{
		while (head != nullptr)
		{
			PopFront();
		}
	}

	void PushBack(int _value)
	{

		NodeLinkedList* NewNode = new NodeLinkedList(_value);

		if (head == nullptr)
		{
			head = tail = NewNode;
			return;
		}

		else
		{
			tail->next = NewNode;
			tail = NewNode;
			return;
		}
		
	}

	void PushFront(int _value)
	{

		NodeLinkedList* NewNode = new NodeLinkedList(_value);

		if (head == nullptr)
		{
			head = tail = NewNode;
			return;
		}

		else
		{
			NewNode->next = head;
			head = NewNode;
			return;
		}

	}

	void Print()
	{
		if (head == nullptr) return;

		else
		{
			NodeLinkedList* temp = head;
			while (temp != nullptr)
			{
				cout << temp->value << " ";
				temp = temp->next;
			}
		}
		return;
	}

	void PopFront()
	{
		if (head == nullptr) return;

		else if (head == tail)
		{
			delete head;
			head = tail = nullptr;
			return;
		}

		else
		{
			NodeLinkedList* temp = head->next;
			head->next = nullptr;
			delete head;
			head = temp;
			return;
		}
	}

	void PopBack()
	{
		if (head == nullptr) return;

		else if (head == tail)
		{
			delete head;
			head = tail = nullptr;
		}

		else
		{
			NodeLinkedList* temp = head;
			while (temp->next != tail) temp = temp->next;
			temp->next = nullptr;
			delete tail;
			tail = temp;
		}
	}

	NodeLinkedList* Get(int _value)
	{

		if (head == nullptr) return nullptr;

		NodeLinkedList* temp = head;

		while (temp->value != _value && temp != nullptr)
		{
			temp = temp->next;
		}

		return temp;
	}

	void Insert(int place, int _value)
	{

		if (head == nullptr || place <= 0) PushFront(_value);

		int currentplace = 1;
		NodeLinkedList* temp = head;

		while (currentplace != place && temp != nullptr)
		{
			temp = temp->next;
			currentplace++;
		}

		if (temp == nullptr) PushBack(_value);

		else
		{
			NodeLinkedList* NewNode = new NodeLinkedList(_value);
			NewNode->next = temp->next;
			temp->next = NewNode;
			return;
		}
	}

	void Erase(int place)
	{

		if (head == nullptr || place <= 0) return;

		if (place == 1 && head != nullptr) PopFront();

		NodeLinkedList* temp = head->next;
		NodeLinkedList* left = head;
		int currentplace = 2;

		while (currentplace != place && temp != nullptr)
		{
			left = temp;
			temp = temp->next;
			currentplace++;
		}

		if (temp == nullptr) return;

		NodeLinkedList* right = temp->next;

		left->next = right;
		temp->next = nullptr;
		delete temp;

	}

};

int main()
{
	
	OneLinkLinkedList lst;
	
	for (int i = 1; i <= 5; i++)
	{
		lst.PushFront(i);
		lst.PushBack(-1 * i);
	}

	lst.Print();
	cout << endl;

	lst.Erase(1);
	lst.Print();
	cout << endl;
	lst.Erase(4);
	lst.Print();
	cout << endl;


}