#include <iostream>
#include <string>

struct Node {
	std::string data;
	Node* next;

	Node(std::string dataInput, Node* nextInput = NULL) : data(dataInput), next(nextInput) {}
	
};

int traverse(Node* n) {
	while (n != NULL) {
		std::cout << n->data << std::endl;
		n = n->next;
	}

	return 0;
}

int deleteNode(Node* head, std::string data) {
	Node* current = head->next;
	while (current != NULL) {
		if (current->data == data) {
			c
		}
	}
}
int main() {
	Node* n4 = new Node("4");
	Node* n3 = new Node("3", n4);
	Node* n2 = new Node("2", n3);
	Node* n1 = new Node("1", n2);

	traverse(n1);
	return 0;
}




