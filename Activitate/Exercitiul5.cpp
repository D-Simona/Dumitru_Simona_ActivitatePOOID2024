#include<iostream>

using namespace std;

class Avion {
private:

	const int idAvion;
	int nrLocuri;
	int pasageri;
	char* companie;
	static int nrAvion;

public:

	Avion(): idAvion(++nrAvion){ 
		this->nrLocuri = 0;
		this->pasageri = 0;
		this->companie = new char[strlen("TAROM") + 1];
		strcpy_s(this->companie, strlen("TAROM") + 1, "TAROM");
		this->nrAvion = 0;
	}

	Avion(int nrLocuri, int pasageri, const char* companie) :idAvion(++nrAvion) { 
		this->nrLocuri = nrLocuri;
		this->pasageri = pasageri;
		this->companie = new char[strlen(companie) + 1];
		strcpy_s(this->companie, strlen(companie) + 1, companie);
	}

	Avion(const Avion& a):idAvion(++nrAvion){ 
		this->nrLocuri = a.nrLocuri;
		this->pasageri = a.pasageri;
		this->companie = new char[strlen(a.companie) + 1];
		strcpy_s(this->companie, strlen(a.companie) + 1, a.companie);
	}

	int getNrLocuri() {
		return this->nrLocuri;
	}

	void setNrLocuri(int locuri) {
		if (locuri > 0) {
			this->nrLocuri = locuri;
		}
	}

	int getPasageri() {
		return this->pasageri;
	}

	void setPasageri(int _pasageri) {
		if (_pasageri > 0) {
			this->pasageri = _pasageri;
		}
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

	operator int() { 
		return pasageri;
	}

	bool operator>(Avion& a) {
		if (this->nrLocuri > a.nrLocuri) {
			return true;
		}
		else
			return false;
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
	avion3.setNrLocuri(60);
	cout << avion3.getNrLocuri() << endl;
	avion3.setPasageri(20);
	cout << avion3.getPasageri() << endl;
	Avion avion4 = avion3;
	avion4 = avion3;
	cout << avion2 << endl;
	cout << (avion2 > avion3) << endl;
	cout << (avion3 > avion2);
}