#include <iostream>
#include <cstdlib>


class Node
{
public:
	Node * next;
	int data;
};

using namespace std;

class LinkedList
{
public:
	int length;
	Node* head;

	LinkedList();
	~LinkedList();
	Node *  add(int index, int data);
	int delNode(int pos);
	void print();
};

LinkedList::LinkedList() {
	this->length = 0;
	this->head = NULL;
}

LinkedList::~LinkedList() {
	std::cout << "LIST DELETED";
}

Node* LinkedList::add(int index, int data) {

	if (index < 0) return NULL;

	int currIndex = 1;
	Node* currNode = head;
	while (currNode && index > currIndex) {
		currNode = currNode->next;
		currIndex++;
	}

	if (index > 0 && currNode == NULL) return NULL;

	Node* newNode = new    Node;
	newNode->data = data;
	if (index == 0) {
		newNode->next = head;
		head = newNode;
		this->length++;
	}
	else {
		newNode->next = currNode->next;
		currNode->next = newNode;
		this->length++;
	}
	return newNode;



}

int LinkedList::delNode(int pos) {
	Node* prevNode = NULL;
	Node* currNode = head;
	int currIndex = 1;
	while (currNode && currNode->data != pos) {
		prevNode = currNode;
		currNode = currNode->next;
		currIndex++;
	}
	if (currNode) {
		if (prevNode) {
			prevNode->next = currNode->next;
			delete currNode;
		}
		else {
			head = currNode->next;
			delete currNode;
		}
		return currIndex;
	}
	return 0;
}

void LinkedList::print() {
	Node* head = this->head;
	int i = 1;
	while (head) {
		std::cout << i << ": " << head->data << endl;
		head = head->next;
		i++;
	}
}

int main(int argc, char const *argv[])
{
	LinkedList* list = new LinkedList();

	//list->add(0,rand() % 10);
	list->add(0, 2);
	list->add(1, 20);

	list->print();
	std::cout << "List Length: " << list->length << std::endl;

	list->delNode(0);
	list->print();
	//delete list;



	return 0;
}