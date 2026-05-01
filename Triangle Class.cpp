//Create a Triangle class. Add exception 
//handling statements to ensure the following 
//conditions: all sides are greater than 0 and
// sum of any two sides is greater than the third side. The class should also have overloaded functions for calculating the area of a right angled triangle as well as using Heron's formula to calculate the area of any type of triangle.
#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
    float a, b, c;

public:
    void input() {
        cout << "Enter three sides: ";
        cin >> a >> b >> c;

        // Exception conditions
        if (a <= 0 || b <= 0 || c <= 0)
            throw "Sides must be greater than 0!";

        if ((a + b <= c) || (a + c <= b) || (b + c <= a))
            throw "Invalid triangle (Triangle inequality failed)!";
    }

    // Heron's Formula (general triangle)
    float area() {
        float s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    // Overloaded function (Right-angled triangle)
    float area(float base, float height) {
        return 0.5 * base * height;
    }
};

int main() {
    Triangle t;
    int choice;

    try {
        t.input();

        cout << "\n1. Area using Heron's Formula\n2. Area of Right-Angled Triangle\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Area = " << t.area();
        }
        else if (choice == 2) {
            float base, height;
            cout << "Enter base and height: ";
            cin >> base >> height;
            cout << "Area = " << t.area(base, height);
        }
        else {
            cout << "Invalid choice!";
        }
    }
    catch (const char* msg) {
        cout << "Exception: " << msg << endl;
    }

    return 0;
}