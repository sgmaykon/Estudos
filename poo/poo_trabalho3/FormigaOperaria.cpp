#include "FormigaOperaria.h"
#include <random>

FormigaOP::FormigaOP(string nome, double tamanho, int qtdePatas, string especie, string cor,int cff, string funcao, int QtdQueCarrega, double velocidade) : Formiga(nome, tamanho, qtdePatas, especie, cor,cff){
    this->funcao = funcao;
    this->QtdQueCarrega = QtdQueCarrega;
    this->velocidade = velocidade;
    qtdJaCarregada = 0;
    this->tipo =0;
}

FormigaOP::~FormigaOP(){
}

int FormigaOP::getTipo() const{
    return tipo;
}

string FormigaOP::getFuncao() const{
    return funcao;
}

void FormigaOP::setFuncao(string funcao){
    this->funcao = funcao;
}

int FormigaOP::getQtdQueCarrega() const{
    return QtdQueCarrega;
}

void FormigaOP::setQtdQueCarrega(int QtdQueCarrega){
    this->QtdQueCarrega = QtdQueCarrega;
}

double FormigaOP::getVelocidade() const{
    return velocidade;
}

void FormigaOP::setVelocidade(double velocidade){
    this->velocidade = velocidade;
}

void FormigaOP::imprime() const{
    Formiga::imprime();
    cout << "Funcao: " << funcao << endl;
    cout << "Quantidade que carrega (gramas): " << QtdQueCarrega << endl;
    cout << "Velocidade: " << velocidade << endl;
}

double FormigaOP::CarregaComida(){
    int minimo = QtdQueCarrega / 2;
    int maximo = 250;
    int valor =(rand() % (maximo - minimo + 1)) + minimo;
    double valor2 = valor*1.0;
    qtdJaCarregada += valor2;
    return valor2;
}

double FormigaOP::getQtdJaCarregada() const{
    return qtdJaCarregada;
}

void FormigaOP::setQtdJaCarregada(double qtdJaCarregada){
    this->qtdJaCarregada = qtdJaCarregada;
}


