#include<iostream>
#include<string>

using namespace std;

class Portofel {
private:
	const int idPortofel;
	int nrBuzunare;
	int* latimeBuzunare;
	static int nrPortofel;

public:
	Portofel():idPortofel(++nrPortofel) {
		this->nrBuzunare = 0;
		this->latimeBuzunare = nullptr;
	}

	Portofel(int nrBuzunare, const int* latimeBuzunare) :idPortofel(++nrPortofel){
		this->nrBuzunare = nrBuzunare;
		this->latimeBuzunare = new int[nrBuzunare];
		for(int i = 0; i < nrBuzunare; i++) {
			this->latimeBuzunare[i] = latimeBuzunare[i]; //imi da exceptie
		}
	}

	~Portofel() {
		if (this->latimeBuzunare != nullptr) {
			delete[]this->latimeBuzunare;
		}
		
	}

	friend ostream& operator<<(ostream& out, Portofel p) {
		out << "Id portofel: " << p.idPortofel << endl;
		out << "Nr buzunare: " << p.nrBuzunare << endl;
		if (p.latimeBuzunare != nullptr) {
			for (int i = 0; i < p.nrBuzunare; i++) {
				out << "LatimeBuzunare: " << p.latimeBuzunare;
			}
		}
		return out;
	}
};

int Portofel::nrPortofel = 0;

int main() {
	Portofel portofel1;
	cout<< portofel1;
	int* param = new int[2] {1, 2};
	Portofel portofel2(3, param);
	cout << portofel2;
}

