//Logan Bolton - ldb0046
//project1_Bolton_ldb0046
//I used ChatGPT to learn the format of the bubble sort algorithm 
//Compile : g++ project3_Bolton_ldb0046.cpp
//Run : ./a.out

//Questions 
// Can I use the bubble sort algorithm?
// Are input comments correct?
// Are the variables in the main function conisidered global variables?

#include <fstream>
#include <iostream>
#include <cstdlib> //for exit()
using namespace std;

const int MAX_SIZE = 100;

//Prints out the integers in the inputted file name.
//Input: 1) The array whose length is going to be determined.
//       2) input file stream object
//       3) the name of file that the array is from
//Output: returns the length of the inputted array
int readfile(int inputArray[], ifstream& inStream, string fileName){ 
    int index = 0;
    inStream >> inputArray[index];
    while (!inStream.eof()) {
        index++;
        inStream >> inputArray[index]; // Writes the current line to the array
    }
    inStream.close();

    cout << "The list of " << index
        << " numbers is:" << endl;

    for (int i = 0; i < index; i++) { // Prints the array from the file
        cout << inputArray[i] << endl;
    }
    cout << endl;

    return index;
}

// Input: 1) the first array that is to be sorted
//        2) the size of the first array
//        3) the second array that is to be sorted 
//        4) the size of the second array
// Output: Returns the pointer array of the sorted integer array
int* sort(int array1[], int array1_size, int array2[], int array2_size) {
    int combinedSize = array1_size + array2_size;
    int* combinedArray = new int[combinedSize];

    //Create a combined array of array1 and array2
    for (int i = 0; i < array1_size; i++) { 
        combinedArray[i] = array1[i];
    }
    for (int i = 0; i < array2_size; i++) {
        combinedArray[i+array1_size] = array2[i];
    }

    //Bubble Sort algorithm to sort combined array
    for(int i = 0; i < combinedSize-1; i++) {      
        for (int j = 0; j < combinedSize-i-1; j++) { 
            if (combinedArray[j] > combinedArray[j+1]) {
                // Swap combinedArray[j] and combinedArray[j+1]
                int temp = combinedArray[j];
                combinedArray[j] = combinedArray[j+1];
                combinedArray[j+1] = temp;
            }
        }
    }

    cout << "The sorted list of " << combinedSize << " numbers is: ";

    for (int i = 0; i < combinedSize; i++) {
        cout << combinedArray[i] << " ";
    }
    cout << endl;

    return combinedArray;
}

// Creates a file that contains the provided sorted array
// Input: 1) the pointer array of the sorted integer array
//        2) the name of the new file
//        3) The size of the sorted array
void writeFile(int* sortedArray, string fileName, int sortedSize) {

    ofstream file(fileName); 

    if (file.is_open()) {
        for (int i = 0; i < sortedSize; i++) {
            file << sortedArray[i] << " "; 
        }
        file.close();  // Close the file
        cout << "File created succesfully." << endl;
    } else {
        cout << "Error writing to file" << endl;
    }
}

int main() {
    //Initialized variables
    int array1[MAX_SIZE];
    int array1_size;
    int array2[MAX_SIZE];
    int array2_size;
    int output[MAX_SIZE];
    
    string fileName1;
    string fileName2;
    string fileName3;
    ifstream inStream;
    
    // Begin Program
    cout << "*** Welcome to Logan's sorting program ***" << endl;
    cout << "Enter the first input file name: ";
    cin >> fileName1;

    // Input file 1
    inStream.open(fileName1);
    if (inStream.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    array1_size = readfile(array1, inStream, fileName1); //prints out the file
    inStream.close();

    // Input File 2
    cout << "Enter the second input file name: ";
    cin >> fileName2;

    inStream.open(fileName2);
    if (inStream.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }

    array2_size = readfile(array2, inStream, fileName2); //prints out the file
    inStream.close();

    // Creates and prints out a sorted array of the two arrays
    int* sortedArray = sort(array1, array1_size, array2, array2_size);

    cout << "Enter the output file name: ";
    cin >> fileName3;

    int combinedSize = array1_size + array2_size;
    writeFile(sortedArray, fileName3, combinedSize); // Creates a file from the sorted array

    cout << "*** Please check the new file - " << fileName3 << " ***" << endl;
    cout << "*** Goodbye. ***" << endl;

    delete[] sortedArray; // removes managed memory
    return 0;
}