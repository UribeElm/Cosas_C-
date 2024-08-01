#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<cstdlib>
using namespace std;

enum error { NoRReal, DiscrCero };

void Raic(float X, float Y, float Z, float& R1, float& R2)

throw(error)
{
	float discr = Y * Y - 4 * X * Z ;
	if (discr < 0)
	{
		throw NoRReal;
	}
	else if (discr == 0)
	{
		throw DiscrCero;
	}
	R1 = (-Y - sqrt(discr)) / (2 * X);
	R2 = (-Y + sqrt(discr)) / (2 * X);
}

int main()
{
	float A = rand()%1000+1, B = rand()%1000+1, C = rand()%1000+1, R1, R2; //rand() invoca un método que arroja un número random
	try
	{
		Raic(A, B, B, R1, R2);
		cout << "Raices reales: " << R1 << " - " << R2 << endl;
	}
	catch (error e)
	{
		switch (e)
		{
		case NoRReal:
			cout << "Ninguna raiz real" << endl;
			break;
		case DiscrCero:
			cout << "Discriminante cero" << endl;
			break;

		}
	}
	system("pause");
	return 0;
}
