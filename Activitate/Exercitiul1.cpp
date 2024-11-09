#include <iostream>
#include<string>

using namespace std;

//exercitiu facem soft - Bogdan Iancu - parcurgere cursuri Youtube
class TelefonMobil {
public:
	int nivelBaterie;
	int id;

	TelefonMobil() //contructor
	{
		producator = "";
		model = "";
		nivelBaterie = 0;
	}

	TelefonMobil(string _producator, string _model) //constructor cu parametri
	{
		producator = _producator;
		model = _model;
		nivelBaterie = 0;
	}

	TelefonMobil(int _nivelBaterie) //constrructor cu un singur parametru
	{
		nivelBaterie = _nivelBaterie;
	}

	void afisare() //functie de afisare
	{
		cout << "Producator: " << this->producator << endl;
		cout << "Model: " << this->model << endl;
		cout << "nivelBaterie:" << this->nivelBaterie << endl;
	}

	void incarca(int nivelIncarcare)
	{
		nivelBaterie += nivelIncarcare;
	}
protected:
	string producator;
private:
	string model;
};

int main() {
	TelefonMobil telefonPersonal;
	TelefonMobil* pTelefon = new TelefonMobil(); 
	delete pTelefon;
	pTelefon = nullptr;

	TelefonMobil telefonDeServiciu("Samsung", "S20");
	telefonDeServiciu.afisare();

	pTelefon = new TelefonMobil("Apple", "Iphone 14");
	pTelefon->afisare();
	delete pTelefon;
	pTelefon = nullptr;

	TelefonMobil telefon3(25);
	TelefonMobil telefon3 = 30;

	telefonPersonal.nivelBaterie = 20;
	telefonPersonal.incarca(50);

	cout << telefonPersonal.nivelBaterie << endl;

}