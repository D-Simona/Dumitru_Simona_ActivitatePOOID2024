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

	TelefonMobil(int id, string producator, int* durate, int zile):id(id)
	{
		this->producator = producator;
		if (durate != nullptr && zile > 0)
		{
			durataZilnicaUtilizare = new int[zile];
			for (int i = 0; i < zile; i++)
			{
				durataZilnicaUtilizare[i] = durate[i]; //deep copy
			}
			nrZile = zile;
		}
		else {
			durataZilnicaUtilizare = nullptr;
			nrZile = 0;
		}
		
	}

	TelefonMobil(const TelefonMobil& t):id(t.id) //constructorul de copiere
	{
		this->producator = t.producator;
		if (t.durataZilnicaUtilizare != nullptr && t.nrZile > 0)
		{
			durataZilnicaUtilizare = new int[t.nrZile];
			for (int i = 0; i < nrZile; i++)
			{
				durataZilnicaUtilizare[i] = t.durataZilnicaUtilizare[i]; //deep copy
			}
			nrZile = t.nrZile;
		}
		else {
			durataZilnicaUtilizare = nullptr;
			nrZile = 0;
		}
	}

	~TelefonMobil()
	{
		if (durataZilnicaUtilizare != nullptr)
		{
			delete[] durataZilnicaUtilizare;
		}
		
	}

	TelefonMobil& operator=(const TelefonMobil& t) //nu se initializeaza var constanta, aceasta ramane aceeasi pentru toate obiectele copiate
	{
		if (this != &t) //evitarea autoasignarii
		{
			if (durataZilnicaUtilizare != nullptr)
			{
				delete[] durataZilnicaUtilizare;
			}
			this->producator = t.producator;
			if (t.durataZilnicaUtilizare != nullptr && t.nrZile > 0)
			{
				durataZilnicaUtilizare = new int[t.nrZile];
				for (int i = 0; i < nrZile; i++)
				{
					durataZilnicaUtilizare[i] = t.durataZilnicaUtilizare[i];
				}
				nrZile = t.nrZile;
			}
			else {
				durataZilnicaUtilizare = nullptr;
				nrZile = 0;
			}
		}
		return *this;
	}

	int getNrZile()
	{
		return nrZile;
	}

	int* getDurataZilnicaUtilizare()
	{
		if (durataZilnicaUtilizare != nullptr && nrZile > 0)
		{
			int* copie = new int[nrZile];
			for (int i = 0; i < nrZile; i++)
			{
				copie[i] = durataZilnicaUtilizare[i];
			}
			return copie;
		}
		return nullptr;
	}

	void setDurataZilnicaUtilizare(int* durata, int nr)
	{
		if (nr > 0 && durata != nullptr)
		{
			if (durataZilnicaUtilizare != nullptr)
			{
				delete[]durataZilnicaUtilizare;
			}
			durataZilnicaUtilizare = new int[nr];
			for (int i = 0; i < nr; i++)
			{
				durataZilnicaUtilizare[i] = durata[i];
			}
			nrZile = nr;
		}
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
	

	int durate[]{3, 2, 1, 2};
	TelefonMobil t4(10, "Motorola", durate, 4);

	TelefonMobil t5(t4); //apelare contructor de copiere
	TelefonMobil t6 = t4;//apelare contructor de copiere

	t1 = t4;
	//t1.operator=(t4);
	int nr = t4.getNrZile();
	int* d = t4.getDurataZilnicaUtilizare();
	for (int i = 0; i < nr; i++)
	{
		cout << d[i] << " ";
	}
	delete[] d; //nu trebuie sa uitam sa facem delete aici!!!!
	d = nullptr;
	int v[]{ 1, 1, 3 };
	t4.setDurataZilnicaUtilizare(v, 3);
}
