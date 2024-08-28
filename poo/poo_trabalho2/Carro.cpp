#include "Carro.h"

//Construtor
Carro::Carro(string placa, string marca, string cor, int ano, double volume) : Veiculo(placa, marca, cor , ano), volume(volume) {
}

//Destrutor
Carro::~Carro(){
}

void Carro::setVolume(double volume){
	this->volume=volume;
}

double Carro::getVolume() const{
	return volume;
}

int Carro::getCategoria() const{
	return CARRO;
}
void Carro::imprime() const {
	Veiculo::imprime();
	cout << "Volume: " << getVolume() << endl;
}

