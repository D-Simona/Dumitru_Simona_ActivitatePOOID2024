#include <iostream>
#include<string>

using namespace std;

//exercitiu facem soft - Bogdan Iancu
class TelefonMobil {
public:
	int nivelBaterie;
	int id;

	void incarca(int nivelIncarcare) {
		nivelBaterie += nivelIncarcare;
	}
protected:
	string producator;
	string model;
};

int main() {
	TelefonMobil telefonPersonal;
	TelefonMobil telefonDeServiciu;

	telefonPersonal.nivelBaterie = 20;
	telefonPersonal.incarca(50);

	cout << telefonPersonal.nivelBaterie << endl;
	
}