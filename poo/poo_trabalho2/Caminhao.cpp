#include "Caminhao.h"

//Construtor
Caminhao::Caminhao(string placa, string marca, string cor, int ano, int eixos) : Veiculo(placa,marca,cor,ano) , eixos(eixos){
}

//Destrutor
Caminhao::~Caminhao() {
}

void Caminhao::setEixos(int eixos){
	this->eixos=eixos;
}
int Caminhao::getEixos() const{
	return eixos;
}

int Caminhao::getCategoria() const{
	return CAMINHAO;
}

void Caminhao::imprime() const {
	Veiculo::imprime();
	cout << "Eixos: " << getEixos() << endl;
}


