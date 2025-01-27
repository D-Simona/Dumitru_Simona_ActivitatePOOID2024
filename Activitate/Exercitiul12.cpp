#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Casa
{
	bool cuEtaj;
	float amprentaSol;
	int nrCamere;
	int* camereLaEtaj;

public:
	Casa()
	{
		this->cuEtaj = false;
		this->amprentaSol = 0;
		this->nrCamere = 0;
		this->camereLaEtaj = NULL;
	}


	float getAmprentaSol()
	{
		return this->amprentaSol;
	}
	int getNrCamere()
	{
		return this->nrCamere;
	}
	void setNrCamere(int nr)
	{
		this->nrCamere = nr;
	}

	Casa(bool cuEtaj, float amprentaSol, int nrCamere, int* camereLaEtaj)//validarile se fac pe paramteri nu pe atribute!!!!!!
	{
		this->cuEtaj = cuEtaj;
		this->amprentaSol = amprentaSol;
		if (nrCamere > 0 && camereLaEtaj != NULL)
		{
			this->nrCamere = nrCamere;
			this->camereLaEtaj = new int[this->nrCamere];
			for (int i = 0; i < this->nrCamere; i++)
			{
				this->camereLaEtaj[i] = camereLaEtaj[i];
			}
		}
		else
		{
			this->nrCamere =0;
			this->camereLaEtaj = NULL;
		}
	}
	Casa(const Casa& c)
	{
		if (this->camereLaEtaj != NULL)
		{
			delete[]this->camereLaEtaj;
		}
		this->cuEtaj = c.cuEtaj;
		this->amprentaSol = c.amprentaSol;
		if (c.nrCamere > 0 && c.camereLaEtaj != NULL)
		{
			this->nrCamere = c.nrCamere;
			this->camereLaEtaj = new int[this->nrCamere];
			for (int i = 0; i < this->nrCamere; i++)
			{
				this->camereLaEtaj[i] = c.camereLaEtaj[i];
			}
		}
		else
		{
			this->nrCamere = 0;
			this->camereLaEtaj = NULL;
		}
	}
	Casa& operator=(const Casa& c)
	{
		if (this != &c)
		{
			if (this->camereLaEtaj != NULL)
			{
				delete[]this->camereLaEtaj;
			}
			this->cuEtaj = c.cuEtaj;
			this->amprentaSol = c.amprentaSol;
			if (c.nrCamere > 0 && c.camereLaEtaj != NULL)
			{
				this->nrCamere = c.nrCamere;
				this->camereLaEtaj = new int[this->nrCamere];
				for (int i = 0; i < this->nrCamere; i++)
				{
					this->camereLaEtaj[i] = c.camereLaEtaj[i];
				}
			}
			else
			{
				this->nrCamere = 0;
				this->camereLaEtaj = NULL;
			}
		}
		return *this;
	}
	~Casa()
	{
		if (this->camereLaEtaj != NULL)
		{
			delete[]this->camereLaEtaj;
		}
	}
	friend ostream& operator<<(ostream& out, const Casa& c)
	{
		out << "Este cu etaj? " << c.cuEtaj << endl;
		out << "Amprenta la sol: " << c.amprentaSol << endl;
		out << "Nr camere: " << c.nrCamere << endl;
		out << "Camere la etaj ";
		for (int i = 0; i < c.nrCamere; i++)
		{
			out << c.camereLaEtaj[i] << " ";
		}
		return out;
	}

	int operator()(int nr)
	{
		int contor = 0;
		for (int i = 0; i < this->nrCamere; i++)
		{
			if (this->camereLaEtaj[i] == nr) 
			{
				contor++ ;
			}
		}
		return contor;
	}
};

int main()
{
	Casa c1;
	cout << c1.getAmprentaSol() << endl;
	c1.setNrCamere(2);
	cout << c1.getNrCamere() << endl;
	int camereLaEtaj[] = { 1,0,0,1,1,1 };
	Casa c2(true, 2.3, 3, camereLaEtaj);
	Casa c4(false, 5.2, 4, camereLaEtaj);
	cout << c2.getNrCamere() << endl;
	cout << c2 << endl;
	cout << c2(0) << endl;
	Casa c3 = c2;
	cout << c3 << endl;
	c3 = c4;
	cout << c3 << endl;

}