#pragma once
#include "Statek.h"
#include "Plansza.h"
#include "Komp.h"
#include "Zawodnik.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
using namespace std;
class Gra {
private:
    bool trafiony;
    bool statek;

public:
    void ustawStatek() : trafiony(false), statek(false);
    void strzel();
    void ustawTrafiony();
    bool czyTrafiony() const {
        return trafiony;
    }

    bool czyMaStatek() const {
        return statek;
    }


};
