#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string words[100];
    int count = 0;

    ifstream file("words.txt");
    if (!file) {
        cout << "Error: Could not open words.txt"<<endl;
        return 0;
    }

    while (file >> words[count]) count++;
    file.close();

    srand(time(0));
    string word = words[rand() % count];
    string display(word.length(), '_');
    int mistakes = 7;
    bool found;
    bool used[26] = { false };

    cout << "---- Hangman Game ----"<<endl;

    while (mistakes > 0 && display != word) {
        cout << endl<<"Word: " << display << endl;
        cout << "Remaining mistakes: " << mistakes << endl;

        cout << "Used letters: ";
        for (int i = 0; i < 26; i++) {
            if (used[i])
                cout << (char)('a' + i) << " ";
        }
        cout << endl;

        cout << "Enter a letter: ";
        char guess;
        cin >> guess;

        if (guess >= 'A' && guess <= 'Z') 
            guess = guess - 'A' + 'a';

      
        if (guess < 'a' || guess > 'z') {
            cout << "Invalid input! Enter alphabets only."<<endl;
            continue;
        }

        if (used[guess - 'a']) {
            cout << "You already used this letter! Try another."<<endl;
            continue;
        }

        used[guess - 'a'] = true;
        found = false;

        for (int i = 0; i < word.length(); i++) {
            if (word[i] == guess) {
                display[i] = guess;
                found = true;
            }
        }

        if (!found) {
            mistakes--;
            cout << "Wrong guess!"<<endl;
        }
        else {
            cout << "Correct!"<<endl;
        }
    }

    if (display == word)
        cout <<endl<< " You won! The word was: " << word << endl;
    else
        cout <<endl<< " You lost! The word was: " << word << endl;

    return 0;
}
