#include <iostream>
#include <vector>
#include <random>
#include <algorithm> //shuffle
#include <windows.h> //do shuffle i cls
using namespace std;

const char deckColorsArray[2] = {'p', 'g'}; //(purple or green)
const char cardsColorsArray[2] = {'r', 'b'}; //(red or black)
const string suitsArray[4] = {"♦️", "♥️", "♠️", "♣️"};
const string ranksArray[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
const int valuesArray[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

class Card {
public:
    char deckColor;
    char cardColor;
    string suit;
    string rank;
    int value;

    Card(char dc, char cc, string s, string r, int val) { //tworzy obiekt carda z tymi typami zmiennych
        deckColor = dc; //przypisuje parametr dc do pola deckColor obiektu
        cardColor = cc;
        suit = s;
        rank = r;
        value = val;
    }
};

class Deck {
public:
    vector<Card> deck = {};

    void createDeck() {
        int deckCount = 2;
        for (int i = 0; i < deckCount; i++) {
            char deckColor;
            if (i == 0) {
                deckColor = deckColorsArray[0];
            }
            else {
                deckColor = deckColorsArray[1];
            }

            for (int j = 0; j < 4; j++) {
                string suit = suitsArray[j];

                char cardColor;
                if (suit == "♦️" || suit == "♥️") {
                    cardColor = cardsColorsArray[0];
                }
                else {
                    cardColor = cardsColorsArray[1];
                }

                for (int k = 0; k < 13; k++) {
                    string rank = ranksArray[k];
                    int value = valuesArray[k];

                    Card generatedCard(deckColor, cardColor, suit, rank, value);
                    deck.push_back(generatedCard);
                }
            }
        }
    }

    void shuffleDeck() {
        random_device rd; //rd jest zrodlem seeda losowego
        mt19937 g(rd()); //mt jest sposobem generacji, g obiektem, bo random jest obiektowy, rd tutaj jest odwolaniem do seeda
        shuffle(deck.begin(), deck.end(), g); //tasowanie na podstawie losowosci tego obiektu
    }

    Card drawACard() {
        if (deck.size() > 25) {
            Card drawnCard = deck.back();
            deck.pop_back();
            return drawnCard;
        }
        else {
            cout << "--------------------------------------------------------------------------------------------------------------------------------------";
            cout << "There are fewer than 25 cards in the deck. The dealer brings 2 more decks to the table. The remaining cards are taken out of rotation.";
            cout << "--------------------------------------------------------------------------------------------------------------------------------------";
            deck.clear();
            createDeck();
            shuffleDeck();
            Card drawnCard = deck.back();
            deck.pop_back();
            return drawnCard;
        }
    }

    void printDeck() { //DEV FUNKCJA, DO WYJEBANIA
        for (int i = 0; i < deck.size(); i++) {
            cout << deck[i].rank << " " << deck[i].suit << "\n";
        }
    }
};

class Hand {
    public:
    vector<Card> playerHand;
    
    

};

class Player {
    public:
    double balance;
    int currentBet;
};


class GameController {
    Hand h;
public:
    void start() {
        Deck d;
        d.createDeck();
        d.shuffleDeck();
        Card drawnCard = d.drawACard();
        h.playerHand.push_back(drawnCard);
        for (const Card& c : h.playerHand) {
            cout << c.rank << " " << c.suit << endl;
        }
    }
};

class Narrator {
    Player p;
    void greeting() {
        cout << "┌──────────────────────────────┐\n";
        cout << "│   You entered the table...   │\n";
        cout << "│  How much $ you want to bet? │\n";
        cout << "│                              │\n";
        cout << "└──────────────────────────────┘\n";
        cout << "│Minimal bet: 5$\n";
        cout << "│Your balance: " << p.balance << "\n";
        cout << "└──────────────────────────────┘\n";
    }
    void gameBeggining() {
        cout << "   •¢¥§•¢¥§¶†¶†‡§¶†¶†¶†• \n";
        cout << "   ¤  Wish you luck... ¤ \n";
        cout << "   •¢¥§¶†¶†‡•¢¥§¶†¶†‡¶†• \n" << "\n";
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    GameController gc;
    gc.start();



    
    return 0;
}


/*
1. Klasa do przechowywania kart gracza/krupiera

Vector z kartami
Funkcja dodawania karty
Funkcja liczenia wartości (WAŻNE: As może być 1 lub 11!)
Funkcja sprawdzania czy bust (powyżej 21)
Funkcja wyświetlania kart
Funkcja czyszczenia ręki (nowa runda)

2. Klasa gracza

Imię
Pieniądze/żetony
Aktualny zakład
Ręka z kartami (użyj klasy z punktu 1)
Funkcja stawiania zakładu
Funkcje wygranej/przegranej (dodawanie/odejmowanie pieniędzy)

3. Klasa krupiera

Ręka z kartami (użyj klasy z punktu 1)
Funkcja automatycznego dobierania kart (krupier dobiera do 17 punktów)
Funkcja pokazywania kart (pierwsza karta ukryta na początku)

4. Klasa zarządzająca grą

Obiekt talii
Obiekt gracza
Obiekt krupiera
Funkcja rozpoczynająca grę
Funkcja rozdania początkowych kart (2 dla gracza, 2 dla krupiera)
Funkcja tury gracza (hit/stand)
Funkcja tury krupiera
Funkcja określająca zwycięzcę
Funkcja nowej rundy

*/