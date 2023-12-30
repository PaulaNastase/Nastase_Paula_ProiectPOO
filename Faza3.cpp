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
		this->denumire = new char[strlen(c.denumire) + 1];
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

	friend istream& operator>>(istream& citire, Continent& c)
	{
		char aux[15];
		cout << "Numele continentului: ";
		citire >> aux;
		if (c.denumire != NULL)
			delete[]c.denumire;
		c.denumire = new char[strlen(aux) + 1, aux];
		strcpy_s(c.denumire, strlen(aux) + 1, aux);
		cout << endl;
		cout << "Suprafata continentului: ";
		citire >> c.suprafata;
		cout << endl;
		cout << "Cate continente vecine are? ";
		citire >> c.nrContinenteVecine;
		cout << endl;

		return citire;
	}

	friend ifstream& operator>>(ifstream& file, Continent& c)
	{
		char aux[15];
		file >> aux;
		if (c.denumire != NULL)
			delete[]c.denumire;
		c.denumire = new char[strlen(aux) + 1, aux];
		strcpy_s(c.denumire, strlen(aux) + 1, aux);
		file >> c.suprafata;
		file >> c.nrContinenteVecine;

		return file;
	}

	friend ofstream& operator<<(ofstream& console, Continent c)
	{
		int l;
		l = strlen[c.denumire + 1];
		if (l != NULL)
		{
			for (int i = 0; i < l; i++)
			{
				console << c.denumire[i];
			}
		}
		console << c.suprafata << " " << c.nrContinenteVecine << endl;

		return console;
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
		this->nume = new char[strlen(v.nume) + 1];
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

	Vulcan operator+=(const Vulcan& v)
	{
		Vulcan vul = *this;
		vul.altitudine = vul.altitudine + v.altitudine;

		return vul;
	}

	friend istream& operator>>(istream& citire, Vulcan& v)
	{
		char aux[15];
		cout << "Numele vulcanului: ";
		citire >> aux;
		if (v.nume != NULL)
			delete[]v.nume;
		v.nume = new char[strlen(aux) + 1];
		strcpy_s(v.nume, strlen(aux) + 1, aux);
		cout << endl;
		cout << "Altitudinea vulcanului: ";
		citire >> v.altitudine;
		cout << endl;
		cout << "Vulcanul se afla in ocean (0) sau pe uscat(1)? ";
		citire >> v.localizare;

		return citire;
	}

	friend ifstream& operator>>(ifstream& fis, Vulcan& v)
	{
		char aux[15];
		fis >> aux;
		if (v.nume != NULL)
		{
			delete[]v.nume;
		}
		v.nume = new char[strlen(aux) + 1];
		strcpy_s(v.nume, strlen(aux) + 1, aux);
		fis >> v.altitudine;
		fis >> v.localizare;

		return fis;
	}

	friend ofstream& operator<<(ofstream& ecran, Vulcan v)
	{
		int l;
		l = strlen[v.nume + 1];
		if (l!= NULL)
		{
			for (int i = 0; i < l; i++)
			{
				ecran << v.nume[i];
			}
		}
		ecran << v.altitudine << " " << v.localizare;

		ecran << endl;
		return ecran;
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
		this->capitala = new char[strlen(t.capitala) + 1];
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

	friend istream& operator>>(istream& citire, Tara& t)
	{
		cout << "Numele tarii: ";
		citire >> t.nume;
		cout << endl;
		cout << "Numarul de judete: ";
		citire >> t.nrJudete;
		cout << "Are iesire la mare? 0-NU, 1-DA ";
		citire >> t.iesireMare;
		char aux[15];
		cout << "Capitala tarii: ";
		citire >> aux;
		if (t.capitala != NULL)
			delete[]t.capitala;
		t.capitala = new char[strlen(aux) + 1];
		strcpy_s(t.capitala, strlen(aux) + 1, aux);

		return citire;
	}

	friend ostream& operator<<(ostream& afisare, const Tara& t)
	{
		afisare << "Numele tarii: " << t.nume << endl;
		afisare << "Numarul de judete: " << t.nrJudete << endl;
		afisare << (t.iesireMare ? "Are iesire la mare." : "Nu are iesire la mare.") << endl;
		afisare << "Capitala tarii: ";
		for (int i = 0; i < strlen(t.capitala); i++)
			afisare << t.capitala[i];

		return afisare;
	}

	void CitireDinFisBinar(fstream& f)
	{
		int lungime;
		f.read((char*)&lungime, sizeof(int));
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}
		this->nume = char[lungime + 1];
		for (int i = 0; i < lungime; i++)
		{
			f.read((char*)&this->nume[i], sizeof(char));
		}
		this->nume[lungime] = '\0';
		f.read((char*)&this->nrJudete, sizeof(int));
		f.read((char*)&this->iesireMare, sizeof(bool));
		int l;
		f.read((char*)&l, sizeof(int));
		char* this->capitala = new char[l];
		f.read(this->capitala, l);
	}

	void ScriereInFisBinar(fstream& f)
	{
		int lungime = strlen(this->nume);
		f.write((char*)&lungime, sizeof(int));
		for (int i = 0; i < lungime; i++)
		{
			f.write((char*)&this->nume[i], sizeof(char));
		}
		f.write((char*)&this->nrJudete, sizeof(int));
		f.write((char*)&this->iesireMare, sizeof(bool));
		int l = strlen(capitala) + 1;
		f.write((char*)&l, sizeof(int));
		f.write(this->capitala, l);
	}
};

