#include<iostream>
#include<string>

using namespace std;

class Autobuz {
private:
	static int nrAutobuze;
	const int idAutobuz;
	int capacitate;
	int nrPersoaneImbarcate;
	char* producator;

public:
	Autobuz() : idAutobuz(++nrAutobuze) { //constructor fara parametri
		this->nrAutobuze = 1;
		this->capacitate = 25;
		this->nrPersoaneImbarcate = 20;
		verificareNrPersoane();
		this->producator = new char[strlen("VW") + 1];
		strcpy_s(this->producator, strlen("VW") + 1, "VW");
	}

	Autobuz(int capacitate, int nrPersoaneImbarcate, const char* producator) : idAutobuz(++nrAutobuze) { //constructor cu parametri
		this->capacitate = capacitate;
		this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		verificareNrPersoane();
		this->producator = new char[strlen(producator) + 1];
		strcpy_s(this->producator, strlen(producator) + 1, producator);
	}

	int verificareNrPersoane() { //metoda pt verificare nrPersoaneImbarcate < capacitate si  nrPersoaneImbarcate are valori pozitive
		int verificare = 0;
		while (verificare == 0){
			if (this->nrPersoaneImbarcate > this->capacitate || this->nrPersoaneImbarcate<0){
				cout <<"Capacitatea autobuzului este: "<< this->capacitate << " Introduceti o valoare corecta: " << endl;
				cin >> this->nrPersoaneImbarcate;
			}
			else {
				verificare = 1;
			}
		}
		return this->nrPersoaneImbarcate;
		cout << endl;
	}

	Autobuz(const Autobuz& a) : idAutobuz(++nrAutobuze){ //constructor copiere
		this->capacitate = a.capacitate;
		this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
		if (a.producator != NULL) {
			this->producator = new char[strlen(a.producator) + 1];
			strcpy_s(this->producator, strlen(a.producator) + 1, a.producator);
		}
		else {
			this->producator = NULL;
		}

	}

	Autobuz operator=(const Autobuz& a) { //operatorul de atribuire
		if (&a != this) { //verificare autoasignare
			if (this->producator != NULL) {
				delete[]this->producator;
			}
			this->capacitate = a.capacitate;
			this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
			if (a.producator != NULL) { //memory leak check
				this->producator = new char[strlen(a.producator) + 1];
				strcpy_s(this->producator, strlen(a.producator) + 1, a.producator);
			}
			else {
				this->producator = NULL;
			}
		}
		return *this;
	}

	int getCapacitate() const{ //metoda accesor GET pt capacitate
		return this->capacitate;
	}

	void setCapacitate(int capacitateNoua) { //metoda accesor SET pt capacitate
		if (capacitateNoua > 0)
			this->capacitate = capacitateNoua;
	}

	char* getProducator() { //metoda accesor GET pt produator
		return this->producator;
	}

	void setProducator(const char* producatorNou) { //metoda accesor SET pt producator
		if (this->producator != NULL)
			delete[]this->producator;
		this->producator = new char[strlen(producatorNou) + 1];
		strcpy_s(this->producator, strlen(producatorNou) + 1, producatorNou);
	}

	void afisare() { //functie afisare
			
		cout << "Nr autobuze: " << this->nrAutobuze << endl;
		cout << "Id Autobuz: " << this->idAutobuz << endl;
		cout << "Capacitate: " << this->capacitate << endl;
		cout << "Nr persoane imbarcate: " << this->nrPersoaneImbarcate << endl;
		if(this->producator!=NULL)
			cout << "Producator: " << this->producator << endl;
		cout << endl;
	}

	int getNrLocuriLibere() const { //metoda verificare locuri libere
		int locuriLibere = 0;
		if (this->capacitate > 0) {
			locuriLibere = this->capacitate - this->nrPersoaneImbarcate;
		}
		return locuriLibere;
	}

	explicit operator int() { //operator cast
		return nrPersoaneImbarcate;
	}
	
	bool operator>(Autobuz& a) { //operatorul >
		return this->capacitate > a.capacitate; //returneaza 1 pt adevarat, 0 pt fals

	}

	friend ostream& operator<<(ostream& out, const Autobuz a);
	
	~Autobuz() { //destructor
		if (this->producator != NULL) {
			delete[]this->producator;
		}
	}
};

int Autobuz::nrAutobuze=0; //initializare atribut static in afara clasei

ostream& operator<<(ostream& out, const Autobuz a) { //operatorul de flux << supraincarcat prin functie globala
	out << "Nr autobuze: " << a.nrAutobuze << "; " << "Id Autobuz: " << a.idAutobuz << "; " << "Capacitate: " << a.capacitate << "; " << "Nr persoane imbarcate: " << a.nrPersoaneImbarcate << "; ";
	if (a.producator != NULL) {
		out << "Producator: " << a.producator << endl;
	}
	return out;
}


int main()
{
	Autobuz autobuz1;
	autobuz1.afisare();

	Autobuz autobuz2(20, 15, "BMW");
	autobuz2.afisare();
	cout <<"Capacitatea autobuzului 2 este: " << autobuz2.getCapacitate() << endl;
	autobuz2.setCapacitate(25);
	cout << "Capacitatea noua pentru autobuzul 2 este: " << autobuz2.getCapacitate() << endl;
	cout << endl;
	
	int locuriLibere = autobuz2.getNrLocuriLibere();
	cout << "Locuri libere: "<< locuriLibere << endl;
	cout << endl;

	Autobuz autobuz3(30, 31, "AUDI");
	autobuz3.afisare();

	Autobuz autobuz4 = autobuz3;
	autobuz4.afisare();

	cout<< autobuz4.getProducator()<<endl;
	autobuz4.setProducator("MB");
	cout << autobuz4.getProducator() << endl;

	autobuz2 = autobuz1;
	cout << autobuz2;

	int persoaneImbarcate = (int)autobuz4;
	cout << persoaneImbarcate<< endl;
	cout<< (autobuz2 > autobuz3)<<endl;
	cout << (autobuz3 > autobuz2) << endl;

	return 0;
}