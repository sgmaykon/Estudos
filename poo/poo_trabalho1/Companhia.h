#ifndef COMPANHIA_H
#define COMPANHIA_H
#include <iostream> 
using namespace std;
namespace poo{
	class Companhia{
		private:
		       string CNPJ;
	       	       string nome;
		public: 
			Companhia(string CNPJ, string nome);
	 		~Companhia();
			string getNome();
			string getCNPJ();
			void imprime();
};
}


#endif //COMPANHIA_H
