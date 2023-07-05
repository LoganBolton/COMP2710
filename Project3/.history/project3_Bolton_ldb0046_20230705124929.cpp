#include <fstream>
#include <iostream>
#include <cstdlib> //for exit()
using namespace std;
int main()
{
    ifstream inStream;
    int data;
    cout << "file name:";
    // cin >> filename;
    // cout << "entered filename is:" << filename << endl;

    // Pass the file name as an array of chars to open()
    // inStream.open(filename);
    // inStream.open((char*)filename.c_str());
    if (inStream.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    inStream >> data;
    while (!inStream.eof()) {
        cout << data << endl;
        inStream >> data;
    }
    inStream.close();
    return 0;
}
