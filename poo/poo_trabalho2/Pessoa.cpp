#include "Pessoa.h"
#include "Veiculo.h"

//Construtor
Pessoa::Pessoa(string nome, string CPF){
	this->nome=nome;
	this->CPF=CPF;
	carros =0;
	caminhoes =0;
}

//Destrutor
Pessoa::~Pessoa(){
}

void Pessoa::setNome(string){
	this->nome = nome;
}

string Pessoa::getNome() const{
       return nome;
}

void Pessoa::setCPF(string){
	this->CPF=CPF;
}
string Pessoa::getCPF() const{
	return CPF;
}

bool Pessoa::adicionaVeiculo(Veiculo& veiculo){ 
	int retorno = 1;
	for(int i = 0; i<qtdeVeiculos();i++){
		if (frota[i]->getPlaca() == veiculo.getPlaca())
			retorno =0;
	}
	this->frota.push_back(&veiculo); //Adiciona o veiculo no vector e aumenta o seu tamanho
	veiculo.setDono(this);
	if(veiculo.getCategoria() == CARRO) 
		carros++;
	else  //Só pode ser carro ou caminhao
		caminhoes++;
	return retorno;
}

bool Pessoa::removeVeiculo(string placa){
	int retorno=0;
	for (int i =0; i<qtdeVeiculos();i++){
		if (frota[i]->getPlaca() == placa){ //Achou a placa
			if (frota[i]->getCategoria() == CARRO)
				this->carros--;
			else //Só pode ser carro ou caminhao
				this->caminhoes--;
			frota[i]->setDono(NULL); //Deixa o veiculo sem dono
			frota.erase(frota.begin()+i); //Remove o veiculo do vector
			retorno =1;
		}
	}
	return retorno;	//Nao achou a placa
}
Veiculo* Pessoa::obtemVeiculo(string placa){
	Veiculo* aux = NULL;
	for(int i =0;i<qtdeVeiculos();i++){
		if (frota[i]->getPlaca() == placa)
		 	aux = frota[i];
	}
	return aux;
}

int Pessoa::qtdeCarros() const {
	return carros;
}
int Pessoa::qtdeVeiculos() const{
	return carros+caminhoes;
}
int Pessoa::qtdeCaminhoes() const{
	return caminhoes;
}

void Pessoa::imprime(int criterio) const{
	vector<Veiculo*> aux = frota;
	cout << "Nome: " << getNome() << endl;
	cout << "CPF: " << getCPF() << endl;
	cout << endl;
	switch(criterio) { 
		case NOSORTED:
			for(int i=0; i<qtdeVeiculos(); i++){
				frota[i]->imprime();
				cout << endl;
			}
			break;	
		case PLACA:
		 	sort(aux.begin(), aux.end(), Veiculo::comparaPlaca);
			for(int i=0; i<qtdeVeiculos();i++){
				aux[i]->imprime();
				cout<<endl;
			}
			break;
		case ANO:
		 	sort(aux.begin(), aux.end(), Veiculo::comparaAno);
			for(int i=0; i<qtdeVeiculos();i++){
				aux[i]->imprime();
				cout<<endl;
			}
			break;

		case CATEGORIA:
		 	sort(aux.begin(), aux.end(), Veiculo::comparaCategoria);
			for(int i=0; i<qtdeVeiculos();i++){
				aux[i]->imprime();
				cout<<endl;
			}
			break;

	}
}
