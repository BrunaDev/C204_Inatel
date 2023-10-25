#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int pot(int a, int n){

	int x;
	
	if(n == 0)
	{
		x = 1;
	}	
	if(n > 0)
	{
		x = a*pow(a,n-1);	
	}
	return x;	
}

int main()
{
	int a, n;
	
	cout<<"Entre com o valor de a: " << endl;
	cin>>a;
	
	cout<<"Entre com o valor de n: " << endl;
	cin>>n;
	
	cout<< "A resposta e: "<< pot (a,n) << endl;
	
	return 0;
}