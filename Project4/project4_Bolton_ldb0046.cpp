// I used GeeksForGeeks to learn how to structure a linked list with C++ syntax
#include <iostream>
#include <string>
using namespace std;

// There will always be at least 3 questions 
int totalQuestions = 3;

struct TriviaNode {
    string question;
    string answer;
    int points;
    TriviaNode* next;

    TriviaNode(
        string questionInput, 
            string answerInput, 
            int pointsInput, 
            TriviaNode* nextInput = nullptr)

        : question(questionInput), 
            answer(answerInput), 
            points(pointsInput), 
            next(nextInput) {}
};

void addTrivia(TriviaNode*& start, string question, string answer, int points) {
    TriviaNode* newNode = new TriviaNode(question, answer, points);
    TriviaNode* current = start;
    while (current->next != nullptr) { // goes to end of linked list
        current = current->next;
    }

    current->next = newNode;

    totalQuestions++;
}

int main() {

    //hard coded questions
    TriviaNode* t1 = new TriviaNode(
        "How long was the shortest war on record? (Hint: how many minutes)", 
        "38", 
        100
    );
    TriviaNode* t2 = new TriviaNode(
        "What was Bank of America’s original name? (Hint: Bank of Italy or Bank of Germany)", 
        "Bank of Italy", 
        50
    );
    TriviaNode* t3 = new TriviaNode(
        "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)",
        "Wii Sports",
        20
    );

    t1->next = t2;
    t2->next = t3;
    
    addTrivia(t1, "When was C++ created?", "1979", 75);

    TriviaNode* current = t1;
    while (current != nullptr) {
        cout << current->question << endl;
        current = current->next;
    }

    return 0;
}