string Tara::oAltaLimbaVorbita = "limba engleza";

class Emisfera
{
private:
	int nrTari;
	Tara* tari;
	string tipEmisfera;
	int nrOceane;

public:
	Emisfera()
	{
		this->tipEmisfera = "Nordica";
		this->nrOceane = 3;
		this->nrTari = 4;
		Tara* tari = new Tara[nrTari];
	}

	Emisfera(string tipEmisfera, int nrOceane, int nrTari): nrTari(nrTari)
	{
		this->tipEmisfera = tipEmisfera;
		this->nrOceane = nrOceane;
		if (this->nrTari != NULL)
		{
			this->tari = new Tara[nrTari];
			for (int i = 0; i < nrTari; i++)
			{
				this->nrTari[i] = nrTari[i];
			}
		}
		else
			this->tari = NULL;
	}

	Emisfera(const Emisfera& e)
	{
		this->tipEmisfera = e.tipEmisfera;
		this->nrOceane = e.nrOceane;
		if (nrTari != 0)
		{
			this->tari = new Tara[nrTari];
			for (int i = 0; i < nrTari; i++)
			{
				this->tari[i] = e.tari[i];
			}
		}
		else
			this->tari = NULL;
	}

	int getNrTari()
	{
		return this->nrTari;
	}

	Tara* getTari()
	{
		return this->tari;
	}

	Tara getTara(int index)
	{
		return this->tari[index];
	}

	string getTipEmisfera()
	{
		return this->tipEmisfera;
	}

	int getNrOceane()
	{
		return this->nrOceane;
	}

	void setNrTari(int nrTari)
	{
		this->nrTari = nrTari;
	}

	void setNrOceane(int nrOceane)
	{
		this->nrOceane = nrOceane;
	}

	void setTipEmisfera(string tipEmisfera)
	{
		if (tipEmisfera.length() > 3)
		{
			this->tipEmisfera = tipEmisfera;
		}
	}

	void setTari(int nrTari, Tara* Tari)
	{
		if (nrTari > 0)
		{
			this->nrTari = nrTari;
			if (this->tari != NULL)
			{
				delete[]this->tari;
			}
			this->tari = new int[nrTari];
			for (int i = 0; i < nrTari; i++)
				this->tari[i] = Tari[i];
		}
	}

