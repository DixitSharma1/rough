//Create a class Student containing fields for Roll No., Name, Class, Year and Total Marks. Write a program to store 5 objects of Student class in a file. Retrieve these records from the file and display them.
#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int rollNo;
    char name[50];
    char className[20];
    int year;
    float marks;

    void getData() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Class: ";
        cin >> className;
        cout << "Enter Year: ";
        cin >> year;
        cout << "Enter Total Marks: ";
        cin >> marks;
    }

    void showData() {
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nClass: " << className;
        cout << "\nYear: " << year;
        cout << "\nMarks: " << marks << endl;
    }
};

int main() {
    Student s;
    

    ofstream outFile("student.dat", ios::binary);

    for (int i = 0; i < 5; i++) {
        cout << "\nEnter details of student " << i + 1 << ":\n";
        s.getData();
        outFile.write((char*)&s, sizeof(s));
    }

    outFile.close();

    ifstream inFile("student.dat", ios::binary);

    cout << "\n\nStored Student Records:\n";

    while (inFile.read((char*)&s, sizeof(s))) {
        s.showData();
    }

    inFile.close();

    return 0;
}