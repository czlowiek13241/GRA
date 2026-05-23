#include "GraMlynek.h"
#pragma once

operacja LupaGry::przetworzenie_polecenie_gracza(int dane[2])
{
	char array[5] = { 0 };
	fgets(array, 5 * sizeof(char), stdin);
	int x, y;
	char z;

	if (sscanf_s(array, "%d%d", &x, &y) == 2)
	{
		dane[0] = x-1; 
		dane[1] = y-1;
		
		if (x == 3 && y < 6 && y >= 0)
		{
			return RUCH;
		}
		if (y < 3 && y >= 0 && x >= 0)
		{
			return RUCH;
		}
		return BLAD_WCZYTANIU_RUCHU;
	}
	if (sscanf_s(array, "%c%d", &z, 1, &x) == 2 || sscanf_s(array, "%d%c", &x, &z, 1) == 2)
	{		
		dane[0] = x-1;
		if (isalpha(z))
		{
			z = tolower(z);
			if (z - 'a' <= 'g')
			{
				dane[1] = z - 'a';
				return RUCH;
			}
		}
		return BLAD_WCZYTANIU_RUCHU;
	}
	if (!isalpha(array[0]))
	{
		return BLAD_WCZYTANIU_RUCHU;
	}
	array[0] = tolower(array[0]);

	if (array[0] == 'z' && array[1] == '\n')
	{
		return ZAPISZ_GRE;
	}
	if(array[0] == 'w' && array[1] == '\n')
	{
		return WCZYTAJ_GRE;
	}
	if (array[0] == 'k' && array[1] == '\n')
	{
		exit(0);
	}
	return BLAD_WCZYTANIU_RUCHU;
}