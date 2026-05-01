//Write a program to compute the sum of the first n terms of the following series:

//𝑆 = 1 − 1/2^2 + 1/3^3 −  .... 1/𝑛^n


//The number of terms n is to be taken from the user through the command line. If the command line argument is not found then prompt the user to enter the value of n.
//
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]) {

    int n;

    // Check command line argument
    if (argc > 1) {
        n = atoi(argv[1]);   // convert string to int
    } else {
        cout << "Enter value of n: ";
        cin >> n;
    }

    double sum = 0;

    for (int i = 1; i <= n; i++) {
        double term = pow(i, i);

        if (i % 2 == 0)
            sum -= 1.0 / term;   // even → negative
        else
            sum += 1.0 / term;   // odd → positive
    }

    cout << "Sum of series = " << sum;

    return 0;
}