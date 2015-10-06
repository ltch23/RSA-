#ifndef Emisor_H
#define Emisor_H
	#include <string>
	#include <cmath>
	#include <fstream>
	#include <sstream>
#include "Mcd.h"

using namespace std;

class Emisor
{
	private:
		string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		long long  N;
		long long  e;
	public:
		string leer();
		Emisor(long long , long long  );
		long long  exponenciacionModular(long long  , long long  , long long );
		void guardar(string);

		string cifrado(string);

};
	 
	Emisor::Emisor(long long  NN, long long  ee)
	{
		N = NN;
		e = ee;
	};
	
	string Emisor::cifrado(string mensaje)
	
	{	
		string str;
		for(long long  i=0;i<mensaje.size();i++)
		{
			long long  tmp=0;
			long long  aux = alfabeto.find(mensaje[i]);
			tmp=Mcd::exponenciacionModular(aux,e,N);
			str+= static_cast<std::ostringstream*>(&(std::ostringstream() << tmp))->str()+" ";
		}
		return str;	 
	};
	
		string Emisor::leer()
        {
        std::ifstream ifsInt ("texto.txt");
        std::string str;
        std::getline(ifsInt,str);
		return  str ;
        ifsInt .close();
		}
		
		void Emisor::guardar(string palabra)
		{
		std::ofstream ofs("cifrado.txt");
		ofs<<palabra;
		ofs.close();
		}

		
#endif // Emisor_H
	
