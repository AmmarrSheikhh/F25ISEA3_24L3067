#include <iostream> 
#include <conio.h>
using namespace std;

bool isPalindrome(string str) {
    int start = 0;
    int end = 0;

    end = str.length()-1;
    

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
        cout << "Enter a string: ";
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