	Tara& operator[](int index) {
	if (index >= 0 && index < this->nrTari)
	{
		return this->tari[index];
	}

	Emisfera operator=(Emisfera & e)
	{
		if (this != &e)
		{
			if (this->nrTari != NULL)
				delete[]this->nrTari;
			this->nrTari = e.nrTari;
			this->nrOceane = e.nrOceane;
			this->tipEmisfera = e.tipEmisfera;
			if (this->nrTari != 0)
			{
				this->tari = new int[this->nrTari];
				for (int i = 0; i < this->nrTari; i++)
					this->tari[i] = e.tari[i];
			}
			else this->tari = NULL;
		}
	}

	~Emisfera()
	{
		if (this->tari != NULL)
			delete[]this->tari;
	}

	friend ostream& operator<<(ofstream& afisare, const Emisfera& e)
	{
		afisare << "Emisfera " << e.getTipEmisfera() << " are " << e.getNrOceane() << " oceane si " << e.getNrTari() << " tari: " << endl;
		if (e.nrTari != NULL)
		{
			for (int i = 0; i < e.nrTari; i++)
			{
				afisare << e.tari[i] < ", ";
			}
		}
		else afisare << " - ";

		afisare << endl;
		return afisare;
	}

	void citireDinFisBinar(fstream& f)
	{
		f.read((char*)&nrTari, sizeof(int));
		f.read((char*)&nrOceane, sizeof(int));
		int lungime;
		f.read((char*)&lungime, sizeof(int));
		if (this->tipEmisfera != NULL)
		{
			delete[]this->tipEmisfera;
		}
		this->tipEmisfera = new char[lungime + 1];
		for (int i = 0; i < lungime; i++)
		{
			f.read((char*)&this->tipEmisfera[i], sizeof(char));
		}
		this->tipEmisfera[lungime] = '\0';
	}

	void scriereInFisBinar(fstream& f)
	{
		f.write((char*)&nrTari, sizeof(int));
		f.write((char*)&nrOceane, sizeof(int));
		int lungime = strlen(this->tipEmisfera);
		f.write((char*)&lungime, sizeof(int));
		for (int i = 0; i < lungime; i++)
		{
			f.write((char*)&this->tipEmisfera[i], sizeof(char));
		}
		//f.write((char*)&tari, sizeof(Tara)); GASESTE O METODA DE A SCRIE UN VECTOR DE OBIECTE INTR-UN FISIER BINAR
		//TREBUIE SCRIS CEVA SI IN MAIN?
	}
};

int main()
{
	Continent c;
	c.afisare();
	Continent c1(12, 17840000);
	c1.afisare();
	Continent c2(48, 1, 44579000);
	c2.afisare();
	esteAsia(c2);
	cout << c.getSuprafata() << endl;
	cout << c1.getContinenteVecine() << endl;
	cout << c2.getDenumire() << endl;
	cout << c2.getNrTari() << endl;
	c.setSuprafata(123000);
	c.setContinenteVecine(3);
	c.setDenumire("America de Nord");
	c.afisare();


	Continent c3 = c + c1;
	c3.afisare();

	Continent c3;
	c3 = c / c1;
	c3.afisare();

	Continent* v_continent = new Continent[2];
	Continent c4;
	cin >> c4;
	Continent c5;
	cin >> c5;
	v_continent[0] = c4;
	v_continent[1] = c5;


	Vulcan vulcan;
	vulcan.afisare();
	Vulcan v("inactiv", 4207);
	v.afisare();
	Vulcan V(976);
	V.afisare();
	modificareAltitudine(vulcan, 5000);
	cout << v.getNume() << endl;
	cout << v.getActivitate() << endl;
	cout << v.getAltitudine() << endl;
	cout << v.getGradEruptie() << endl;
	cout << v.getLocalizare() << endl;

	V.setLocalizare(false);
	V.setAltitudine(3000);
	V.setNume("Vezuviu");
	V.afisare();

	Vulcan* v_vulcan = new Vulcan[2];
	Vulcan v1;
	cin >> v1;
	Vulcan v2;
	cin >> v2;
	v_vulcan[0] = v1;
	v_vulcan[1] = v2;

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

	Tara* v_tara = new Tara[2];
	Tara t1;
	cin >> t1;
	Tara t2;
	cin >> t2;
	v_tara[0] = t1;
	v_tara[1] = t2;

	Tara** pp_tara = new Tara * [2];
	for (int i = 0; i < 2; i++)
		pp_tara[i] = new Tara[2];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			cin >> pp_tara[i][j];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			cout << pp_tara[i][j];


}