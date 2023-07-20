// I used ChatGPT to learn the syntax of a linked list in C++
#include <iostream>
#include <string>
using namespace std;

int totalPoints = 0;
int totalQuestions = 0;

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
// make a function that runs a game without user input questions. 
// then in main have it ask questions then run the game function.
// Have unit test ask question function and then run the game function 

void inputQuestion (TriviaNode*& start) {
    bool continueInput = true; 
    string continueInputStr;
    string newQuestion;
    string newAnswer;
    string newPointsString;
    int newPoints;
    string userAnswer;
    do {
        // Input Question
        cout << "Enter a question: ";
        getline(cin, newQuestion);
        
        cout << "Enter an answer: ";
        getline(cin, newAnswer);

        cout << "Enter award points: ";
        cin >> newPointsString; 
        newPoints = stoi(newPointsString);
        cin.ignore();
        addTrivia(start, newQuestion, newAnswer, newPoints);

        cout << "Continue? (Yes/No): ";
        cin >> continueInputStr;

        if (continueInputStr == "Yes") {
            continueInput = true;
        }
        else {
            continueInput = false;
        }
        cin.ignore();
    }
    while (continueInput);
    cout << endl;
}

//Is it okay to just input the start of the first node instead of the whole list?
//Can I also input the total questions?
int runGame(TriviaNode*& start, int totalQuestions) {

    if (totalQuestions <= 0) {
        cout << "Warning - the number of trivia to be asked must equal to or be larger than 1." << endl;
        return 1;
    }

    TriviaNode* current = start;
    string userAnswer;
    int countedQuestions = 0;

    while (current != nullptr) {
        countedQuestions++;
        current = current->next;
    }

    if (countedQuestions < totalQuestions) {
        cout << "Warning - There is only " << to_string(countedQuestions) << "in the list." << endl;
        return 1;
    }

    current = start; // Reset current node of linked list to be the start
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

TriviaNode* hardCodedQuestions() {
 
    // Hard coded questions 
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

    totalQuestions = 3;
    return t1;
}

void unitTest () {
    TriviaNode* start = nullptr;

    cout << "***This is a debugging version ***" << endl;

    cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
    assert(1 == runGame(start, 0));
    cout << "Case 1 Passed" << endl << endl;

    start = hardCodedQuestions();
    cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
    assert(0 == runGame(start, 1));
    cout << "Case 2.1 passed" << endl << endl;

    cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
    assert(0 == runGame(start, 1));
    cout << "Case 2.2 passed" << endl << endl;

    cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
    assert(0 == runGame(start, 3));
    cout << "Case 3 passed" << endl << endl;

    cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
    assert(1 == runGame(start, 5));
    cout << "Case 4 passed" << endl << endl;

    cout << "*** End of the Debugging Version ***" << endl;

}

void prod() {
    TriviaNode* start = hardCodedQuestions();

    cout << "*** Welcome to Log's trivia quiz game ***" << endl;
    cout << endl;
    inputQuestion(start);
    runGame(start, totalQuestions);

    cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;
}

int main() {

    
    // #ifdef PROD
        prod();
    // #endif

    // #ifdef UNIT_TESTING
        // unitTest();
    // #endif

    return 0;
}
