#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

class miclase 
{
	vector<int> vecto;
public:
	miclase(vector<int> v)
	{
		vecto = v;
	}
	void print()
	{
		for (int i = 0; i < vecto.size(); i++)
		{
			cout << vecto[i] << " ";		
			cout << endl;
		}
	}
};
int main()
{
	vector <int> vec;
	for (int i = 1; i <= 5; i++)
	{
		vec.push_back(i);
	}
	miclase o(vec);
	o.print();
	system("pause");
	return 0;
}
