
#include<iostream>
#include<algorithm>
using namespace std;

class Persoana {
protected:
	char* nume;
protected:
	int varsta;
public:
	Persoana() {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy_s(this->nume, strlen("Anonim") + 1, "Anonim");
		this->varsta = 0;
	}

	Persoana(const	char* nume, int varsta) {
		if (strlen(nume)==0)
			throw new exception("Introdu nume");
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		if (varsta < 0)
			throw new exception("varsta<0");
	
		this->varsta = varsta;
	}

	Persoana(const Persoana& p) {
		this->nume = new char[strlen(p.nume) + 1];
		strcpy_s(nume, strlen(p.nume) + 1, p.nume);
		this->varsta = p.varsta;
	}

	Persoana& operator=(const Persoana& p) {
		if (this != &p)
		{
			delete[]this->nume;
			this->nume = new char[strlen(p.nume) + 1];
			strcpy_s(nume, strlen(p.nume) + 1, p.nume);
			this->varsta = p.varsta;
		}
		return *this;
	}

	~Persoana() {
			delete[]this->nume;
	}

	void setNume(char* nume) {
		if (strlen(nume) == 0)  
			throw new exception("Numele nu poate fi null"); 
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume)+1, nume);
	}

	char* getNume() const {
		return this->nume;
	}

	void setVarsta(int varsta) {
		if (varsta <= 0)
			throw new exception("varsta<0");
			this->varsta = varsta;
	}

	int getVarsta() {
		return this->varsta;
	}
	friend ostream& operator<<(ostream& out, const Persoana& p);
	friend istream& operator>>(istream& in, Persoana& p);
};
ostream& operator<<(ostream& out, const Persoana& p) {
	out << "Nume: " << p.nume << " ,Varsta: " << p.varsta;
	return out;
}
istream& operator>>(istream& in, Persoana& p) {
	char aux[100];
	cout << "Nume: ";
	in >> aux;

	delete[] p.nume;  
	p.nume = new char[strlen(aux) + 1];
	strcpy_s(p.nume,strlen(aux)+1, aux);

	cout << "Varsta: ";
	in >> p.varsta;

	if (p.varsta <= 0) {
		throw new exception ("Varsta trebuie sa fie un numar pozitiv");
	}

	return in;
}



class Angajat : public Persoana {
protected:
	const int id_angajat;
	string nume_manager;
	double salariu;
	const double salariu_minim;
public:
	Angajat() : id_angajat(0),salariu_minim(0),Persoana() {
		this->nume_manager = "Unknown";
		this->salariu = 0;
	}
	Angajat(const Angajat& a) :id_angajat(a.id_angajat),salariu_minim(a.salariu_minim) {
		this->setNume(a.getNume());
		this->varsta = a.varsta;
		this->nume_manager = a.nume_manager;
		this->salariu = a.salariu;

	}
	Angajat& operator=(const Angajat& a)  {
		if (this != &a)
		{
			Persoana::operator=(a);
			this->nume_manager = a.nume_manager;
			this->salariu = a.salariu;
		}
		return *this;

	}

	Angajat(const char* nume, int varsta, int id_angajat, string nume_manager, double salariu,const double salariu_minim) : Persoana(nume, varsta), id_angajat(id_angajat),salariu_minim(salariu_minim)  {
		if(nume_manager.empty())
			throw new exception("nu e valid");
		this->nume_manager = nume_manager;
		if (salariu < 0)
			throw new exception("salariu<0");
		this->salariu = salariu;
	}

	const int getId_angajat() {
		return this->id_angajat;
	}
	string getnume_manager(){
		return this->nume_manager;

	}
	void setnume_manager(string nume_manager) {
		if (nume_manager.length() == 0)
			throw new exception("Adaugati nume mananger");
		this->nume_manager = nume_manager;
	}

	double getsalariu() {
		return this->salariu;
	}
	void setsalariu(double salariu) {
		if (salariu < salariu_minim)
			throw new exception("Salariul trebuie sa fie >= salariu minim");
		this->salariu = salariu;
	}
	friend ostream& operator<<(ostream& out, const Angajat& a);
	friend istream& operator>>(istream& in, Angajat& a);

}; 



ostream& operator<<(ostream& out, const Angajat& a) {
	out << (Persoana)a;
	out << "id angat: " << a.id_angajat << ", Nume manager: " << a.nume_manager << ", Salariu: " << a.salariu;
	return out;
}
 istream& operator>>(istream& in, Angajat& a) {
	
	in >> (Persoana&)a;

	
	cout << "Manager: ";
	in >> a.nume_manager;

	
	cout << "Salariu: ";
	in >> a.salariu;
	if (a.salariu <= a.salariu_minim)
		throw new exception ("Salariul trebuie sa fie <= decat salariul minim.");

	return in;
}

