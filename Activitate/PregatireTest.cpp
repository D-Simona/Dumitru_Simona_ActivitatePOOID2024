//////Structura test seminar
////
//////Sa se creeze un proiect C++ in mediul Microsoft Visual Studio care sa nu genereze erori la compilare
//////Sa se defineasca clasa X ce contine diferite atribute(inclusiv constante sau statice) dintre care unul este in mod obligatoriu un pointer(char* sau int*).
//////Pentru acestea sa se defineasca o interfata publica de acces. Metodele de tip set trebuie sa valideze valorile de intrare si sa genereze exceptii sau sa afiseze mesaje specifice
////// Sa se defineasca pentru clasa X constructori(implicit si diferite forme cu parametri) si functia destructor(fara a genera memory leaks)
//////Sa se defineasca pentru clasa X constructorul de copiere
//////Sa se supraincarce pentru clasa X operatorul = fara a avea memory leaks
//////Sa se supraincarce operatorul << / >> pentru clasa X
////// Sa se implementeze 2 metode care sa prelucreze atribute ale clasei
//////Sa se supraincarce operatorul Y1, Y2 pentru clasa X
//////Suplimentar - Sa se exemplifice elementele implementate in programul principal.Sa fie utilizat Debugger-ul pentru a vizualiza memoria rezervata datelor si pentru a urmari apelurile diferitelor metode
//////ATENTIE !!!Metodele implementate trebuie sa evite shallow - copy si generearea de memory leaks.
//////
//////ATENTIE !!!Dupa fiecare etapa, programul trebuie sa compileze si sa ruleze.In caz contrar, se considera neindeplinit primul punct din evaluare.
//////
//////Operatori luati in considerare : =, ++ si -- in cele 2 forme(post si prefixata), [](indexare), +, -, *, / , +=, -+, *=, >> si << (stream - uri pentru lucrul cu consola), 
////// !, cast la orice tip(implicit si explicit), () (functie), > , < . >= , <= , ==
////
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Cofetarie {
//private:
//	string nume;
//	int nrAngajati;
//	float* salarii;
//	bool esteVegana;
//	const int anDeschidere; //pe acesta il initializam in signatura constructorului
//	float adaos;
//	static int TVA; //pe acesta il initializam in afara clasei
//
//public:
//
//	Cofetarie() :anDeschidere(2024) { //constructorul default/implicit/fara parametri
//		this->nume = "Dulcinela";
//		this->nrAngajati = 0;
//		this->esteVegana = true;
//		this->adaos = 15;
//		this->salarii = NULL;
//	}
//
//	Cofetarie(string nume, int nrAngajati, bool vegan, int an, float adaos) :anDeschidere(an) {//constructorul cu parametri; in lista de parametri avem si un int an la care face referire anDeschidere
//		this->nume = nume;
//		this->nrAngajati = nrAngajati;
//		this->esteVegana = vegan;
//		this->adaos = adaos;
//		this->salarii = new float[nrAngajati]; //sablon pt vectori
//		for(int i=0;i<nrAngajati;i++){
//			this->salarii[i] = 1000 + i * 100;
//		}
//	}
//	
//	Cofetarie(const Cofetarie& c) :anDeschidere(c.anDeschidere) { //constructorul de copiere
//		this->nume = c.nume;
//		this->nrAngajati = c.nrAngajati;
//		this->esteVegana = c.esteVegana;
//		this->adaos = c.adaos;
//		this->salarii = new float[c.nrAngajati]; //sablon pt vectori
//		for (int i = 0; i < c.nrAngajati; i++) {
//			this->salarii[i] = c.salarii[i];
//		}
//	}
//
//	Cofetarie operator=(const Cofetarie& c) { //operatorul =
//		if (&c != this) { //primul pas este verificare de autoatribuire
//			this->nume = c.nume;
//			this->nrAngajati = c.nrAngajati;
//			this->esteVegana = c.esteVegana;
//			this->adaos = c.adaos;
//			if (this->salarii != NULL) {//pasul 2 este sa verificam daca exista ceva alocat deja la adresa respectiva => verificare memory leak
//				delete[]this->salarii;
//			}
//			this->salarii = new float[c.nrAngajati];
//			for (int i = 0; i < c.nrAngajati; i++) {
//				this->salarii[i] = c.salarii[i];
//			}
//		}
//	}
//
//	~Cofetarie() {
//		if (this->salarii) {
//			delete[]this->salarii;
//		}
//	}
//
//};
//
//int Cofetarie::TVA = 9;
//
//
//int main() {
//
//
//	Cofetarie cofetarie1;
//	Cofetarie cofetarie2("Projiturela", 20, 0, 2022, 20);
//	Cofetarie cofetarie3 = cofetarie2;
//
//
//	return 0;
//}
//
