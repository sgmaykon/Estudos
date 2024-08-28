#include "FormigaRainha.h" 
#include "Formigueiro.h"

FormigaRainha::FormigaRainha(string nome, double tamanho, int qtdePatas, string especie, string cor, int cff, string funcao, int QtdOvos) : Formiga(nome, tamanho, qtdePatas, especie, cor,cff){
    this->funcao = funcao;
    this->QtdOvos = QtdOvos;
    this->QtdOvosJaPostos = 0;
    requisito = 0.5;
    this->tipo = 1;
    constante = 3.141592653589793/3; 
}

FormigaRainha::~FormigaRainha(){
}

string FormigaRainha::getFuncao() const{
    return funcao;
}

int FormigaRainha::getTipo() const{
    return tipo;
}

void FormigaRainha::setFuncao(string funcao){
    this->funcao = funcao;
}

int FormigaRainha::getQtdOvos() const{
    return QtdOvos;
}

void FormigaRainha::setQtdOvos(int QtdOvos){
    this->QtdOvos = QtdOvos;
}

void FormigaRainha::imprime() const{
    Formiga::imprime();
    cout << "Funcao: " << funcao << endl;
    cout << "Quantidade de ovos que pode colocar: " << QtdOvos << endl;
    cout << "Quantidade de ovos ja postos: " << QtdOvosJaPostos << endl;
}


bool FormigaRainha::PostaOvo(){
    if (getFormigueiro()->getComida() < requisito) {
        return false;
    }
    else{
        QtdOvosJaPostos++;
        getFormigueiro()->setComida(getFormigueiro()->getComida() - requisito);
        requisito = constante * requisito;
        return true;
    }
}

int FormigaRainha::getQtdOvosJaPostos() const{
    return QtdOvosJaPostos;
}

double FormigaRainha::getRequisito() const{
    return requisito;
}

void FormigaRainha::setRequisito(double requisito){
    this->requisito = requisito;
}

void FormigaRainha::setQtdOvosJaPostos(int QtdOvosJaPostos){
    this->QtdOvosJaPostos = QtdOvosJaPostos;
}

