#include "Komp.h"

void Komp::Komp() {
    flota.push_back(new Czteromasztowiec());
    flota.push_back(new Trojmasztowiec());
    flota.push_back(new Trojmasztowiec());
    flota.push_back(new Dwumasztowiec());
    flota.push_back(new Dwumasztowiec());
    flota.push_back(new Dwumasztowiec());
    flota.push_back(new Jednomasztowiec());
    flota.push_back(new Jednomasztowiec());
    flota.push_back(new Jednomasztowiec());
    flota.push_back(new Jednomasztowiec());

    srand(static_cast<unsigned int>(time(nullptr)));

    for (Statek* statek : flota) {
        bool ustawiony = false;
        while (!ustawiony) {
            int x = rand() % gra.rozmiar();
            int y = rand() % gra.rozmiar();
            bool pionowo = rand() % 2 == 0;
            ustawiony = ustawStatek(x, y, statek, pionowo);
        }
    }
}
void Komp::~Komp() {
    for (Statek* statek : flota) {
        delete statek;
    }
}

bool Komp::ustawStatek() {
    int rozmiar = statek->getRozmiar();

    if (pionowo && y + rozmiar > gra.rozmiar()) {
        return false;
    }

    if (!pionowo && x + rozmiar > gra.rozmiar()) {
        return false;
    }

    for (int i = 0; i < rozmiar; ++i) {
        if (pionowo && gra(x, y + i).czyMaStatek()) {
            return false;
        }

        if (!pionowo && gra(x + i, y).czyMaStatek()) {
            return false;
        }
    }

    for (int i = 0; i < rozmiar; ++i) {
        if (pionowo) {
            gra(x, y + i).ustawStatek();
        }
        else {
            gra(x + i, y).ustawStatek();
        }
    }

    return true;
}

bool Komp::czyKoniecGry() {
    for (const Statek* statek : flota) {
        if (!statek->czyZatopiony()) {
            return false;
        }
    }

    return true;
}

void Komp::losowyStrzal() {
    int x, y;
    do {
        x = rand() % gra.rozmiar();
        y = rand() % gra.rozmiar();
    } while (zawodnik.gra(x, y).czyTrafiony());

    cout << "Komputer strzela na pole (" << x << ", " << y << ")..." << endl;
    zawodnik.strzel(x, y, *this);
}

void Komp::wyswietlPlansze() {
    gra.wyswietl(pokazStatki);
}

void Komp::zapiszPlanszeDoPliku() {

    ofstream plik(nazwaPliku);
    if (plik.is_open()) {
        for (int i = 0; i < gra.rozmiar(); ++i) {
            for (int j = 0; j < gra.rozmiar(); ++j) {
                char symbol;
                if (gra(i, j).czyTrafiony()) {
                    if (gra(i, j).czyMaStatek()) {
                        symbol = 'X';
                    }
                    else {
                        symbol = 'O';
                    }
                }
                else {
                    symbol = '~';
                }
                plik << symbol << ' ';
            }
            plik << endl;
        }
        plik.close();
    }
    else {
        cout << "B³¹d podczas zapisu do pliku." << endl;
    }
}
