#include <iostream>

using namespace std;

class Continent
{
private:
	static int nrContinente;
	const int nrTari;
	char* denumire;
	int suprafata;
	int nrContinenteVecine;

public:

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

	Continent(const Continent& c) :nrTari(c.nrTari)
	{
		suprafata = c.suprafata;
		nrContinenteVecine = c.nrContinenteVecine;
		denumire = c.denumire;
		this->denumire = new char[strlen(c.denumire + 1)];
		strcpy_s(this->denumire, strlen(c.denumire) + 1, c.denumire);
	}

	int getSuprafata()
	{
		return this->suprafata;
	}

	int getContinenteVecine()
	{
		return this->nrContinenteVecine;
	}

	char* getDenumire()
	{
		return this->denumire;
	}

	const int getNrTari()
	{
		return this->nrTari;
	}

	void setSuprafata(int suprafata)
	{
		this->suprafata = suprafata;
	}

	void setContinenteVecine(int nrContinenteVecine)
	{
		this->nrContinenteVecine = nrContinenteVecine;
	}

	void setDenumire(const char* denumire)
	{
		if (this->denumire != NULL)
			delete[]this->denumire;
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}

	static int getCateContinente()
	{
		return nrContinente;
	}


	~Continent()
	{
		if (this->denumire != NULL)
			delete[]this->denumire;
	}


	void afisare()
	{
		cout << denumire << " este unul din cele " << nrContinente << " continente si are o suprafata de " << suprafata << " km^2. Are " << nrContinenteVecine << " continent vecin. Cuprinde " << nrTari << " (de) tari." << endl;
	}

	friend void esteAsia(Continent c);

	Continent operator+(const Continent& c)
	{
		Continent con = *this;
		con.suprafata = this->suprafata + c.suprafata;
		con.nrContinenteVecine = this->nrContinenteVecine + c.nrContinenteVecine;
		if (con.denumire != NULL)
			delete[]con.denumire;
		con.denumire = new char[strlen(this->denumire) + strlen(c.denumire) + 1];
		strcpy_s(con.denumire, strlen(this->denumire) + 1, this->denumire);
		strcpy_s(con.denumire, strlen(c.denumire) + 1, c.denumire);

		return con;
	}

	Continent operator=(const Continent& c)
	{
		if (this != &c)
		{
			suprafata = c.suprafata;
			nrContinenteVecine = c.nrContinenteVecine;
			if (this->denumire != NULL)
				delete[]this->denumire;
			this->denumire = new char[strlen(c.denumire) + 1];
			strcpy_s(this->denumire, strlen(c.denumire) + 1, c.denumire);
		}

		return *this;
	}

	Continent operator-(const Continent& c)
	{
		Continent con = *this;
		con.nrContinenteVecine = this->nrContinenteVecine - c.nrContinenteVecine;

		return con;
	}

	Continent operator/(const Continent& c)
	{
		Continent con = *this;
		con.suprafata = this->suprafata / c.suprafata;

		return con;
	}


};

int Continent::nrContinente = 7;

void esteAsia(Continent c)
{
	if (c.suprafata < 800000)
	{
		cout << "Continentul nu este Asia.";
	}
	else
	{
		cout << "Continentul este Asia.";
	}

}

class Vulcan
{
private:
	static int gradEruptie;
	const string activitate;
	bool localizare;
	char* nume;
	int altitudine;

public:

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

	Vulcan(const Vulcan& v) :activitate(v.activitate)
	{
		localizare = v.localizare;
		altitudine = v.altitudine;
		this->nume = new char[strlen(v.nume + 1)];
		strcpy_s(this->nume, strlen(v.nume) + 1, v.nume);
	}

	const string getActivitate()
	{
		return this->activitate;
	}

	bool getLocalizare()
	{
		return this->localizare;
	}

	char* getNume()
	{
		return this->nume;
	}

	int getAltitudine()
	{
		return this->altitudine;
	}

	void setLocalizare(bool localizare)
	{
		this->localizare = localizare;
	}

	void setNume(const char* nume) 
	{
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}

	void setAltitudine(int nouaAlt)
	{
		this->altitudine = nouaAlt;
	}

	static int getGradEruptie()
	{
		return gradEruptie;
	}


	~Vulcan()
	{
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}
	}

	void afisare()
	{
		cout << "Vulcanul " << nume << " este " << activitate << ", se afla pe " << (this->localizare ? "mare" : "uscat") << ", are o altitudine de " << altitudine << " metri si are gradul de eruptie " << gradEruptie << "." << endl;
	}

	friend int modificareAltitudine(Vulcan v, int altNoua);

	Vulcan operator=(const Vulcan& v)
	{
		if (this != &v)
		{
			if (this->nume != NULL) {
				delete[]this->nume;
			}
			altitudine = v.altitudine;
			localizare = v.localizare;
			this->nume = new char[strlen(v.nume) + 1];
			strcpy_s(this->nume, strlen(v.nume) + 1, v.nume);
		}
		return *this;
	}

	Vulcan operator*(const Vulcan& v)
	{
		Vulcan vul = *this;
		vul.altitudine = this->altitudine * v.altitudine;

		return vul;
	}

	friend istream& operator>>(istream& citire, Vulcan vulcan)
	{
		char aux[100];
		cout << "Numele vulcanului: ";
		citire >> aux;
		if (vulcan.nume != NULL)
			delete[]vulcan.nume;
		vulcan.nume = new char[strlen(aux) + 1];
		strcpy_s(vulcan.nume, strlen(aux) + 1, aux);
		if (vulcan.localizare == true)
			cout << "Se afla in ocean." << endl;
		else
			cout << "Se afla pe uscat." << endl;
		cout << "Altitudine: ";
		citire >> vulcan.altitudine;
	}

	Vulcan operator+=(const Vulcan& v)
	{
		Vulcan vul = *this;
		vul.altitudine = vul.altitudine + v.altitudine;

		return vul;
	}


};

