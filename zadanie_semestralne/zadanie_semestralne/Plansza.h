#pragma once
#include "Plansza.cpp";
enum pole
{
	nie_istnieje = -1,
	puste_pole = 0,
	pole_gracza_1 = 1,
	pole_gracza_2 = 2
};
class Plansza
{
    private:
	char*** plansza = new char**[7];
	char* znak_wolnego_pola = &wolne_pole;
	char* znak_gracza = &gracz_1;
	char* znak_gracza_2 = &gracz_2;

    public:
		Plansza();
		void wyswietl_plansze();
		void wyswietl_plansze(int tryb);
		char gracz_1 = 'X';
		char gracz_2 = 'Y';
		char wolne_pole = 'O';
		int tryb = 0;
		bool wstaw(int x, int y, pole nowe_pole);
		void usun(int x, int y);
		pole jakie_pole(int x, int y);

};