#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
using namespace std;

bool newGame(bool won) {
    int randomNumber = rand() % 100 + 1;
    int playerInput;
    char again;

    cin >> playerInput;
    while (playerInput != randomNumber) {
        cout << "Wrong! Try again: \n";
        cin >> playerInput;
    }

    if (playerInput == randomNumber) {
        cout << "You won! \n";
        cout << "Wanna try again? (y/n): \n";
        cin >> again;
        while (again != 'n' && again != 'y') {
            cout << "Enter right input! \n";
            cin >> again;
        }
        if (again == 'y') {
            won = false;
        }
        else if (again == 'n') {
            won = true;
        }
    }
    return won;
}

int main() {
    bool won = false;

    cout << "Welcome in number guessing game! \n";

    if (won == false) {
        srand(time(0));
        cout << "Guess the number from 1 - 100: \n";

        won = newGame(won);
    }
    if (won) {
        cout << "You won! \n";
    }
    
    system("cls");
}