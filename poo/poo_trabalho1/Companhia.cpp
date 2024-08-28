#include "Companhia.h"
namespace poo{
	Companhia::Companhia(string CNPJ, string nome){
       		this->CNPJ = CNPJ;
		this-> nome = nome;
	}
	Companhia::~Companhia(){
	}

	string Companhia::getNome(){
		return nome;
	}

	string Companhia::getCNPJ(){
		return CNPJ;
	}

	void Companhia::imprime(){
		cout << "CNPJ: " << nome << endl;
		cout << "NOME: " << CNPJ << endl;
	}

}