int  Vulcan::gradEruptie = 2;

int modificareAltitudine(Vulcan v, int altNoua)
{
	v.altitudine = v.altitudine + altNoua;

	return v.altitudine;
}

class Tara
{
private:
	static string oAltaLimbaVorbita;
	const int suprafata;
	string nume;
	int nrJudete;
	char* capitala;
	bool iesireMare;

public:

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

	Tara(const Tara& t) :suprafata(t.suprafata)
	{
		nume = t.nume;
		nrJudete = t.nrJudete;
		iesireMare = t.iesireMare;
		this->capitala = new char[strlen(t.capitala + 1)];
		strcpy_s(this->capitala, strlen(t.capitala + 1), t.capitala);
	}

	void afisare()
	{
		cout << "Tara " << nume << " are o suprafata de " << suprafata << " km^2, " << (this->iesireMare ? " are iesire la mare. " : " nu are iesire la mare. ") << " Pe langa limba nationala, se mai vorbeste si " << oAltaLimbaVorbita << ". Tara este impartita in " << nrJudete << " judete, iar capitala este " << this->capitala << "." << endl;

	}


	const int getSuprafata()
	{
		return suprafata;
	}

	string getNume()
	{
		return nume;
	}

	int getNrJudete()
	{
		return nrJudete;
	}

	char* getCapitala()
	{
		return this->capitala;
	}

	bool getIesireMare()
	{
		return iesireMare;
	}

	void setNume(string nume)
	{
		this->nume = nume;
	}

	void setNrJudete(int nrJudete)
	{
		this->nrJudete = nrJudete;
	}

	void setCapitala(const char* capitala) //e const aici?
	{
		if (this->capitala != NULL)
		{
			delete[]this->capitala;
		}
		this->capitala = new char[strlen(capitala) + 1];
		strcpy_s(this->capitala, strlen(capitala) + 1, capitala);
	}

	void setIesireMare(bool iesireMare)
	{
		this->iesireMare = iesireMare;
	}

	static string getCeLimba()
	{
		return oAltaLimbaVorbita;
	}

	~Tara()
	{
		if (this->capitala != NULL)
		{
			delete[]this->capitala;
		}
	}

	Tara operator=(const Tara& t)
	{
		if (this != &t)
		{
			nrJudete = t.nrJudete;
			iesireMare = t.iesireMare;
			nume = t.nume;
			if (this->capitala != NULL)
				delete[]this->capitala;
			this->capitala = new char[strlen(t.capitala) + 1];
			strcpy_s(this->capitala, strlen(t.capitala) + 1, t.capitala);
		}
		
		return *this;
	}

	Tara operator-=(const Tara& t)
	{
		Tara tara = *this;
		this->nrJudete -= t.nrJudete;

		return *this;
	}

	Tara operator+(const Tara& t)
	{
		Tara tara = *this;
		tara.nrJudete = this->nrJudete + t.nrJudete;
		tara.nume = this->nume + t.nume;
		if (tara.capitala != NULL)
			delete[]tara.capitala;
		tara.capitala = new char[strlen(this->capitala) + strlen(t.capitala) + 1];
		strcpy_s(tara.capitala, strlen(this->capitala) + 1, this->capitala);
		strcpy_s(tara.capitala + strlen(this->capitala), strlen(t.capitala) + 1, t.capitala);

		return tara;
	}

	Tara operator++()
	{
		this->nrJudete += 5;
		return *this;
	}

	Tara operator++(int)
	{
		Tara copie = *this;
		this->nrJudete += 5;
		return copie;
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
	//esteAsia(c2);
	cout << c.getSuprafata() << endl;
	cout << c1.getContinenteVecine() << endl;
	cout << c2.getDenumire() << endl;
	cout << c2.getNrTari() << endl;
	c.setSuprafata(123000);
	c.setContinenteVecine(3);
	c.setDenumire("America de Nord");
	c.afisare();


	//Continent c3 = c + c1;
	//c3.afisare();

	//Continent c3;
	//c3 = c / c1;
	//c3.afisare();


	Vulcan vulcan;
	vulcan.afisare();
	Vulcan v("inactiv", 4207);
	v.afisare();
	Vulcan V(976);
	V.afisare();
	//modificareAltitudine(vulcan, 5000);
	cout << v.getNume() << endl;
	cout << v.getActivitate() << endl;
	cout << v.getAltitudine() << endl;
	cout << v.getGradEruptie() << endl;
	cout << v.getLocalizare() << endl;

	V.setLocalizare(false);
	V.setAltitudine(3000);
	V.setNume("Vezuviu");
	V.afisare();


	Tara tara;
	tara.afisare();
	Tara T(15, 83871);
	T.afisare();
	Tara t("Japonia", 377973, 8);
	t.afisare();
	cout << t.getCapitala() << endl;
	cout << t.getCeLimba() << endl;
	cout << t.getIesireMare() << endl;
	cout << t.getNrJudete() << endl;
	cout << t.getNume() << endl;
	cout << t.getSuprafata() << endl;

	tara.setCapitala("Helsinki");
	tara.setIesireMare(true);
	tara.setNrJudete(54);
	tara.setNume("Finlanda");
	tara.afisare();
}