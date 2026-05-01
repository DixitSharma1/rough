//Define a class Person having name as a data member. Inherit two classes Student and Employee from Person. Student has additional attributes as course, marks and year and Employee has department and salary. Write display() method in all the three classes to display the corresponding attributes. Provide the necessary methods to show runtime polymorphism.

#include <iostream>
using namespace std;

class Person {
protected:
    char name[50];

public:
    void getName() {
        cout << "Enter Name: ";
        cin >> name;
    }

    virtual void display() {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
    char course[30];
    int marks;
    int year;

public:
    void getStudent() {
        getName();
        cout << "Enter Course: ";
        cin >> course;
        cout << "Enter Marks: ";
        cin >> marks;
        cout << "Enter Year: ";
        cin >> year;
    }

    void display() {
        cout << "\n--- Student Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Year: " << year << endl;
    }
};

class Employee : public Person {
    char department[30];
    float salary;

public:
    void getEmployee() {
        getName();
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display() {
        cout << "\n--- Employee Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Person* p;  
    Student s;
    Employee e;

  
    p = &s;
    s.getStudent();
    p->display();  


    p = &e;
    e.getEmployee();
    p->display(); 
    return 0;
}