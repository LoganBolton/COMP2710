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

void deleteNode(Node*& head, std::string data) {
    if (head == NULL) {
        return;
    }

    if (head->data == data) {
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
        return;
    }

    Node* prev = head;
    Node* current = head->next;
    while (current != NULL) {
        if (current->data == data) {
            prev->next = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
	Node* n4 = new Node("4");
	Node* n3 = new Node("3", n4);
	Node* n2 = new Node("2", n3);
	Node* n1 = new Node("1", n2);

	deleteNode(n1, "1");
	traverse(n1); // Traverse the list starting from n1

	return 0;
}

 
