#include<stdlib.h>
#include<iostream>
using namespace std;

class Armor{	
	private:
		string name;
		string model;
	public:
		Armor( string _name, string _model){
			name = _name;
			model= _model;
		}
		virtual void showV_name(){
			cout<<"Nombre: "<< name <<endl;
		}
		void show_model()
		{
			cout<<"Modelo: "<< model <<endl;
		}
};

class Control: public Armor{
	private:
		string IA;
		int version;
	public:
		Control(string _name, string _model, string _IA, int _version):Armor(_name, _model){
			IA= _IA;
			version=_version;
		}
		virtual void show_IA(){
			cout<<"Inteligencia artificial: "<< IA <<endl;	
		}
		void show_vers(){
			cout<<"Version: "<< version <<endl;
		}
};

class Storage : public Armor{
	private:
		int codigo;
		string name_alm;
	public:
		Storage(string _name, string _model, int _codigo, string _name_alm):Armor(_name, _model){
			codigo= _codigo;
			name_alm=_name_alm;
		}
		void show_cod(){
			cout<<"Codigo del almacen: "<< codigo <<endl;
		}
		void show_name_alm(){
			cout<<"Nombre del area: "<< name_alm <<endl;
		}
};

int main(){
	Armor	b	("MARK","1");
	Control	d1	("MARk","L","Friday",2);
	Storage	d2	("MARK","5",231,"Sotano");
	
	Armor 	*p;
	
	p = &b; 
	p->showV_name() ;
	p->show_model();
	
	cout<<endl;
	
	p = &d1; 
	p->showV_name();
	p->show_model();
	d1.show_IA();
	d1.show_vers();
	
	cout<<endl;
	
	p=&d2;
	p->showV_name();
	p->show_model();
	d2.show_name_alm();
	d2.show_cod();
	
	cout<<endl;
	
	cout<<"********************************** Elmer Fabian Uribe Arellano **********************************"<<endl;
	
	cout<<endl;
	
	system("pause");
	return 0;
	
}
