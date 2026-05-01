//Create a Matrix class. Write a menu-driven program to perform following Matrix operations (exceptions should be thrown by the functions if matrices passed to them are incompatible and handled by the main() function):

//a. Sum

//b. Product

//c. Transpose

#include <iostream>
using namespace std;

class Matrix {
    int rows, cols;
    int mat[10][10];

public:
    void input() {
        cout << "Enter rows and cols: ";
        cin >> rows >> cols;

        cout << "Enter elements:\n";
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> mat[i][j];
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }

    Matrix sum(Matrix m) {
        if (rows != m.rows || cols != m.cols)
            throw "Addition not possible!";

        Matrix temp;
        temp.rows = rows;
        temp.cols = cols;

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                temp.mat[i][j] = mat[i][j] + m.mat[i][j];

        return temp;
    }

    Matrix multiply(Matrix m) {
        if (cols != m.rows)
            throw "Multiplication not possible!";

        Matrix temp;
        temp.rows = rows;
        temp.cols = m.cols;

        for (int i = 0; i < temp.rows; i++) {
            for (int j = 0; j < temp.cols; j++) {
                temp.mat[i][j] = 0;
                for (int k = 0; k < cols; k++)
                    temp.mat[i][j] += mat[i][k] * m.mat[k][j];
            }
        }

        return temp;
    }

    Matrix transpose() {
        Matrix temp;
        temp.rows = cols;
        temp.cols = rows;

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                temp.mat[j][i] = mat[i][j];

        return temp;
    }
};

int main() {
    Matrix m1, m2, result;
    int choice;

    do {
        cout << "\n1. Sum\n2. Product\n3. Transpose\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Matrix 1:\n";
                    m1.input();
                    cout << "Matrix 2:\n";
                    m2.input();
                    result = m1.sum(m2);
                    cout << "Result:\n";
                    result.display();
                    break;

                case 2:
                    cout << "Matrix 1:\n";
                    m1.input();
                    cout << "Matrix 2:\n";
                    m2.input();
                    result = m1.multiply(m2);
                    cout << "Result:\n";
                    result.display();
                    break;

                case 3:
                    cout << "Matrix:\n";
                    m1.input();
                    result = m1.transpose();
                    cout << "Transpose:\n";
                    result.display();
                    break;

                case 4:
                    cout << "Exiting...";
                    break;

                default:
                    cout << "Invalid choice!";
            }
        }
        catch (const char* msg) {
            cout << "Exception: " << msg << endl;
        }

    } while (choice != 4);

    return 0;
}