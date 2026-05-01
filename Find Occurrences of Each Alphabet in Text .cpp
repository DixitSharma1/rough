//Write a program that prints a table indicating the number of occurrences of each alphabet in the text entered as command line arguments.
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    int count[26] = {0}; // For a-z

    // Loop through all command line arguments
    for (int i = 1; i < argc; i++) {
        char *p = argv[i];

        while (*p != '\0') {
            char ch = *p;

            // Convert uppercase to lowercase
            if (ch >= 'A' && ch <= 'Z')
                ch = ch + 32;

            // Check if alphabet
            if (ch >= 'a' && ch <= 'z') {
                count[ch - 'a']++;
            }

            p++;
        }
    }

    // Display result
    cout << "Alphabet Frequency:\n";
    for (int i = 0; i < 26; i++) {
        cout << char(i + 'a') << " : " << count[i] << endl;
    }

    return 0;
}