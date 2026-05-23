// zadanie_semestralne.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "GraMlynek.h";
#include <stdio.h>
#include <iostream>

int main()
{
	int dane[2];
	dane[0] = 0;
	dane[1] = 0;
	operacja wynik;
	Plansza plansza = Plansza();

	do
	{
		wynik = LupaGry::przetworzenie_polecenie_gracza(dane);
		plansza.wyswietl_plansze(0);

	} while (wynik != ZAPISZ_GRE);
	

}