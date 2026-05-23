#pragma once
#include "GraMlynek.h";
enum tryb
{
	wstawianie_pionkow = 1,
	przesuwanie_pionkow = 2,
};



class Zasady
{
	Plansza* plansza;
	Gracze* grasz_1;
	Gracze* grasz_2;
	DaneGry dane_gry;
	tryb tryb_gry;

    public:
	void przeprowadzenie_ruchu(int pozycja[2]);

    private:
	bool mlynek(int x, int y);
	void update_gracza();

	Zasady(Gracze* grasz_1, Gracze* grasz_2, Plansza* plansza, DaneGry dane_gry);

};

