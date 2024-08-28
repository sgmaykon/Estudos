#include "Formiga.h"

Formiga::Formiga(string nome, double tamanho, int qtdePatas, string especie, string cor, int cff) : Inseto(nome, tamanho, qtdePatas){
    this->especie = especie;
    this->cor = cor;
    formigueiro = NULL;
    this->cff = cff;
}

Formiga::~Formiga(){
}

string Formiga::getEspecie() const{
    return especie;
}

void Formiga::setEspecie(string especie){
    this->especie = especie;
}

string Formiga::getCor() const{
    return cor;
}

void Formiga::setCor(string cor){
    this->cor = cor;
}

void Formiga::imprime() const{
    Inseto::imprime();
    cout << "Especie: " << especie << endl;
    cout << "Cor: " << cor << endl;
    cout << "CFF: " << cff << endl;
}

void Formiga::setFormigueiro(Formigueiro* formigueiro){
    this->formigueiro = formigueiro;
}

Formigueiro* Formiga::getFormigueiro() const{
    return formigueiro;
}

int Formiga::getCff() const{
    return cff;
}

void Formiga::setCff(int cff){
    this->cff = cff;
}

bool Formiga::ComparaNome(Formiga* f){
    return (this->getNome() < f->getNome());
}
