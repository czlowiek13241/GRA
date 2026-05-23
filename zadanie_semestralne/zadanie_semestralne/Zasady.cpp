#include "GraMlynek.h"
#pragma once
void Zasady::przeprowadzenie_ruchu(int pozycja[2])
{
	if (dane_gry.tryb_gry == wstawianie_pionkow)
	{
		plansza->wstaw(pozycja[0], pozycja[1], dane_gry.ruch_gracza == 0 ? pole::pole_gracza_1 : pole::pole_gracza_2);
		mlynek(pozycja[0], pozycja[1]);
		dane_gry.ruch_gracza = dane_gry.ruch_gracza == 0 ? 1 : 0;
	}

}
bool Zasady::mlynek(int x, int y)
{
	bool mlynek = false;
	Gracze* grasz_wstawiajacy = dane_gry.ruch_gracza == 0 ? grasz_1 : grasz_2;
	Gracze* grasz_przeciwny = dane_gry.ruch_gracza == 1 ? grasz_2 : grasz_1;

	if (plansza->jakie_pole(x, y) == grasz_wstawiajacy->pole_gracza && plansza->jakie_pole(x + 1, y) == grasz_wstawiajacy->pole_gracza && plansza->jakie_pole(x + 2, y) == grasz_wstawiajacy->pole_gracza)
	{
		plansza->usun(x, y);
		plansza->usun(x + 1, y);
		plansza->usun(x + 2, y);
		update_gracza();
		return true;
	}
	if (plansza->jakie_pole(x, y) == grasz_wstawiajacy->pole_gracza && plansza->jakie_pole(x - 1, y) == grasz_wstawiajacy->pole_gracza && plansza->jakie_pole(x - 2, y) == grasz_wstawiajacy->pole_gracza)
	{
		plansza->usun(x, y);
		plansza->usun(x - 1, y);
		plansza->usun(x - 2, y);
		update_gracza();
		return true;
	}
	if (plansza->jakie_pole(x, y) == grasz_wstawiajacy->pole_gracza && plansza->jakie_pole(x + 1, y) == grasz_wstawiajacy->pole_gracza && plansza->jakie_pole(x + 2, y) == grasz_wstawiajacy->pole_gracza)
	{
		plansza->usun(x, y);
		plansza->usun(x, y+1);
		plansza->usun(x, y+2);
		update_gracza();
		return true;
		
	}
	if (plansza->jakie_pole(x, y) == grasz_wstawiajacy->pole_gracza && plansza->jakie_pole(x, y-1) == grasz_wstawiajacy->pole_gracza && plansza->jakie_pole(x, y-2) == grasz_wstawiajacy->pole_gracza)
	{
		plansza->usun(x, y);
		plansza->usun(x, y-1);
		plansza->usun(x, y-2);
		update_gracza();
		return true;
	}
	return false;

}
void Zasady::update_gracza()
{
	if (dane_gry.ruch_gracza == 0)
	{
		dane_gry.ilosc_bialych++;
		dane_gry.ilosc_czarnych--;
	}
	else
	{
		dane_gry.ilosc_czarnych++;
		dane_gry.ilosc_bialych--;
	}
	
}