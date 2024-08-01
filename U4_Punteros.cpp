//Declaración de punteros || &n = La direccion de la vaiable n||*n = El contenido de la variable.
#include<iostream>
#include<stdlib.h>

using namespace std;

int main (){
	
	int n=110, *drc_n;
	drc_n = &n;
	
	cout<<"N es: "<< *drc_n << endl;
	
	cout<<"La direccion de n es: "<<drc_n<<endl;
	
	system("pause");
	return 0;
}

