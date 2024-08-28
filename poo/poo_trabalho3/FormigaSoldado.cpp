#include "FormigaSoldado.h"

FormigaSoldado::FormigaSoldado(string nome, double tamanho, int qtdePatas, string especie, string cor, int cff,string funcao, string patente, int experiencia) : Formiga(nome, tamanho, qtdePatas, especie, cor,cff){
    this->funcao = funcao;
    this->patente = patente;
    this->experiencia = experiencia;
    tipo = 2;
}

FormigaSoldado::~FormigaSoldado(){
}

string FormigaSoldado::getFuncao() const{
    return funcao;
}

int FormigaSoldado::getTipo() const{
    return tipo;
}

void FormigaSoldado::setFuncao(string funcao){
    this->funcao = funcao;
}

string FormigaSoldado::getPatente() const{
    return patente;
}

void FormigaSoldado::setPatente(string patente){
    this->patente = patente;
}

int FormigaSoldado::getExperiencia() const{
    return experiencia;
}

void FormigaSoldado::setExperiencia(int experiencia){
    this->experiencia = experiencia;
}

void FormigaSoldado::imprime() const{
    Formiga::imprime();
    cout << "Funcao: " << funcao << endl;
    cout << "Patente: " << patente << endl;
    cout << "Experiencia: " << experiencia << endl;
}
