#include<iostream>
#include<string>

using namespace std;

class DosarAdmitere
{
	int nrOptiuni;
	string numeCandidat;
	float medieAdmitere;
	string* specializare;
public:
	DosarAdmitere()
	{
		this->medieAdmitere = 0;
		this->numeCandidat = "Necunoscut";
		this->nrOptiuni = 0;
		this->specializare = nullptr;
	}

	DosarAdmitere(string numeCandidat, float medieAdmitere, int nrOptiuni, string* specializare)
	{
		if (numeCandidat.size() >= 3)
		{
			this->numeCandidat = numeCandidat;
		}
		else
		{
			this->numeCandidat = "Necunoscut";
		}
		
			this->medieAdmitere = medieAdmitere;
		
		if (nrOptiuni > 0 && specializare!=NULL)
		{
			this->nrOptiuni = nrOptiuni;
			this->specializare = new string[this->nrOptiuni];
			for (int i = 0;i < this->nrOptiuni;i++)
			{
				this->specializare[i] = specializare[i];
			}
		}
		else
		{
			this->nrOptiuni = 0;
			this->specializare = NULL;
		}
	}

	DosarAdmitere(const DosarAdmitere& d)
	{

		this->numeCandidat = d.numeCandidat;
		this->medieAdmitere = d.medieAdmitere;
		this->nrOptiuni = d.nrOptiuni;
		this->specializare = new string[this->nrOptiuni];
		for (int i = 0;i < this->nrOptiuni;i++)
		{
			this->specializare[i] = d.specializare[i];
		}
	}

	DosarAdmitere& operator=(const DosarAdmitere& d)
	{
		if (this != &d)
		{
			if (this->specializare != NULL)
			{
				delete[]this->specializare;
			}
			this->numeCandidat = d.numeCandidat;
			this->medieAdmitere = d.medieAdmitere;
			this->nrOptiuni = d.nrOptiuni;
			this->specializare = new string[this->nrOptiuni];
			for (int i = 0;i < this->nrOptiuni;i++)
			{
				this->specializare[i] = d.specializare[i];
			}
		}
		return *this;
	}
		
	~DosarAdmitere()
	{
		if (this->specializare != NULL)
		{
			delete[]this->specializare;
		}
	}

	string getNumeCandidat()
	{
		return this->numeCandidat;
	}
	float getMedieAdmitere()
	{
		return this->medieAdmitere;
	}

	void setMedieAdmitere(float medie)
	{
		this->medieAdmitere = medie;
	}

	friend ostream& operator<<(ostream& out, const DosarAdmitere& d)
	{
		out << "Nume Candidat: " << d.numeCandidat << endl;
		out << "Medie admitere: " << d.medieAdmitere << endl;
		out << "Nr optiuni: " << d.nrOptiuni << endl;
		out << "Specializare: ";
		for (int i = 0;i < d.nrOptiuni;i++)
		{
			out << d.specializare[i] << endl;
		}
		return out;
	}
	explicit operator float()
	{
		return this->medieAdmitere;
	}

	/*DosarAdmitere& operator+=(int nr)
	{
		DosarAdmitere copie = *this;
		copie.nrOptiuni += nr;
		return copie;
	}*/
};

int main()
{
	DosarAdmitere d1;
	cout << d1.getNumeCandidat() << endl;
	d1.setMedieAdmitere(10);
	cout << d1.getMedieAdmitere() << endl;
	string specializari[] = { "marketing", "contabilitate", "informatica", "fizica", "chimie"};
	DosarAdmitere d2("Ionel", 7, 2, specializari);
	cout << d2.getNumeCandidat() << endl;
	DosarAdmitere d3 = d2;
	cout <<"D1 "<< d1 << endl << endl;
	cout<<"D2 " << d2 << endl << endl;
	cout <<"D3 " << d3 << endl << endl;
	DosarAdmitere d4("Vasile", 9, 3, specializari);
	cout << d4 << endl;
	cout << "--------------------" << endl;
	d3 = d4;
	
	/*d3 += 1;
	cout << d3 << endl;*/
	cout << d4 << endl;
	cout << (float)d3 << endl;
}