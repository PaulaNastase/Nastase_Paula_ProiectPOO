#include <iostream>

using namespace std;

class Continent
{
public:
	static int nrContinente;
	const int nrTari;
	char* denumire;
	int suprafata;
	int nrContinenteVecine;

	Continent() :nrTari(44)
	{
		this->denumire = new char[strlen("Europa") + 1];
		strcpy_s(this->denumire, strlen("Europa") + 1, "Europa");
		this->suprafata = 10530000;
		this->nrContinenteVecine = 1;
	}

	Continent(int nrTari, int suprafata) :nrTari(nrTari)
	{
		this->denumire = new char[strlen("America de Sud") + 1];
		strcpy_s(this->denumire, strlen("America de Sud") + 1, "America de Sud");
		this->suprafata = suprafata;
		this->nrContinenteVecine = 1;
	}

	Continent(int nrTari, int nrContinenteVecine, int suprafata) : nrTari(nrTari), nrContinenteVecine(nrContinenteVecine)
	{
		this->denumire = new char[strlen("Asia") + 1];
		strcpy_s(this->denumire, strlen("Asia") + 1, "Asia");
		this->suprafata = suprafata;
	}

	~Continent()
	{
		delete[]this->denumire;
	}


	void afisare()
	{
		cout << denumire << " este unul din cele " << nrContinente << " continente si are o suprafata de " << suprafata << " km^2. Are " << nrContinenteVecine << " continent vecin. Cuprinde " << nrTari << " (de) tari." << endl;
	}
};

int Continent::nrContinente = 7;


class Vulcan
{
public:
	static int gradEruptie;
	const string activitate;
	bool localizare;
	char* nume;
	int altitudine;

	Vulcan() :activitate("inactiv")
	{
		this->localizare = true;
		this->altitudine = 6893;
		this->nume = new char[strlen("Ojos del Salado") + 1];
		strcpy_s(this->nume, strlen("Ojos del Salado") + 1, "Ojos del Salado");
	}

	Vulcan(string activitate, int altitudine) :activitate(activitate), altitudine(altitudine)
	{
		this->localizare = false;
		this->nume = new char[strlen("Mauna Kea") + 1];
		strcpy_s(this->nume, strlen("Mauna Kea") + 1, "Mauna Kea");
	}

	Vulcan(int altitudine) : activitate("adormit"), altitudine(altitudine)
	{
		this->localizare = true;
		this->nume = new char[strlen("Edgecumbe") + 1];
		strcpy_s(this->nume, strlen("Edgecumbe") + 1, "Edgecumbe");
	}

	~Vulcan()
	{
		delete[]this->nume;
	}

	void afisare()
	{
		cout << "Vulcanul " << nume << " este " << activitate << ", se afla pe " << (this->localizare ? "mare" : "uscat") << ", are o altitudine de " << altitudine << " metri si are gradul de eruptie " << gradEruptie<<"." << endl;
	}
};

int  Vulcan::gradEruptie = 2;

class Tara
{
public:
	static string oAltaLimbaVorbita;
	const int suprafata;
	string nume;
	int nrJudete;
	char* capitala;
	bool iesireMare;

	Tara() :suprafata(238397)
	{
		this->iesireMare = true;
		this->nume = "Romania";
		this->capitala = new char[strlen("Bucuresti") + 1];
		strcpy_s(this->capitala, strlen("Bucuresti") + 1, "Bucuresti");

	}

	Tara(int nrJudete, int suprafata) : suprafata(suprafata), nrJudete(nrJudete)
	{
		this->iesireMare = false;
		this->nume = "Austria";
		this->capitala = new char[strlen("Viena") + 1];
		strcpy_s(this->capitala, strlen("Viena") + 1, "Viena");

	}

	Tara(string nume, int suprafata, int nrJudete) : suprafata(suprafata), nume(nume)
	{
		this->iesireMare = true;
		this->nrJudete = nrJudete;
		this->capitala = new char[strlen("Tokyo") + 1];
		strcpy_s(this->capitala, strlen("Tokyo") + 1, "Tokyo");

	}

	void afisare()
	{
		cout << "Tara " << nume << " are o suprafata de " << suprafata << " km^2, " << (this->iesireMare ? " are iesire la mare. " : " nu are iesire la mare. ") << " Pe langa limba nationala, se mai vorbeste si " << oAltaLimbaVorbita << ". Tara este impartita in " << nrJudete << " judete, iar capitala este " << this->capitala << "." << endl;

	}

	~Tara()
	{
		delete[]this->capitala;
	}
};

string Tara::oAltaLimbaVorbita = "limba engleza";

void main()
{
	Continent c;
	c.afisare();
	Continent c1(12, 17840000);
	c1.afisare();
	Continent c2(48, 1, 44579000);
	c2.afisare();

	Vulcan vulcan;
	vulcan.afisare();
	Vulcan v("inactiv", 4207);
	v.afisare();
	Vulcan V(976);
	V.afisare();

	Tara tara;
	tara.afisare();
	Tara T(15, 83871);
	T.afisare();
	Tara t("Japonia", 377973, 8);
	t.afisare();
}