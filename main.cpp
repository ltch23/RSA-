#include <iostream>
	#include <string>
	#include <stdlib.h>
	#include <time.h>
#include "Receptor.h"
#include "Emisor.h"
#include "Mcd.h"

using namespace std;

int main()
{
Receptor Bob;
Bob.receptor();
long long  opc;	
string mensaje;
cout<<"ingrese (1) para cifrar 		(2) para descifrar: ";
cin>>opc;

if(opc==1)
{
	//EMISOR
	long long  N, e;
	cout<<"ingrese N: ";
	cin>>N;
	cout<<"ingrese e: ";
	cin>>e;
	
	Emisor Alice(N,e);
	mensaje=Alice.leer();
	
	string Mcifrado=Alice.cifrado(mensaje);
	cout<<"mensaje cifrado es : "<<Mcifrado<<endl;
	
	Alice.guardar(Mcifrado); 
}

else if(opc==2)	
{
	//RECEPTOR
	//mensaje=Bob.leer();
	string Mdescifrado;
	Mdescifrado = Bob.descifrado(mensaje);
	cout<<"mensaje decifrado es: "<<Mdescifrado<<endl;
	Bob.guardar(Mdescifrado);
}
else
	cout<<"ERROR: ingresa un numero correcto ";
return 0;
}

