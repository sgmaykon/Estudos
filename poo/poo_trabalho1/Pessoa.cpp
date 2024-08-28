#include "Pessoa.h"
namespace poo {
	Pessoa::Pessoa(string cpf, string nome){
		this->nome = nome;
		this->cpf = cpf;
	}
	Pessoa::~Pessoa(){
	}
	string Pessoa::getNome() const{
		return nome;
	}

	string Pessoa::getCPF() const {
		return cpf;
	}

	void Pessoa::imprime() const{
		cout << "Nome: " << nome << endl;
		cout << "CPF: " << cpf << endl;

	}

	//ImplementaÃao do operador "==" que compara dois objetos da classe pessoa
	bool Pessoa::operator==(const Pessoa& outra) const {
	        return ( (this->cpf == outra.cpf) && (this->nome == outra.nome) );  //Verifca se os atributos sao iguais
	}
	//Implementacao do operador "!=" que compara dois objetos da classe pessoa
	bool Pessoa::operator!=(const Pessoa& outra) const {
	return ( (this->cpf != outra.cpf) || (this->nome != outra.nome) );	 //Verifica se os atributos sao diferentes	
}
}
