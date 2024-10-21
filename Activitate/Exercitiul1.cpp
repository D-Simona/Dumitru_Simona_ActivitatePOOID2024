#include <iostream>
#include<string>

using namespace std;

class TelefonMobil {
public:
	int nivelBaterie;

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