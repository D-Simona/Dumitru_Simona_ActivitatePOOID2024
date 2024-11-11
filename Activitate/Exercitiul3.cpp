#include<iostream>
#include<string>


using namespace std;

//exercitiu facem soft - continuare parcurgere cursuri youtube

class TelefonMobil
{
private:
	string producator;
	int* durataZilnicaUtilizare;
	int nrZile;
	static int anLot;//atribut static pe domeniul privat
public:
	const int id;
	static int anProductie;//atribut static pe domeniul public

	TelefonMobil() : id(-1)
	{
		producator = "";
		durataZilnicaUtilizare = nullptr;
		nrZile = 0;
	}

	TelefonMobil(int id) : id(id)
	{
		producator = "";
		durataZilnicaUtilizare = nullptr;
		nrZile = 0;
	}

	static int getAnLot()//getter static pt atributul static
	{
		return anLot;
	}

	static void setAnLot(int anLot)//setter static pt atributul static
	{
		//this->anLot = anLot; asa nu merge, o metoda statica nu-l primeste pe this
		TelefonMobil::anLot = anLot;
	}

	static int getTotalNumarZile(TelefonMobil* telefoane, int nrTelefoane) //arata cate zile au fost utilizate in toatalitate telefoanele
	{
		int suma = 0;
		if (telefoane != nullptr && nrTelefoane > 0)
		{
			for (int i = 0; i < nrTelefoane; i++)
			{
				suma += telefoane[i].nrZile;
			}
		}
		return suma;
	}
};

int TelefonMobil::anProductie = 2022; //initialiarea unui atribut static se face outline (in afara clasei)
int TelefonMobil::anLot = 2024;

int main()
{
	TelefonMobil t1;
	cout << t1.id << endl;
	TelefonMobil t2(5);
	cout << t2.id << endl;
	cout << TelefonMobil::anProductie << endl;
	cout << t1.anProductie << endl;
	t1.anProductie = 2010;
	cout << t2.anProductie << endl; //un atribut static este comun pentru toate obiectele
	cout << TelefonMobil::getAnLot() << endl;
	cout << t1.getAnLot() << endl;
	t1.setAnLot(2023);
	cout << t2.getAnLot() << endl;
	TelefonMobil t3(7);
	TelefonMobil vector[]{ t1, t2, t3 };
	cout << TelefonMobil::getTotalNumarZile(vector, 3) << endl;//folosim metoda statica atunci cand prelucram mai multe obiecte

}
