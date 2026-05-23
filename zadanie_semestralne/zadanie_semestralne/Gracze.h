
#include "GraMlynek.h";
#include <string>
class Gracze
{
	int index = 0;
	std::string nazwa_gracza = "Anonymous";
    public:
    DaneGry* dane_gry;
	Gracze(int index, DaneGry* dane_gry);
	Gracze(int index, DaneGry* dane_gry, std::string Nazwa_gracza);
	pole pole_gracza;
};
class Komputer
{
	
};
