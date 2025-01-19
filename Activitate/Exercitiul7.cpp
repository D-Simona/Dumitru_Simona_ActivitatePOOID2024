////exemplu exercitiu
//#include<iostream>
//using namespace std;
//
//class C {
//public:
//	int x = 0;
//	C(int v = 0) : x(v) {}
//	C(const C& c) {
//		cout << "\nConstructorul de copiere";
//	}
//	C& operator= (const C& c)
//	{
//		cout<<"\nOperator de atribuire";
//		return *this;
//	}
//};
//C f(C c) {
//	return c;
//}
//
//int main() {
//	C c1, c2 = c1, c3; //aici se apeleaza de 3 ori constructorul
//	c3 = f(c1); //aici se apeleaza operatorul de atribuire
//	cin.get();
//}