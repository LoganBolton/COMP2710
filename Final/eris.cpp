#include <iostream>
#include <string>
using namespace std;

struct Node {
	string data;
	Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void traverse() {
	Node* current = head;
	while (current != NULL) {
		cout << current->data << endl;
		current = current->next;
	}
}

void addNode(string dataInput) {
	Node* current = head;
	Node* newNode = new Node();
	newNode->data = dataInput;
	newNode->next = NULL;
	
	if (head == NULL) {
		head = newNode;
	}
	else {
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}

}
void addIndexNode(string dataInput, int index) {
	int counter = 0;
	Node* current = head;
	Node* newNode = new Node();
	newNode->data = dataInput;
	int currIndex = 0;
	
	//Special casese
	if (index < 0) {
		cout << "invalid index" << endl;
		return;
	}
	
	while (current != NULL) {
		current = current->next;
		counter++;
	}
	if (counter < index) {
		cout << "out of bounds" << endl;
		return;
	}

	if (index == 0) {
		newNode->next = head;
		head = newNode;
		return;
	}


	current = head;
	while (currIndex < index-1) {
		current = current->next;
		currIndex++;
	}

	newNode->next = current->next;
	current->next = newNode;
	
}	
		
		
int main() {
	Node* n1 = new Node();
	Node* n2 = new Node();
	Node* n3 = new Node();
	Node* n4 = new Node();

	n1->data = "a";
	n1->next = n2;

	n2->data = "b";
	n2->next = n3;

	n3->data = "c";
	n3->next = n4;

	n4->data = "d";
	n4->next = nullptr;

	head = n1;


	addIndexNode("z", -9);
	traverse();

	return 0;
} 
