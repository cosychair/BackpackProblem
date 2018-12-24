#pragma once
#include <iostream>
#include "Iterator.h"

using namespace std;

class List {
private:
	class Node {
	public:
		Thing *data;
		Node *next;
		Node *prev;
		Node(Thing * data = nullptr, Node *next = nullptr, Node *prev = nullptr) : data(data), next(next), prev(prev) {};
		~Node() {
			next = nullptr;
			delete next;
			prev = nullptr;
			delete prev;
		};
	};
	Node *head;
	Node *tail;
	size_t size;
public:
	List(Node *head = nullptr, Node *tail = nullptr, size_t size = 0){
		this->head = head;
		this->tail = (tail) ? tail : head;
		this->size = size;
	};
	~List();
	void pushBack(Thing * data); // добавление в конец списка
	void pushFront(Thing * data); // добавление в начало списка
	void popBack(); // удаление последнего элемента
	void popFront(); // удаление первого элемента
	size_t getSize(); // получение размера списка
	void clear(); // удаление всех элементов списка
	bool isEmpty(); // проверка на пустоту списка
	Thing* front();
	Thing* back();
	void printToConsole();
	//методы итератора
	class ListIterator: public Iterator {
	private:
		Node *cur;
	public:
		ListIterator(Node *start) {
			cur = start;
		};
		void next();
		bool hasNext();
		Thing* current();
	};
	Iterator* createIterator() {
		return new ListIterator(head);
	}
};

