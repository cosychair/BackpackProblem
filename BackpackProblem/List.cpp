#include "List.h"

List::~List() {
	clear();
}

void List::pushBack(Thing* data) {
	if (isEmpty()) {
		head = new Node(data);
		tail = head;
	}
	else {
		tail->next = new Node(data);
		(tail->next)->prev = tail;
		tail = tail->next;
	}
	++size;
}

void List::pushFront(Thing* data) {
	if (isEmpty()) {
		head = new Node(data);
		tail = head;
	}
	else {
		head = new Node(data, head);
		(head->next)->prev = head;
	}
	++size;
}

void List::popBack() {
	if (!isEmpty()) {
		if (size == 1)
			head = tail = nullptr;
		else {
			Node *tmp = tail->prev;
			delete tail;
			tail = tmp;
			tail->next = nullptr;
		}
		--size;
	}
}

void List::popFront() {
	if (!isEmpty()) {
		if (size == 1)
			head = tail = nullptr;
		else {
			Node *tmp = head->next;
			delete head;
			head = tmp;
			head->prev = nullptr;
		}
		--size;
	}
}


size_t List::getSize() {
	return size;
}

void List::clear() {
	while (size!=0) popFront();
}

bool List::isEmpty() {
	return size == 0;
}

Thing* List::front() {
	return head->data;
}

Thing* List::back() {
	return tail->data;
}

void List::printToConsole() {
	cout << "List: " << endl;
	if (head)
		for (Node *tmp = head; tmp; tmp = tmp->next) tmp->data->printThing();
	else
		cout << "is empty" << endl;
}

void List::ListIterator::next(){
	if (cur == nullptr) 
		throw out_of_range("The next element does not exist");
	cur = cur->next;
}

bool List::ListIterator::hasNext(){
	return cur!=nullptr;
}

Thing* List::ListIterator::current(){

	return cur->data;
}


