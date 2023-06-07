#pragma once
#include "Statek.h"
#include "Plansza.h"
#include "Gra.h"
#include "Komp.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>

class Czteromasztowiec : public Statek {
public:
    Czteromasztowiec() : Statek(4) {}

    char getSymbol() const override {
        return 'C';
    }
};

class Trojmasztowiec : public Statek {
public:
    Trojmasztowiec() : Statek(3) {}

    char getSymbol() const override {
        return 'T';
    }
};

class Dwumasztowiec : public Statek {
public:
    Dwumasztowiec() : Statek(2) {}

    char getSymbol() const override {
        return 'D';
    }
};

class Jednomasztowiec : public Statek {
public:
    Jednomasztowiec() : Statek(1) {}

    char getSymbol() const override {
        return 'J';
    }
};

class Zawodnik {
private:
    Plansza plansza;
    vector<Statek*> flota;

public:
    Zawodnik();
    ~Zawodnik();


    bool ustawStatek(int x, int y, Statek* statek, bool pionowo);
    bool czyKoniecGry() const;


    void strzel(int x, int y, Zawodnik& przeciwnik);



    void pozycjaStatku(const Statek& statek, int& x, int& y) const {
        for (int i = 0; i < plansza.rozmiar(); ++i) {
            for (int j = 0; j < plansza.rozmiar(); ++j) {
                if (&plansza(i, j) == &statek) {
                    x = i;
                    y = j;
                    return;
                }
            }
        }
    }

    void wyswietlPlansze(bool pokazStatki) const;

    void zapiszPlanszeDoPliku(const string& nazwaPliku) const;