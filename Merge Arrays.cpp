//Write a program to merge two ordered arrays to get a single ordered array.

#include <iostream>
using namespace std;

int main() {
    int a[50], b[50], c[100];
    int n1, n2;

    cout << "Enter size of first array: ";
    cin >> n1;
    cout << "Enter elements (sorted): ";
    for (int i = 0; i < n1; i++)
        cin >> a[i];

    cout << "Enter size of second array: ";
    cin >> n2;
    cout << "Enter elements (sorted): ";
    for (int i = 0; i < n2; i++)
        cin >> b[i];

    int i = 0, j = 0, k = 0;

    // Merging process
    while (i < n1 && j < n2) {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    // Remaining elements
    while (i < n1)
        c[k++] = a[i++];

    while (j < n2)
        c[k++] = b[j++];

    cout << "Merged Sorted Array: ";
    for (int i = 0; i < k; i++)
        cout << c[i] << " ";

    return 0;
}