enum limbaj {
	fullstack = 1, backend = 2, frontend = 3
};

class Programator : public Angajat {
	char* limbajProgramareFolosit;
	limbaj folosit;

public:
	Programator() : Angajat() {
		char* limbajProgramareFolosit = new char[strlen("Unknown") + 1];
		strcpy_s(limbajProgramareFolosit, strlen("Unknown") + 1, "Unknown");
		this->folosit = fullstack;
	}

	Programator(const char* nume, int varsta, int id_angajat, string nume_manager, double salariu,const char* limbajProgramareFolosit, limbaj folosit) : Angajat(nume, varsta, id_angajat, nume_manager, salariu,salariu_minim) {
		this->limbajProgramareFolosit = new char[strlen(limbajProgramareFolosit) + 1];
		strcpy_s(this->limbajProgramareFolosit, strlen(limbajProgramareFolosit) + 1, limbajProgramareFolosit);
		this->folosit = folosit;
	}
	Programator(const Programator& p) : Angajat(p) {
		this->limbajProgramareFolosit = new char[strlen(p.limbajProgramareFolosit) + 1];
		strcpy_s(this->limbajProgramareFolosit, strlen(p.limbajProgramareFolosit) + 1, p.limbajProgramareFolosit);
		this->folosit = p.folosit;
	}
	Programator& operator=(const Programator& p) {
		if (this != &p)
		{
			Angajat::operator=(p);
			delete[]this->limbajProgramareFolosit;
			this->limbajProgramareFolosit = new char[strlen(p.limbajProgramareFolosit) + 1];
			strcpy_s(limbajProgramareFolosit, strlen(p.limbajProgramareFolosit) + 1, p.limbajProgramareFolosit);
			this->folosit = p.folosit;

		}
		return *this;

	}
	~Programator(){
		if (this->limbajProgramareFolosit != NULL)
			delete[]this->limbajProgramareFolosit;
	}

	char* getLimbajProgramareFolosit() {
		return this->limbajProgramareFolosit;
	}
	void setLimbajProgramareFolosit(char* limbajProgramareFolosit) {
		if (strlen(limbajProgramareFolosit) == 0)
			throw new exception("Nu poate fi null");
		this->limbajProgramareFolosit = new char[strlen(limbajProgramareFolosit) + 1];
		strcpy_s(this->limbajProgramareFolosit,strlen(limbajProgramareFolosit)+1, limbajProgramareFolosit);
	}
	limbaj getLimbajfolosit() {
		return this->folosit;
	}
	void setLimbajfolosit(limbaj folosit) {
		this->folosit = folosit;
	}

	string limbajToString(limbaj folosit) {
		switch (folosit) {
		case fullstack:
			return "fullstack";
		case backend:
			return "backend";
		case frontend:
			return "frontend";
		default:
			throw new exception("Valoare invalidă pentru limbaj.");
		}
	}

	limbaj stringToLimbaj(const string& value) {
		if (value == "fullstack") {
			return fullstack;
		}
		else if (value == "backend") {
			return backend;
		}
		else if (value == "frontend") {
			return frontend;
		}
		else {
			throw new exception("String invalid pentru limbaj.");
		}
	}

	friend ostream& operator<<(ostream& out, const Programator& b);
	friend istream& operator>>(istream& in, Programator& b);
};
ostream& operator<<(ostream& out,const Programator& b) {
	out << (Angajat)b;
	out << " Limbaj folosit: " << b.limbajProgramareFolosit << ", Enumerare:" << b.folosit;
	return out;
}
istream& operator>>(istream& in, Programator& p) {

	in >> (Angajat&)p;
	char aux[100];
	cout << "Limbajul de programare: ";
	in >> aux;
	p.setLimbajProgramareFolosit(aux);

	string limbaj_str;
	cout << "Tip limbaj (fullstack, backend, frontend): ";
	in >> limbaj_str;
	p.setLimbajfolosit(p.stringToLimbaj(limbaj_str));

	return in;
}


class Departament {
	char* denumire;
	Angajat* angajati;
	int nr_angajati;
	static int nr_total_angajati;
public:
	double salariuTotal() {
		double total = 0.0;
		for (int i = 0; i < nr_angajati; i++) {
			total += angajati[i].getsalariu();
		}
		return total;
	}

