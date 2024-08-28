#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include <string>
#include <cmath> 

using namespace std;

namespace poo {
	class Pessoa{ 
		private:
			string nome;
			string cpf; 
		public:
			Pessoa(string cpf, string nome);
			virtual ~Pessoa();
			string getNome() const;
		        string getCPF() const;
			void imprime() const ;
			bool operator==(const Pessoa &outra) const; //Criacao de um operador para comparar 2 objetos pessoa
			bool operator!=(const Pessoa &outra) const; //Fiz isso para comparar dois objetos pessoa dentro da classe Voo
	};
}
#endif 
