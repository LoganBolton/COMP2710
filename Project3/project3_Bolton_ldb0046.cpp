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

int sort(int array1[], int array1_size, int array2[], int array2_size, int output[]) {
    int combinedSize = array1_size + array2_size;
    int combinedArray[combinedSize];
    for (int i = 0; i < array1_size; i++) {
        output[i] = array1[i];
    }

    for (int i = 0; i < array2_size; i++) {
        output[i+array1_size] = array2[i];
    }

    for (int i = 0; i < combinedSize; i++) {
        cout << output[i] << endl;
    }

    return combinedSize;
}

int main( ) {

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

    sort(array1, array1_size, array2, array2_size, output);
    return 0;
}

