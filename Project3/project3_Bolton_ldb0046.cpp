//I used ChatGPT to learn how to use the bubble sort algorithm 

#include <fstream>
#include <iostream>
#include <cstdlib> //for exit()
#include <string>
using namespace std;


const int MAX_SIZE = 100;

int readfile(int inputArray[], ifstream& inStream){ 
    int index = 0;
    inStream >> inputArray[index];
    while (!inStream.eof()) {
        // cout << inputArray[index] << endl;
        index++;
        inStream >> inputArray[index];
    }
    inStream.close();
    return index;
}

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
                // Swap arr[j] and arr[j+1]
                int temp = combinedArray[j];
                combinedArray[j] = combinedArray[j+1];
                combinedArray[j+1] = temp;
            }
        }
    }

    cout << "The sorted list of " << combinedSize
        << " numbers is: ";

    for (int i = 0; i < combinedSize; i++) {
        cout << combinedArray[i] << " " ;
    }
    cout << endl;
    return combinedArray;
}

void writeFile(int* sortedArray, string fileName, int sortedSize) {

    ofstream file(fileName); 

    if (file.is_open()) {  // Check if the file is successfully opened
        for (int i = 0; i < sortedSize; i++) {
            file << sortedArray[i] << " ";  // Write each element to the file
        }
        file.close();  // Close the file
        cout << "File created succesfully." << endl;
    } else {
        cout << "Error writing to file" << endl;
    }
}

int main() {

    int array1[MAX_SIZE];
    int array1_size;
    int array2[MAX_SIZE];
    int array2_size;
    int output[MAX_SIZE];
    
    ifstream inStream;
    string fileName1 = "input1.txt";
    string fileName2 = "input2.txt";
    
    // Input file 1
    inStream.open(fileName1);
    if (inStream.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    array1_size = readfile(array1, inStream);
    inStream.close();

    // input File 2
    inStream.open(fileName2);
    if (inStream.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    array2_size = readfile(array2, inStream);
    inStream.close();

    //Creates and prints out a sorted array of the two arrays
    int* sortedArray = sort(array1, array1_size, array2, array2_size);

    int combinedSize = array1_size + array2_size;
    string fileName3 = "output.txt";
    writeFile(sortedArray, fileName3, combinedSize);

    delete[] sortedArray; // remove managed memory
    return 0;
}
