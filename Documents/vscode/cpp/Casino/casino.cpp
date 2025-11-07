#include <iostream>
#include <windows.h>
using namespace std;


string deck[52] = {
                "[A]♥", "[2]♥", "[3]♥", "[4]♥", "[5]♥", "[6]♥", "[7]♥", "[8]♥", "[9]♥", "[10]♥", "[J]♥", "[Q]♥", "[K]♥",
                "[A]♦", "[2]♦", "[3]♦", "[4]♦", "[5]♦", "[6]♦", "[7]♦", "[8]♦", "[9]♦", "[10]♦", "[J]♦", "[Q]♦", "[K]♦",
                "[A]♣", "[2]♣", "[3]♣", "[4]♣", "[5]♣", "[6]♣", "[7]♣", "[8]♣", "[9]♣", "[10]♣", "[J]♣", "[Q]♣", "[K]♣",
                "[A]♠", "[2]♠", "[3]♠", "[4]♠", "[5]♠", "[6]♠", "[7]♠", "[8]♠", "[9]♠", "[10]♠", "[J]♠", "[Q]♠", "[K]♠"};

int balance = 50;


void mainMenuText() {
    cout << "┌─────────────────────────────────────────────┐\n";
    cout << "│ Welcome to the casino! Let's pick a game... │\n";
    cout << "└─────────────────────────────────────────────┘\n";

    cout << "┌─────────────────┐\n";
    cout << "│ [1] - Blackjack │\n";
    cout << "└─────────────────┘\n";

    cout << "┌────────────────┐\n";
    cout << "│ [2] - Roulette │\n";
    cout << "└────────────────┘\n";

    cout << "┌────────────────────┐\n";
    cout << "│ [3] - Leave & Save │\n";
    cout << "└────────────────────┘\n";

    cout << "│ Your choice: ";
}

void gameBegginingTexts() {
    cout << "┌──────────────────────────┐\n";
    cout << "│ You entered the table... │\n";
    cout << "└──────────────────────────┘\n";
    cout << "   •¢¥§•¢¥§¶†¶†‡§¶†¶†¶†• \n";
    cout << "   ¤  Wish you luck... ¤ \n";
    cout << "   •¢¥§¶†¶†‡•¢¥§¶†¶†‡¶†• \n" << "\n";
}

int betting() {
        int playerBet;
        bool correctInput = false;

        cout << "How much $ you want to bet? \n";

        while (correctInput == false) {
            cin >> playerBet;
            if (playerBet >= 5 && playerBet <= balance) {
                correctInput = true;
            }
            else if (playerBet >= 5 && playerBet > balance) {
                cout << "You have insufficient balance. \n";
            }
            else if (playerBet < 5) {
                cout << "Minimal bet is $5. \n";
            }
            else {
                cout << "Enter correct input. \n";
            }
        }

        cout << "Your bet: " << playerBet << "\n";
        cout << "Dealer dispenses the cards. \n" << "\n";
    return playerBet;
}

string drawACard() {
        bool drawedSuccessfully = false;

        int randomCardIndex = rand() % 52;
        string drawedCard;
        drawedCard = deck[randomCardIndex];

        if (deck[randomCardIndex] != "drawed") {
            drawedSuccessfully = true;
            drawedCard = deck[randomCardIndex];
            deck[randomCardIndex] = "drawed";
        }

        while (!drawedSuccessfully) {
            randomCardIndex = rand() % 52;

            if (deck[randomCardIndex] != "drawed") {
                drawedSuccessfully = true;
                drawedCard = deck[randomCardIndex];
                deck[randomCardIndex] = "drawed";
            }
        }
    return drawedCard;
}

void dealerHand() {
    cout << "Dealer hand:  \n";

    string firstCard = drawACard();
    string secondCard = drawACard();
    cout << firstCard << " " << secondCard << "\n" << "\n";
    
}

void playerHand() {
    cout << "Your hand:  \n";
    string firstCard = drawACard();
    string secondCard = drawACard();
    cout << firstCard << " " << secondCard << "\n";
}

bool determineWinner() {

}
    

int main() {
    mainMenuText();

    string userMainScreenInput;

    bool correctInput = false;
    while (correctInput == false) {
        cin >> userMainScreenInput;
        if (userMainScreenInput == "1" || userMainScreenInput == "2" || userMainScreenInput == "3") {
            correctInput = true;
        }
        else {
            cout << "Enter Correct input. (1-3) \n";
        }
    }

    if (userMainScreenInput  == "1") {
        system("cls");
        gameBegginingTexts();
        betting();
        system("cls");
        dealerHand();
        playerHand();
    }
    else if (userMainScreenInput == "2") {
        system("cls");
        cout << "Work in progress \n";
        return 0;
    }
    else if (userMainScreenInput == "3") {
        cout << "Saving function work in progress \n";
        return 0;
    }

}