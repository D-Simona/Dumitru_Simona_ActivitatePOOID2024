#include<iostream>
#include<string>

using namespace std;

class Persoana {
private:
	int* varsta;

public: 
	string nume;
	char sex;
	float inaltime;

	Persoana() {
		this->nume = "Nume";
		this->sex = 'F/M';
		this->inaltime = inaltime;
		this->varsta = nullptr;
	}

	Persoana(string _nume, char _sex, float _inaltime, int* _varsta) {
		this->nume = _nume;
		this->sex = _sex;
		this->inaltime = _inaltime;
		this->varsta = _varsta; //asa nu..
	}

	void afisare() {
		cout << "Nume: " << this->nume << endl;
		cout << "Sex: " << this->sex << endl;
		cout << "Inaltime:" << this->inaltime << endl;
		cout << "Varsta: " << this->varsta << endl;
	}

};

int main() {
	Persoana persoana1;
	persoana1.afisare();
	Persoana persoana2;
}
