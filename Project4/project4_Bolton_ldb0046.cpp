//Logan Bolton - ldb0046
//project4_Bolton_ldb0046
//I used ChatGPT to learn the syntax of a linked list in C++.
//I also used ChatGPT to learn how to simulate user input in the inputQuestion test driver.
//Compile : g++ project4_Bolton_ldb0046.cpp
//Run : ./a.out

#include <iostream>
#include <sstream> 
#include <string>
#include <assert.h>
using namespace std;

int totalPoints = 0;
int totalQuestions = 0;

// Linked list of trivia questions
struct TriviaNode {
    string question;
    string answer;
    int points;
    TriviaNode* next;

    TriviaNode(
        string questionInput, 
        string answerInput, 
        int pointsInput, 
        TriviaNode* nextInput = NULL)

        : question(questionInput), 
            answer(answerInput), 
            points(pointsInput), 
            next(nextInput) {}
};

// Adds a question to the linked list of questions
// Inputs:
//      start - pointer to the first node in the linked list of questions
//      question - question that is to be added
//      answer - answer to the inputted question
//      points - amount of the points awarded for correctly answering the inputted question
TriviaNode* addTrivia(TriviaNode*& start, string question, string answer, int points) {
    TriviaNode* newNode = new TriviaNode(question, answer, points);
    TriviaNode* current = start;
    while (current->next != NULL) { // goes to end of linked list
        current = current->next;
    }

    current->next = newNode;
    totalQuestions++;
    return newNode; 
}

// Checks if the inputted answer corresponds to the answer in the linked list
// Inputs:
//      answer - user inputted question
//      n - the pointer for the node that points to the correct answer
bool isCorrect (string answer, TriviaNode*& n) {
    if (answer == n->answer) {
        return true;
    }
    else {
        return false;
    }
}

