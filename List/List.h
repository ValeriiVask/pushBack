#pragma once
#include <exception>
#include <stdexcept>

template <typename T>
class List
{
private:
	struct Node
	{
		Node(T value) noexcept
		{
			this->value = value;
			next = nullptr;
			prev = nullptr;
		}
		T value;
		Node* next;
		Node* prev;
	};

	Node* head;
	Node* tail;

public:
	List() noexcept
	{
		head = nullptr;
		tail = nullptr;
	}

	~List()
	{
		while (head != nullptr)
		{
			Node* tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	size_t size() const noexcept
	{
		int nodeCount = 0;
		Node* nodePtr = head;
		while (nodePtr != nullptr)
		{
			++nodeCount;
			nodePtr = nodePtr->next;
		}
		return nodeCount;
	}

	void pushFront(T value)
	{
		Node* newNode = new Node(value);
		newNode->next = head;
		if (head != nullptr)
			head->prev = newNode;
		else
			tail = newNode;
		head = newNode;
	}

	void pushBack(T value)
	{
		//TODO Implement the pushBack method that adds a new element at the end of the list.

	}

	T popBack()
	{
		if (tail == nullptr)
			throw std::exception("List is empty.");
		Node* tmp = tail;
		tail = tail->prev;
		if (tail != nullptr)
			tail->next = nullptr;
		else
			head = nullptr;
		T value = tmp->value;
		delete tmp;
		return value;
	}
};
