#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

class person 
{
private:
	string name;
	int age;
public:
	person(string _name, int _age){ name = _name; age = _age; }
	virtual void mostrar() 
	{
		cout << "Nombre: " << name << "\n Edad: "<< age <<endl;
	}
};
class student :public person 
{
private:
	float fin_grd;
public:
	student(string _name, int _age, float _fin_grd) :person(_name, _age) {fin_grd = _fin_grd;}
	void mostrar()
	{
		person::mostrar();
		cout << "La calificacion final: " << fin_grd << endl;
	}
};

class employee :public person 
{
private:
	string puesto;
public:
	employee(string _name, int _age, string _puesto):person(_name, _age) {puesto = _puesto;}
	void mostrar()
	{
		person::mostrar();
		cout << "Puesto de trabajo: " << puesto << endl;
	}
};

int main() 
{
	person* vector[2];
	vector[0] = new student("Elmer", 21, 85);
	vector[1] = new employee("Evelyn", 18, "Directora general");
	vector[0] -> mostrar();
	cout <<endl;
	vector[1] -> mostrar();
	system("pause");
	return 0;
}