	Departament() {
		this->denumire = new char[strlen("Unknown") + 1];
		strcpy_s(this->denumire, strlen("unknown") + 1, "Unknown");
		this->angajati = nullptr;
		this->nr_angajati = 0;
	}
	Departament(const char* denumire, Angajat* angajati, int nr_angajati) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		this->angajati = new Angajat[nr_angajati];
		for (int i = 0;i < nr_angajati;i++)
			this->angajati[i] = angajati[i];
		this->nr_angajati = nr_angajati;
		this->nr_total_angajati = this->nr_total_angajati + nr_angajati;

	}
	Departament(const Departament& d) {
		this->denumire = new char[strlen(d.denumire) + 1];
		strcpy_s(this->denumire, strlen(d.denumire) + 1, d.denumire);
		this->angajati = new Angajat[d.nr_angajati];
		for (int i = 0;i < nr_angajati;i++)
			this->angajati[i] = d.angajati[i];
		this->nr_angajati = d.nr_angajati;
	}
	Departament& operator=(const Departament& d) {
		if (this != &d)
		{
				delete[]this->denumire;
				delete[]this->angajati;
				this->denumire = new char[strlen(d.denumire) + 1];
				strcpy_s(this->denumire, strlen(d.denumire) + 1, d.denumire);
				this->angajati = new Angajat[d.nr_angajati];
				for (int i = 0;i < nr_angajati;i++) {
					this->angajati = d.angajati;
					this->nr_angajati = d.nr_angajati;
				}
		}
		return *this;
	}
	~Departament()
	{
		delete[]this->denumire;
		delete[]this->angajati;
	}

	
	char* getDenumire() {
		return this->denumire;
	}
	void setDenumire(char* denumire) {
		if (strlen(denumire) == 0)
			throw new exception("Adaugati o denumire: ");
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}

	Angajat* getangajati()
	{
		return this->angajati;
	}
	void setangajati(Angajat* angajati) {
		this->angajati = new Angajat[nr_angajati];
		for (int i = 0;i < nr_angajati;i++)
		{
			this->angajati[i] = angajati[i];
		}
	}
	friend ostream& operator<<(ostream& out, const Departament& d);
	friend istream& operator>>(istream& in, Departament& d);

	Angajat* cautaAngajatDupaNume(const char* nume) {
		for (int i = 0; i < nr_angajati; i++) {
			if (strcmp(angajati[i].getNume(), nume) == 0) {
				return &angajati[i];
			}
		}
		return nullptr;
	}
};
int Departament::nr_total_angajati = 0; 
ostream& operator<<(ostream& out, const Departament& d) {
	out << "Denumire: " << d.denumire << ", Nr angajati: " << d.nr_angajati << endl;
	for (int i = 0; i < d.nr_angajati; i++) {
		out << "Angajat #" << i + 1 << ": " << d.angajati[i] << endl;
	}
	return out;
}

istream& operator>>(istream& in, Departament& d) {
	
	char aux[100];
	cout << "Introduceti denumirea departamentului: ";
	in >> aux;

	d.setDenumire(aux); 
	cout << "Introduceti numarul de angajati: ";
	in >> d.nr_angajati;
	if (d.nr_angajati <= 0) {
		throw new exception("Numarul de angajati trebuie sa fie pozitiv");
	}

	delete[] d.angajati; 
	d.angajati = new Angajat[d.nr_angajati];

	for (int i = 0; i < d.nr_angajati; i++) {
		cout << "Angajatul #" << i + 1 << ":" << endl;
		in >> d.angajati[i]; 
	}

	return in;
}


int main() {
	try {
		Persoana p1("Ion", 30);
		cout << p1 << endl;

		Persoana p2;
		cout << "Introduceti detalii pentru persoana:" << endl;
		cin >> p2;
		cout << p2 << endl;

		Angajat a1("Maria", 25, 101, "Mihai", 3000, 2000);
		cout << a1 << endl;

		Angajat a2;
		cout << "Introduceti detalii pentru angajat:" << endl;
		cin >> a2;
		cout << a2 << endl;

		Programator pr1("Alex", 28, 102, "Ion", 4000, "C++", fullstack);
		cout << pr1 << endl;

		Programator pr2;
		cout << "Introduceti detalii pentru programator:" << endl;
		cin >> pr2;
		cout << pr2 << endl;

		Angajat angajati[] = { a1, a2 };
		Departament d1("IT", angajati, 2);
		cout << d1 << endl;
		

		Departament d2;
		cout << "Introduceti detalii pentru departament:" << endl;
		cin >> d2;
		cout << d2 << endl;
		cout << "Salariul total al departamentului: " << d2.salariuTotal() << endl;

		char numeCautat[100];
		cout << "Introduceti numele angajatului pe care doriti sa-l cautati: ";
		cin >> numeCautat;

		Angajat* angajatGasit = d2.cautaAngajatDupaNume(numeCautat);
		if (angajatGasit) {
			cout << "Angajat gasit:\n" << *angajatGasit << endl;
		}
		else {
			cout << "Nu exista un angajat cu numele \"" << numeCautat << "\" in departament." << endl;
		}


	}
	catch (const exception& e) {
		cout << "Eroare: " << e.what() << endl;
	}

	return 0;
}