#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
#include "Statek.h"
#include "Zawodnik.h" 
#include "Plansza.h"
#include "Gra.h"

class Komp {
private:
    Gra gra;
    vector<Statek*> flota;

public:
    Komp();
    ~Komp();

    bool ustawStatek(int x, int y, Statek* statek, bool pionowo);
    bool czyKoniecGry() const;

    void losowyStrzal(Zawodnik& Zawodnik);

    void wyswietlPlansze(bool pokazStatki) const;

    void zapiszPlanszeDoPliku(const string& nazwaPliku) const;
}

