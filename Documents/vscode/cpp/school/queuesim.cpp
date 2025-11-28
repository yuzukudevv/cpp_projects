#include <iostream>
#include <vector>
using namespace std;

vector<int> kolejka = {};

void menu() {
    cout << "[1]push()\n";
    cout << "[2]pop()\n";
    cout << "[3]front()\n";
    cout << "[4]empty()\n";
    cout << "[5]size()\n";
    cout << "[6]zakoncz program\n";
}

class Funkcje {
    public:
    void wyswietl() {
        cout << "Aktualna kolejka: \n";
        if (kolejka.empty()) {
            cout << "Pusta.\n";
        } else {
                for (int i = 0; i < kolejka.size(); i++) {
                    cout << "[" << i << "] = " << kolejka[i] << "\n";
                }
                cout << "\n";
                }
    }

    void pushh() {
        int liczba;
        cout << "Daj liczbe do wrzucenia do kolejki \n";
        cin >> liczba;
        kolejka.push_back(liczba);
        cout << "Dodano: " << liczba << " do kolejki. \n";
    }

    void popp() {
        cout << "Wyrzucono z kolejki. \n";
        kolejka.erase(kolejka.begin());
    }

    void frontt() {
        cout << "Pierwszy element kolejki to: ";
        cout << kolejka[0] << "\n";
    }

    void emptyy() {
        if (kolejka.empty()) {
            cout << "Kolejka jest pusta. \n";
        } else {
            cout << "W kolejce znajdują się elementy. \n \n";
        }
    }

    void sizee() {
        cout << "Wielkość kolejki to: ";
        cout << kolejka.size() << "\n";
    }
};

class Obliczenia {
    public:
    void maksymalny() { 
        int tempMax = INT_MIN;
        if (!kolejka.empty()) {
            for (int i = 0; i < kolejka.size(); i++) {
                if (kolejka[i] > tempMax) {
                    tempMax = kolejka[i];
                }
            }
            cout << "maksymalny = " << tempMax << "\n";
        } else {
            cout << "Maksymalny element nie jestnieje, kolejka jest pusta. \n \n";
        }
    }

    void minimalny() {
        int tempMin = INT_MAX;
        if (!kolejka.empty()) {
            for (int i = 0; i < kolejka.size(); i++) {
                if (kolejka[i] < tempMin) {
                    tempMin = kolejka[i];
                }
            }
            cout << "minimalny = " << tempMin << "\n";
        } else {
            cout << "Minimalny element nie jestnieje, kolejka jest pusta. \n \n";
        }
    }

    void suma() {
        int suma = 0;
        for (int i = 0; i < kolejka.size(); i++) {
            suma += kolejka[i];
        }
        cout << "suma = " << suma << "\n";
    }

    void sumaNieparz() {
        int suma = 0;
        for (int i = 0; i < kolejka.size(); i++) {
            if (kolejka[i] % 2 == 0) {
                suma += kolejka[i];
            }
        }
        cout << "suma nieparzystych liczb = " << suma << "\n";
    }

    void sredniaOParzInd() {
        int suma = 0;
        for (int i = 0; i < kolejka.size(); i+=2) {
            suma += kolejka[i];
        }
        cout << "srednia o parzystych indeksach = " << suma << "\n";
    }

    void sredniaONieparzInd() {
        int suma = 0;
        for (int i = 1; i < kolejka.size(); i+=2) {
            suma += kolejka[i];
        }
        cout << "srednia o nieparzystych indeksach = " << suma << "\n";
    }
};

int main() {
    Funkcje f;
    Obliczenia o;
    menu();
    int wybor = 0;
    do {
        f.wyswietl();
        cout << "Wybor: ";
        cin >> wybor;
        cout << "\n";
        switch(wybor) {
            case 1:
                f.pushh();
                f.wyswietl();
                o.maksymalny();
                o.minimalny();
                o.suma();
                o.sumaNieparz();
                o.sredniaOParzInd();
                o.sredniaONieparzInd();
                menu();
            break;
            case 2:
                f.wyswietl();
                f.popp();
                o.maksymalny();
                o.minimalny();
                o.suma();
                o.sumaNieparz();
                o.sredniaOParzInd();
                o.sredniaONieparzInd();
                menu();
            break;
            case 3:
                f.wyswietl();
                f.frontt();
                o.maksymalny();
                o.minimalny();
                o.suma();
                o.sumaNieparz();
                o.sredniaOParzInd();
                o.sredniaONieparzInd();
                menu();
            break;
            case 4:
                f.wyswietl();
                f.emptyy();
                o.maksymalny();
                o.minimalny();
                o.suma();
                o.sumaNieparz();
                o.sredniaOParzInd();
                o.sredniaONieparzInd();
                menu();
            break;
            case 5:
                f.wyswietl();
                f.sizee();
                o.maksymalny();
                o.minimalny();
                o.suma();
                o.sumaNieparz();
                o.sredniaOParzInd();
                o.sredniaONieparzInd();
                menu();
            break;
    
        }
    } while (wybor != 6);
}