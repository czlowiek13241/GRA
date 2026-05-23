#pragma once
#include "LupaGry.cpp";
enum operacja
{
	RUCH = 0,
	BLAD_WCZYTANIU_RUCHU = -1,
	ZAPISZ_GRE = 2,
	WCZYTAJ_GRE = 3,
};

class LupaGry
{
	Gracze gracz_1;
	Gracze gracz_2;
	Plansza* plansza;
	DaneGry* dane_gry;



    public:
	LupaGry(Gracze gracz_1, Gracze gracz_2);
	static operacja przetworzenie_polecenie_gracza(int pozycja[2]);
	void ZagranieRuchu(Gracze gracz, int tryb);
	

};

