//#include<iostream>
//
//using namespace std;
//
//class Persoana {
//public:
//	int varsta;
//	Persoana (int v=30):varsta (v){}
//};
//
//class Profesor {
//public:
//	int varsta;
//	Profesor(int v=20) : varsta (v){}
//	operator Persoana() {
//		Persoana p;
//		p.varsta = varsta;
//		return p;
//	}
//};
//
//Persoana f(Persoana p) {
//	p.varsta++;
//	return p;
//}
//
//int main() {
//	Persoana p;
//	f(p);
//	cout << endl << p.varsta;
//	Profesor prof;
//	f(prof);
//	cout << " " << prof.varsta;
//	cin.get();
//}//la rularea programului se vor afisa doar varstele de 30 si 20 
////deoarece ambele obiecte sunt temporare la transmoiterea prin valoare