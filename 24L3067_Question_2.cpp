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
        cout << "Error: Could not open words.txt"<<endl;         //opens the file named "words.txt" using filehandling and if this file isnt present, gives an error 
        return 0;
    }

    while (file >> words[count]) count++;          //copies the words from the file into the string (a word is considered a word until a space or linebreak is faced)
    file.close();

    srand(time(0));
    string word = words[rand() % count];          //selects a random word from the file using rand function
    string display(word.length(), '_'); 
    int mistakes = 7;                           //lives
    bool found;
    bool used[26] = { false };            //creates an array of alphabets that'll be used to check whether an alphabet entered has already been used or not

    cout << "---- Hangman Game ----"<<endl;

    while (mistakes > 0 && display != word) {
        cout << endl<<"Word: " << display << endl;
        cout << "Remaining mistakes: " << mistakes << endl;

        cout << "Used letters: ";
        for (int i = 0; i < 26; i++) {
            if (used[i])
                cout << (char)('a' + i) << " ";             //using ASCII codes, prints the words used.
        }
        cout << endl;

        cout << "Enter a letter: ";
        char guess;
        cin >> guess;

        if (guess >= 'A' && guess <= 'Z') 
            guess = guess - 'A' + 'a';                 //same thing as before, compares the ASCII codes and checks if the inputed alphabet, is indeed an alphabet or not

      
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

