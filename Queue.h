#pragma once
#include <iostream>
#include "Thing.h"
using namespace std;

class Queue {
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
	Queue(Node *head = nullptr, Node *tail = nullptr, size_t size = 0){
		this->head = head;
		this->tail = (tail) ? tail : head;
		this->size = size;
	};
	~Queue();
	void pushBack(Thing * data); // добавление в конец списка
	void pushFront(Thing * data); // добавление в начало списка
	void popBack(); // удаление последнего элемента
	void popFront(); // удаление первого элемента
	size_t getSize(); // получение размера списка
	void clear(); // удаление всех элементов списка
	bool isEmpty(); // проверка на пустоту списка
	void* front();
	void* back();
	void printToConsole();
};

