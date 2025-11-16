#include <iostream> 
#include <conio.h>
using namespace std;

bool isPalindrome(string str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; 
        }
    }

    int start = 0;
    int end = str.length() - 1;        //end will be 1 less than the actual amount as we start the start from 0

    while (start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}


int main() {
    char ch;
    string input;

    cout << "---- Palindrome Checker ----" << endl;
    cout << "Press ESC to exit anytime."<<endl<<endl;

    while (true) {
        cout << "Enter a string: ";                       //takes input of the string to check in this loop and tests the palidrome, until ESC is pressed
        cin >> input;

        if (isPalindrome(input))
            cout <<endl<< "Palindrome"<<endl;
        else
            cout <<endl<< "Not Palindrome"<<endl;

        cout << "\nPress any key to continue or ESC to exit...";
        ch = _getch();
        if (ch == 27)
            break;

        cout << endl << endl;
    }

    return 0;
}


