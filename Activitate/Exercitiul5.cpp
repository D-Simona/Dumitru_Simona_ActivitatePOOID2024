#include<iostream>
#include<string>

using namespace std;

class Avion {
private:

	const int idAvion;
	int nrLocuri;
	int pasageri;
	char* companie;
	static int nrAvion;

public:

	Avion(): idAvion(++nrAvion){ //constructorul fara parametri
		this->nrLocuri = 0;
		this->pasageri = 0;
		this->companie = new char[strlen("TAROM") + 1];
		strcpy_s(this->companie, strlen("TAROM") + 1, "TAROM");
		this->nrAvion = 0;
	}

	Avion(int nrLocuri, int pasageri, const char* companie) :idAvion(++nrAvion) { //constructor cu parametri
		this->nrLocuri = nrLocuri;
		this->pasageri = pasageri;
		this->companie = new char[strlen(companie) + 1];
		strcpy_s(this->companie, strlen(companie) + 1, companie);
	}

	Avion(const Avion& a):idAvion(++nrAvion){ //constructor de copiere
		this->nrLocuri = a.nrLocuri;
		this->pasageri = a.pasageri;
		this->companie = new char[strlen(a.companie) + 1];
		strcpy_s(this->companie, strlen(a.companie) + 1, a.companie);
	}

	Avion operator=(const Avion& a) {
		if (&a != this) {
			if (this->companie != NULL) {
				delete[]this->companie;
			}
			this->nrLocuri = a.nrLocuri;
			this->pasageri = a.pasageri;
			this->nrAvion = a.nrAvion;
			if (a.companie != NULL) {
				this->companie = new char[strlen(a.companie) + 1];
				strcpy_s(this->companie, strlen(a.companie) + 1, a.companie);
			}
			else {
				this->companie = NULL;
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Avion a);

	~Avion() {
		delete[]this->companie;
	}
};

int Avion::nrAvion = 0;

ostream& operator<<(ostream& o, const Avion a) {
	o << "ID Avion: " << a.idAvion << endl;
	o << "Nr locuri avion: " <<a.nrLocuri << endl;
	o << "Pasageri: " << a.pasageri << endl;
	if (a.companie != NULL) {
		o << "Companie: " << a.companie;
	}
	return o;
}

int main() {
	Avion avion1;
	Avion avion2(40, 32, "WizzAir");
	Avion avion3(50, 40, "Ryanair");
	Avion avion4 = avion3;
	avion4 = avion3;
	cout << avion2;

}