#include<iostream>
#include<string>

using namespace std;

class Farmacie {
private:
	const int CODUnic;
	string adresa;
	int nrMedicamente;
	float* preturiMedicamente;
	static int cod;

public:

	Farmacie() :CODUnic(++cod) {
		this->adresa = "Strada Frumoasa";
		this->nrMedicamente = 0;
		this->preturiMedicamente = nullptr;
	}

	Farmacie(string adresa, int nrMedicamente, float* preturiMedicamente) :CODUnic(++cod) {
		this->adresa = adresa;
		this->nrMedicamente = nrMedicamente;
		this->preturiMedicamente = new float[nrMedicamente];
		for (int i = 0; i < nrMedicamente; i++) {
			this->preturiMedicamente[i] = preturiMedicamente[i];
		}
		delete[]preturiMedicamente;
	}

	Farmacie(const Farmacie& f) :CODUnic(++cod) {
		this->adresa = f.adresa;
		this->nrMedicamente = f.nrMedicamente;
		this->preturiMedicamente = new float[nrMedicamente];
		for (int i = 0; i < f.nrMedicamente; i++) {
			this->preturiMedicamente[i] = f.preturiMedicamente[i];
		}
	}

	string getAdresa() {
		return this->adresa;
	}

	void setAdresa(string adresaNoua) {
		if (adresa.length() > 2) {
			this->adresa = adresaNoua;
		}
	}

	int getNrMedicamente() {
		return this->nrMedicamente;
	}
	
	const int getCodUnic() {
		return this->CODUnic;
	}

	Farmacie operator=(const Farmacie& f) {
		if (this != &f) {
			this->adresa = f.adresa;
			this->nrMedicamente = f.nrMedicamente;
			if (this->preturiMedicamente != nullptr) {
				delete[]this->preturiMedicamente;
			}
			this->preturiMedicamente = new float[nrMedicamente];
			for (int i = 0; i < f.nrMedicamente; i++) {
				this->preturiMedicamente[i] = f.preturiMedicamente[i];
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, Farmacie f);
	friend istream& operator>>(istream& in, Farmacie& f);

	~Farmacie() {
		if(this->preturiMedicamente!=nullptr)
			delete[]this->preturiMedicamente;
	}
};

int Farmacie::cod = 0;

ostream& operator<<(ostream& out, Farmacie f) {
	out << "Cod Unic: " << f.CODUnic << endl;
	out << "Adresa: " << f.adresa << endl;
	out << "Nr Medicamente: " << f.nrMedicamente << endl;
	for (int i = 0; i < f.nrMedicamente; i++) {
		out << f.preturiMedicamente[i];
	}
	return out;
}

istream& operator>>(istream& in, Farmacie& f) {
	cout << "Adresa: ";
	in >> f.adresa;
	cout << "Nr Medicamente: ";
	in >> f.nrMedicamente;
	if (f.preturiMedicamente != nullptr) {
		delete[]f.preturiMedicamente;
	}
	f.preturiMedicamente = new float[f.nrMedicamente];
	for (int i = 0; i < f.nrMedicamente; i++) {
		cout << "Pret pt medicamentul " << (i + 1) << " : ";
		in >> f.preturiMedicamente[i];
	}
	return in;
}

int main() {

	Farmacie farmacie1;
	Farmacie farmacie2("Strada Sanatoasa", 3, new float[3]{1, 2, 3});
	Farmacie farmacie3("strada OK", 2, new float[2] { 5,6 });
	cout << farmacie1;

	return 0;
}