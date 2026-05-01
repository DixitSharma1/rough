//Copy the contents of one text file to another file, after removing all whitespaces.

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("input.txt");   
    ofstream outFile("output.txt"); 

    char ch;

    if (!inFile) {
        cout << "Error opening input file!";
        return 1;
    }

    if (!outFile) {
        cout << "Error opening output file!";
        return 1;
    }

    while (inFile.get(ch)) {
       
        if (ch != ' ' && ch != '\n' && ch != '\t') {
            outFile.put(ch);
        }
    }

    cout << "File copied successfully without whitespaces.";

    inFile.close();
    outFile.close();

    return 0;
}