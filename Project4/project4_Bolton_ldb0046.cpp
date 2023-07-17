
#include <iostream>
#include <string>
using namespace std;

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


int main() {

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
    
    TriviaNode* current = t1;
    while (current != nullptr) {
        cout << current->question << endl;
        current = current->next;
    }

    return 1;
}