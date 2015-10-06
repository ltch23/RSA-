#ifndef Receptor_H
#define Receptor_H
	#include <string>
	#include <cmath>
	#include <fstream>
	#include <sstream>
#include "Mcd.h"

using namespace std;

class Receptor
{
	private:
		std::string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		long long  N;
		long long  e;
		long long  Ee_i;
	public:
		void receptor();
 		void generacionDeClaves();
		long long  generarNumero(long long  );
		
 		void guardar(string);
		string descifrado(string);
	
};
	void Receptor::receptor()
	{
		generacionDeClaves();
	};

	void Receptor::generacionDeClaves()
	{
	long long  p,q,d,ON,Ee;
  	p=generarNumero(p);
	q=generarNumero(q);
	e=generarNumero(Ee);


	N=p*q;
	
	ON=(p-1)*(q-1);
	Ee_i=Mcd ::mod(Mcd ::mcdExtendido(ON,e) , ON);
	
	cout<<"p:   "<<p<<"   q:   "<<q<<"   e:   "<<e<<endl;
	cout<<"Ee_i:   "<<Ee_i<<"   N:   "<<N<<"   ON:   "<<ON<<endl;
	cout<<"*******************************************************"<<endl;
	cout<<endl;
	
	};
	
	long long  Receptor::generarNumero(long long num)
	{
		bool cont=false;
		srand(time(NULL));
		num=rand()%200+10;
	
		for(long long  i=2 ; i<(num^(1/2));i++)
			if(Mcd ::mod(num,i)==0)
			{cont=true;break;}
		if(cont==true)
		{	
			while(cont==true)
			{
				cont=0;
				srand(time(NULL));
				num=rand()%200+10;
				for(long long  i=2;i<(num^(1/2));i++)
					if(Mcd ::mod(num,i)==0)
						{cont=true;	break;}
			}
		} 
		return num;
		
	};
	
	string Receptor::descifrado(string mensaje)
	{
		string str;
		std::ifstream ifsInt("cifrado.txt");
		long long  numero;
		while(ifsInt >> numero) 
		{
			long long  tmp=0;
			tmp=Mcd::exponenciacionModular(numero,Ee_i,N);
			str+= alfabeto[tmp];
		}
		return str;	 
	};


		/* string Receptor::leer()
        {
        std::ifstream text("mensaje.txt");
		std::string word;
		while(text >> word)
		std::cout << word << std::endl;
		text.close();
		
		}
		 */
	void Receptor::guardar(string palabra)
		{
		std::ofstream ofs("descifrado.txt");
		ofs<<palabra;
		ofs.close();
		}
	

#endif // RECEPTOR_H
