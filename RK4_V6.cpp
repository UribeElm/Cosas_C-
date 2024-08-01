#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

class RungeKutta4 {
private:
	float x, y,h;
public:
	RungeKutta4(float _x, float _y, float _h){x = _x,y = _y,h = _h;}
	virtual void show_vals()
	{
		cout << "\tValores: " << endl;
		cout << "\t\tx= " << x << endl;
		cout << "\t\ty= " << y << endl;
		cout << "\t\th= " << h << endl;
	}
	void show_students()
	{
		cout << "Practica realizada por: " << endl;
		cout << " \tFraustro Saavedra Bryan del Angel \tAS18110141 \n \tHernandez Zuniga Alexis Osvaldo \tAS15112296 \n \tLopez Perez Juan Angel Alexis \tAS18110550 \n \tUribe Arellano Elmer Fabian \tAS18111232" << endl;
		cout << endl;
	}
	float get_x(){return x;}
	float get_y() {return y; }
	float get_h(){return h;}
	float func();
	float params();
};

class datos: public RungeKutta4 
{
private:
	string f;
public:
	datos(string _f, float _x, float _y, float _h):RungeKutta4(_x, _y, _h) { f = _f; }
	void show() { RungeKutta4::show_vals(); cout << "F: " << f << endl; }
};

float RungeKutta4::func()
{
	float _funcion = (-20 *y)+(7 * exp(-0.5 * (x)));
	return _funcion;
}

float RungeKutta4::params()
{
	float k = func();
	return k;
}

int main()
{
	float incX = 0.0, incY = 5.0, paso = 0.01, Ki[3]{}, Xi[3]{}, Yi[3]{};
	
	RungeKutta4 o(incX,incY,paso);
	RungeKutta4* p;
	p = &o;
	o.show_students();
	p->show_vals();

	Xi[0] = incX;
	Yi[0] = incY;

	cout<<endl;

	for (int i = 0; i <= 3; i++) 
	{
		incX = Xi[i];
		incY = Yi[i];

		for (int j = 0; j <= 3; j++) 
		{
			if (j == 1 || j == 2) 
			{
				incX = Xi[i] + paso / 2.0;
				incY = Yi[i] + (paso / 2.0) * Ki[j - 1];
			}
			else if (j == 3) 
			{
				incX = Xi[i] + paso;
				incY = Yi[i] + paso * Ki[j - 1];
			}

			RungeKutta4 a(incX, incY, paso);
			Ki[j] = a.params();
			cout << "\tK[" << j+1 << "]= " << Ki[j] << endl;
		}
		Xi[i+1] = Xi[i] + paso;
		Yi[i+1] = Yi[i]+(paso / 6.0)*(Ki[0] + 2 * Ki[1] + 2 * Ki[2] + Ki[3]);
		cout << "\t\t\tX[" << i << "]= " << Xi[i+1] << "\t\t\tY[" << i << "]= " << Yi[i+1] << endl;
	}
	system("pause");
	return 0;
}
