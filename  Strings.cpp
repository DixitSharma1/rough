
//Write a menu driven program to perform string manipulation (without using inbuilt string functions):

a. Show address of each character in string

b. Concatenate two strings.

c. Compare two strings

d. Calculate length of the string (use pointers)

e. Convert all lowercase characters to uppercase

f. Reverse the string

g. Insert a string in another string at a user specified positionStrings

#include <iostream>
using namespace std;

int main() {
    char str1[100], str2[100], temp[200];
    int choice;

    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    do {
        cout << "\n1. Show address of each character";
        cout << "\n2. Concatenate strings";
        cout << "\n3. Compare strings";
        cout << "\n4. Length of string (pointer)";
        cout << "\n5. Lowercase to Uppercase";
        cout << "\n6. Reverse string";
        cout << "\n7. Insert string";
        cout << "\n8. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            cout << "Addresses:\n";
            for (int i = 0; str1[i] != '\0'; i++) {
                cout << str1[i] << " -> " << (void*)&str1[i] << endl;
            }
            break;
        }

        case 2: {
            int i = 0, j = 0;
            while (str1[i] != '\0') {
                temp[i] = str1[i];
                i++;
            }
            while (str2[j] != '\0') {
                temp[i++] = str2[j++];
            }
            temp[i] = '\0';
            cout << "Concatenated: " << temp;
            break;
        }

        case 3: {
            int i = 0, flag = 0;
            while (str1[i] != '\0' || str2[i] != '\0') {
                if (str1[i] != str2[i]) {
                    flag = 1;
                    break;
                }
                i++;
            }
            if (flag == 0)
                cout << "Strings are equal";
            else
                cout << "Strings are not equal";
            break;
        }

        case 4: {
            char *p = str1;
            int len = 0;
            while (*p != '\0') {
                len++;
                p++;
            }
            cout << "Length = " << len;
            break;
        }

        case 5: {
            for (int i = 0; str1[i] != '\0'; i++) {
                if (str1[i] >= 'a' && str1[i] <= 'z')
                    str1[i] = str1[i] - 32;
            }
            cout << "Uppercase: " << str1;
            break;
        }

        case 6: {
            int len = 0;
            while (str1[len] != '\0') len++;

            for (int i = 0; i < len / 2; i++) {
                char t = str1[i];
                str1[i] = str1[len - i - 1];
                str1[len - i - 1] = t;
            }
            cout << "Reversed: " << str1;
            break;
        }

        case 7: {
            int pos, i = 0, j = 0;
            cout << "Enter position: ";
            cin >> pos;

            while (str1[i] != '\0') {
                temp[i] = str1[i];
                i++;
            }
            temp[i] = '\0';

            for (i = 0; i < pos; i++)
                str1[i] = temp[i];

            for (j = 0; str2[j] != '\0'; j++)
                str1[i++] = str2[j];

            for (j = pos; temp[j] != '\0'; j++)
                str1[i++] = temp[j];

            str1[i] = '\0';

            cout << "After insertion: " << str1;
            break;
        }

        case 8:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 8);

    return 0;
}