#include "Professor.h"

namespace poo{
	Professor::Professor(string cpf, string nome, string universidade) : Pessoa (cpf, nome), universidade(universidade){
			}
	Professor::~Professor(){
	}

	string Professor::getUniversidade() const {
	return universidade;
	}

	void Professor::imprime() const {
	Pessoa::imprime();
	cout << "Universidade : " << universidade << endl;
	}
}	


