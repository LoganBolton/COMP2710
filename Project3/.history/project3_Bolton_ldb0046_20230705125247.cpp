#include <fstream>
#include <iostream>
#include <cstdlib> //for exit()
using namespace std;

int readfile(int inputArray[], ifstream& inStream){ int index;
    inStream >> inputArray[index];
    while (! inStream.eof()) {
        cout << inputArray[index] << endl;
        index++;
        inStream >> inputArray[index];
}
    return index;
}

int main( ) {
    ifstream inStream1;
    int iArray1[MAX_SIZE];
    int iArray1_size;
    int iArray2[MAX_SIZE];
    int iArray2_size;
    inStream1.open("input1.txt");
    // iArray1_size = readfile(inputAry, inStreamFirst);
    inStreamFirst.close( );
return 0; }

