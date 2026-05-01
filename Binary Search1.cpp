
//Write a program to search a given element in a set of N numbers using Binary Search


//b. without recursion.

#include <iostream>
using namespace std;

int main() {
    int n, key;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter sorted elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int left = 0, right = n - 1, mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid] == key) {
            cout << "Element found at index " << mid;
            return 0;
        }
        else if (key < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    cout << "Element not found";
    return 0;
}