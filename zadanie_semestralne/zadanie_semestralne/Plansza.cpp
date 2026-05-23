#include "Plansza.h"
#include <iostream>

Plansza::Plansza()
{
	for (int i = 0; i <= 2; i++)
	{
		plansza[i] = new char*[3];
		for (int j = 0; j < 3; j++)
		{
			plansza[i][j] = znak_wolnego_pola;
		}
	}
	plansza[3] = new char*[6];
	for (int j = 0; j < 6; j++)
	{
		plansza[3][j] = znak_wolnego_pola;
	}
	for (int i = 4; i < 7; i++)
	{
		plansza[i] = new char*[3];
		for (int j = 0; j < 3; j++)
		{
			plansza[i][j] = znak_wolnego_pola;
		}
	}
}
void Plansza::wyswietl_plansze(int tryb)
{
	if (tryb == 1)
	{
		wyswietl_plansze();
	}
	else
	{
		printf(" (%c)------------(%c)------------(%c)\n", *plansza[0][0], *plansza[0][1], *plansza[0][2]);
		printf("  |              |              |\n");
		printf("  |  (%c)--------(%c)--------(%c)  |\n", *plansza[1][0], *plansza[1][1], *plansza[1][2]);
		printf("  |   |          |          |   |\n");
		printf("  |   |  (%c)----(%c)----(%c)  |   |\n", *plansza[2][0], *plansza[2][1], *plansza[2][2]);
		printf("  |   |   |             |   |   |\n");
		printf(" (%c)-(%c)-(%c)           (%c)-(%c)-(%c)\n", *plansza[3][0], *plansza[3][1], *plansza[3][2], *plansza[3][3], *plansza[3][4], *plansza[3][5]);
		printf("  |   |   |             |   |   |\n");
		printf("  |   |  (%c)----(%c)----(%c)  |   |\n", *plansza[4][0], *plansza[4][1], *plansza[4][2]);
		printf("  |   |          |          |   |\n");
		printf("  |  (%c)--------(%c)--------(%c)  |\n", *plansza[5][0], *plansza[5][1], *plansza[5][2]);
		printf("  |   |          |          |   |\n");
		printf(" (%c)------------(%c)------------(%c)\n", *plansza[6][0], *plansza[6][1], *plansza[6][2]);
	}
}
void Plansza::wyswietl_plansze()
{
	/*
	std::cout << " (0)------------(0)------------(0)" << std::endl;
	std::cout << "  |              |              |" << std::endl;
	std::cout << "  |  (0)--------(0)--------(0)  |" << std::endl;
	std::cout << "  |   |          |          |   |" << std::endl;
	std::cout << "  |   |  (0)----(0)----(0)  |   |" << std::endl;
	std::cout << "  |   |   |             |   |   |" << std::endl;
	std::cout << " (0)-(0)-(0)           (0)-(0)-(0)" << std::endl;
	std::cout << "  |   |   |             |   |   |" << std::endl;
	std::cout << "  |   |  (0)----(0)----(0)  |   |" << std::endl;
	std::cout << "  |   |          |          |   |" << std::endl;
	std::cout << "  |  (0)--------(0)--------(0)  |" << std::endl;
	std::cout << "  |   |          |          |   |" << std::endl;
	std::cout << " (0)------------(0)------------(0)" << std::endl;
	      printf("  A---B---C------D------E---F---G\n");
	*/
	printf("01) (%c)------------(%c)------------(%c)\n", *plansza[0][0], *plansza[0][1], *plansza[0][2]);
	printf("02)  |              |              |\n");
	printf("03)  |  (%c)--------(%c)--------(%c)  |\n", *plansza[1][0], *plansza[1][1], *plansza[1][2]);
	printf("04)  |   |          |          |   |\n");
	printf("05)  |   |  (%c)----(%c)----(%c)  |   |\n", *plansza[2][0], *plansza[2][1], *plansza[2][2]);
	printf("06)  |   |   |             |   |   |\n");
	printf("07) (%c)-(%c)-(%c)           (%c)-(%c)-(%c)\n", *plansza[3][0], *plansza[3][1], *plansza[3][2], *plansza[3][3], *plansza[3][4], *plansza[3][5]);
	printf("08)  |   |   |             |   |   |\n");
	printf("09)  |   |  (%c)----(%c)----(%c)  |   |\n", *plansza[4][0], *plansza[4][1], *plansza[4][2]);
	printf("10)  |   |          |          |   |\n");
	printf("11)  |  (%c)--------(%c)--------(%c)  |\n", *plansza[5][0], *plansza[5][1], *plansza[5][2]);
	printf("12)  |   |          |          |   |\n");
	printf("13) (%c)------------(%c)------------(%c)\n", *plansza[6][0], *plansza[6][1], *plansza[6][2]);
	printf("  A---B---C------D------E---F---G\n");
}
bool Plansza::wstaw(int x, int y, pole nowe_pole)
{
	if (!(plansza[x][y] == znak_wolnego_pola))
	{
		std::cout << "to pole jest ju¿ zajête, proszê wybraæ inne miejsce" << std::endl;
		return false;
	}
	switch (nowe_pole)
	{
	case pole::puste_pole:
		plansza[x][y] = znak_wolnego_pola;
		break;
	case pole::pole_gracza_1:
		plansza[x][y] = znak_gracza;
		break;
	case pole::pole_gracza_2:
		plansza[x][y] = znak_gracza_2;
		break;
	default:
		break;
	}
	return true;
}
void Plansza::usun(int x, int y)
{
	plansza[y][x] == znak_wolnego_pola;
}
bool sprawdzanie_prawidlowosci_pola(int x, int y)
{
	if (x == 3 && y < 6 && y >= 0)
	{
		return true;
	}
	if (y < 3 && y >= 0 && x >= 0)
	{
		return true;
	}
	return false;
}
pole Plansza::jakie_pole(int x, int y)
{
	    if (!sprawdzanie_prawidlowosci_pola(x, y))
	    {
			return pole::nie_istnieje;
		}
 
		if (plansza[y][x] == znak_wolnego_pola)
		{
			return pole::puste_pole;
		}
		if (plansza[y][x] == znak_gracza)
		{
			return pole::pole_gracza_1;
		}
		if (plansza[y][x] == znak_gracza_2)
		{
			return pole::pole_gracza_2;
		}
		printf("nie mo¿na rozpoznaæ tego pola, prawdopodobnie jest uszkodzone, koñczê dzia³anie programu");
		exit(0);
}