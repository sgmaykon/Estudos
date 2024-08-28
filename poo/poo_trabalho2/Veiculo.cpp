#include "Veiculo.h"

Veiculo::Veiculo(string placa, string marca, string cor, int ano){
	this->placa=placa;
	this->marca = marca;
	this-> cor = cor;
	this-> ano=ano;
	this->dono=NULL;
}
Veiculo::~Veiculo(){
}

void Veiculo::setPlaca(string placa){
	this->placa=placa;
}
void Veiculo::setMarca(string marca){
	this->marca=marca;
}
void Veiculo::setCor(string cor){
	this->cor=cor;
}
void Veiculo::setAno(int ano){
	this->ano=ano;
}
void Veiculo::setDono(Pessoa* p1){
	this->dono=p1;
}
string Veiculo::getPlaca() const{
	return placa;
}
string Veiculo::getMarca() const{
	return marca;
}
string Veiculo::getCor() const{
	return cor;
}
int Veiculo::getAno() const{
	return ano;
}

bool Veiculo::comparaPlaca(Veiculo* v1, Veiculo* v2){
	return v1->getPlaca() < v2->getPlaca();
}

bool Veiculo::comparaAno(Veiculo* v1, Veiculo* v2){
	if (v1->getAno() == v2->getAno())
		return comparaPlaca(v1,v2);
	else
		return v1->getAno() < v2->getAno();
}
bool Veiculo::comparaCategoria(Veiculo* v1, Veiculo* v2){
	if (v1->getCategoria() == v2->getCategoria())
		return comparaPlaca(v1,v2);
	else
		return v1->getCategoria() < v2->getCategoria();
}

void Veiculo::imprime() const {
	cout << "Placa: " << getPlaca() << endl;
	cout << "Marca: " << getMarca() << endl;
	cout << "Cor: " << getCor() << endl;
	cout << "Ano: " << getAno() << endl;
	cout << "Categoria: " << getCategoria() << endl;
}


	
