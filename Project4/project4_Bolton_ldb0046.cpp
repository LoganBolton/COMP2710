// I used GeeksForGeeks to learn how to structure a linked list with C++ syntax
#include <iostream>
#include <string>
using namespace std;

int totalPoints = 0;
int totalQuestions = 3; //Always at least 3 questions

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


bool isCorrect (string answer, TriviaNode*& n) {
    if (answer == n->answer) {
        return true;
    }
    else {
        return false;
    }
}

int main() {

    string newQuestion;
    string newAnswer;
    int newPoints;
    string newPointsString;
    string userAnswer;

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
    
    cout << "*** Welcome to Log's trivia quiz game ***" << endl;

    // Input Question
    cout << "Enter a question: ";
    getline(cin, newQuestion);
    // cin >> newQuestion;
    
    cout << "Enter an answer: ";
    getline(cin, newAnswer);
    // cin >> newAnswer;


    cout << "Enter award points: ";
    // getline(cin, newPointsString);
    cin >> newPointsString; 
    newPoints = stoi(newPointsString);
    cin.ignore();
    addTrivia(t1, newQuestion, newAnswer, newPoints);
    
    cout << endl;
    TriviaNode* current = t1;
    for (int i = 0; i < totalQuestions; i++) {
        cout << "Question: " << current->question << endl;
        cout << "Answer: ";
        getline(cin, userAnswer);

        if (isCorrect(userAnswer, current)) {
            cout << "Your answer is correct. ";
            cout << "You receive " + to_string(current->points) + " points." << endl;
            totalPoints += current->points;
            cout << "Your Total Points: " + to_string(totalPoints) << endl;
        }
        else {
            cout << "Your answer is wrong. ";
            cout << "The correct answer is: " + current->answer << endl;
            cout << "Your Total Points: " + to_string(totalPoints) << endl;

        }

        current = current->next;
        cout << endl;
    }

    return 0;
}