// Function that allows the user to input custom questions to the quiz
// Input:
//      start - pointer to the first node in the list of trivia questions
void inputQuestion (TriviaNode*& start) {
    bool continueInput = true; 
    string continueInputStr;
    string newQuestion;
    string newAnswer;
    int newPoints;
    string userAnswer;
    do {
        // Input Question
        cout << "Enter a question: ";
        getline(cin, newQuestion);
        
        cout << "Enter an answer: ";
        getline(cin, newAnswer);

        cout << "Enter award points: ";
        cin >> newPoints; 
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

// Runs the part of the game where the user answers questions
// Inputs:
//      start - pointer to the first node in the linked list of questions
//      totalQuestions - total number of questions that the user is prompted to answer
int runGame(TriviaNode*& start, int totalQuestions) {

    if (totalQuestions <= 0) { // Checks for invalid input
        cout << "Warning - the number of trivia to be asked must equal to or be larger than 1." << endl;
        return 1;
    }

    TriviaNode* current = start;
    string userAnswer;
    int countedQuestions = 0;
    stringstream ss;

    while (current != NULL) { // Counts the total amount of questions that are actually in the linked list
        countedQuestions++;
        current = current->next;
    }

    if (countedQuestions < totalQuestions) { // Checks for invalid input
        ss << "Warning - There is only " << countedQuestions << " trivia in the list." << endl << endl;
        return 1;
    }

    current = start; // Reset current node of linked list to be the start of the list
    for (int i = 0; i < totalQuestions; i++) {
        cout << "Question: " << current->question << endl;
        cout << "Answer: ";
        getline(cin, userAnswer);

        if (isCorrect(userAnswer, current)) {
            std::stringstream ss;
            ss << "Your answer is correct. ";
            ss << "You receive " << current->points << " points." << std::endl;
            totalPoints += current->points;
            ss << "Your Total Points: " << totalPoints << std::endl;
            std::cout << ss.str();
        }
        else {
            std::stringstream ss;
            ss << "Your answer is wrong. ";
            ss << "The correct answer is: " << current->answer << std::endl;
            ss << "Your Total Points: " << totalPoints << std::endl;
            std::cout << ss.str();
        }

        current = current->next; // Moves to next node in the linked list
        cout << endl;
    }

    return 0;
}

// Creates the hard coded trivia questions
// Output:
//      Returns the pointer to the first hard coded question.
TriviaNode* hardCodedQuestions() {
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


// Test driver for addTrivia
void testAddTrivia() {

    TriviaNode* start = hardCodedQuestions(); // first node in the list
    TriviaNode* createdNode = addTrivia(start, "question", "answer", 1);
    assert(createdNode->question == "question");
    assert(createdNode->answer == "answer");
    assert(createdNode->points == 1);

    TriviaNode* createdNode2 = addTrivia(start, "", "", 0);
    assert(createdNode2->question == "");
    assert(createdNode2->answer == "");
    assert(createdNode2->points == 0);

    TriviaNode* createdNode3 = addTrivia(start, "atoesnuthaoneuhnsatohensuhansotehunshaonethunsahoetuhnsaothensuaonethunstaohnseuthansoethunstaohnesuthansotehunsthaonsetuhnsaothensuthaonsethua"
                                                , "atoesnuthaoneuhnsatohensuhansotehunshaonethunsahoetuhnsaothensuaonethunstaohnseuthansoethunstaohnesuthansotehunsthaonsetuhnsaothensuthaonsethua"
                                                , 999999999);
    assert(createdNode3->question == "atoesnuthaoneuhnsatohensuhansotehunshaonethunsahoetuhnsaothensuaonethunstaohnseuthansoethunstaohnesuthansotehunsthaonsetuhnsaothensuthaonsethua");
    assert(createdNode3->answer == "atoesnuthaoneuhnsatohensuhansotehunshaonethunsahoetuhnsaothensuaonethunstaohnseuthansoethunstaohnesuthansotehunsthaonsetuhnsaothensuthaonsethua");
    assert(createdNode3->points == 999999999);
}

void testIsCorrect () {

    TriviaNode* current = hardCodedQuestions(); // first node in the list
    
    string testQuestion = "How long was the shortest war on record? (Hint: how many minutes)";
    string testAnswer = "38";
    while (current != NULL) { // finds the question
        if (current->question == testQuestion) {
            assert(current->answer == testAnswer); 
        }
        current = current->next;
    }

    current = hardCodedQuestions();
    testQuestion = "What was Bank of America’s original name? (Hint: Bank of Italy or Bank of Germany)";
    testAnswer = "Bank of Italy";
    while (current != NULL) {
        if (current->question == testQuestion) {
            assert(current->answer == testAnswer); 
        }
        current = current->next;
    }

    current = hardCodedQuestions();
    TriviaNode* createdNode = addTrivia(current, "testQuestion1", "testAnswer1", 3);
    testQuestion = "testQuestion1";
    testAnswer = "testAnswer1";
    while (current != NULL) {
        if (current->question == testQuestion) {
            assert(current->answer == testAnswer); 
        }
        current = current->next;
    }
}

void testInputQuestion() {
    TriviaNode* start = hardCodedQuestions(); // first node in the list
    TriviaNode* current = start;
    istringstream testInput("Test question\nTest answer\n10\nNo\n");
    streambuf* origCin = cin.rdbuf(testInput.rdbuf());
    inputQuestion(start);
    while (current->next != NULL) {
        current = current->next;
    }
    
    assert(current->question == "Test question");
    assert(current->answer == "Test answer");
    assert(current->points == 10);
    // Clean up
    cin.rdbuf(origCin);

    current = start;
    istringstream testInput2("\n\n0\nNo\n");
    origCin = cin.rdbuf(testInput2.rdbuf());
    inputQuestion(start);
    while (current->next != NULL) {
        current = current->next;
    }
    
    assert(current->question == "");
    assert(current->answer == "");
    assert(current->points == 0);
    // Clean up
    cin.rdbuf(origCin);

    current = start;
    istringstream testInput3("aoebtuhatoehbutnaoaoteunthaboetnhubhbetnuhbatnhoeuatoheuthb\naoebtuhatoehbutnaoaoteunthaboetnhubhbetnuhbatnhoeuatoheuthb\n99999\nNo\n");
    origCin = cin.rdbuf(testInput3.rdbuf());
    inputQuestion(start);
    while (current->next != NULL) {
        current = current->next;
    }
    
    assert(current->question == "aoebtuhatoehbutnaoaoteunthaboetnhubhbetnuhbatnhoeuatoheuthb");
    assert(current->answer == "aoebtuhatoehbutnaoaoteunthaboetnhubhbetnuhbatnhoeuatoheuthb");
    assert(current->points == 99999);
    // Clean up
    cin.rdbuf(origCin);
}

// Debugging version of the program
void debugTest () {
    #ifdef UNIT_TESTING
        TriviaNode* start = NULL;

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

        totalPoints = 0;
        cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
        assert(0 == runGame(start, 3));
        cout << "Case 3 passed" << endl << endl;

        cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
        assert(1 == runGame(start, 5));
        cout << "Case 4 passed" << endl << endl;

        cout << "Test Drivers testing..." << endl;
        testAddTrivia();
        testIsCorrect();
        cout << "Testing \"inputQuestion\" Method:" << endl; //Is this Okay?
        testInputQuestion();
        cout << endl << "Success" << endl << endl;
        cout << "*** End of the Debugging Version ***" << endl;
    #endif
}

int main() {
    // Unit Tests
    #ifdef UNIT_TESTING
        debugTest();
    #else
    // Production Code
    TriviaNode* start = hardCodedQuestions();
    cout << "*** Welcome to Log's trivia quiz game ***" << endl;
    inputQuestion(start);
    runGame(start, totalQuestions);

    cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;

    #endif 
    return 0; // success
}