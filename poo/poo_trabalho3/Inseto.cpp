#include "Inseto.h"

Inseto::Inseto(string nome, double tamanho, int qtdePatas){
    this->nome = nome;
    this->tamanho = tamanho;
    this->qtdePatas = qtdePatas;
}

Inseto::~Inseto(){
}

string Inseto::getNome() const{
    return nome;
}

void Inseto::setNome(string nome){
    this->nome = nome;
}

double Inseto::getTamanho() const{
    return tamanho;
}

void Inseto::setTamanho(double tamanho){
    this->tamanho = tamanho;
}

int Inseto::getQtdePatas() const{
    return qtdePatas;
}

void Inseto::setQtdePatas(int qtdePatas){
    this->qtdePatas = qtdePatas;
}

void Inseto::imprime() const{
    cout << "Nome: " << nome << endl;
    cout << "Tamanho: " << tamanho << endl;
    cout << "Quantidade de patas: " << qtdePatas << endl;
}
