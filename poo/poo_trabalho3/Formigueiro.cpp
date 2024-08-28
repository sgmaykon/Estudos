#include "Formigueiro.h"

Formigueiro::Formigueiro(){
    nome = "";
    comida = 0;
    rainha = NULL;
    qtdFormigas = 0;
    qtdeOvos = 0;
    qtdeOP = 0;
    qtdeSoldados = 0;
}

Formigueiro::Formigueiro(string nome,double comida,Formiga* rainha){
    this->nome = nome;
    this->comida = comida;
    this->rainha = rainha;
    qtdFormigas = 0;
    qtdeOvos = 0;
    qtdeOP = 0;
    qtdeSoldados = 0;
}

Formigueiro::~Formigueiro(){
}

double Formigueiro::getComida() const{
    return comida;
}

void Formigueiro::setComida(double comida){
    this->comida = comida;
}

int Formigueiro::getQtdFormigas() const{
    return qtdFormigas;
}

void Formigueiro::setQtdFormigas(int qtdFormigas){
    this->qtdFormigas = qtdFormigas;
}

int Formigueiro::getQtdeOvos() const{
    return qtdeOvos;
}

void Formigueiro::setQtdeOvos(int qtdeOvos){
    this->qtdeOvos = qtdeOvos;
}

int Formigueiro::getQtdeOP() const{
    return qtdeOP;
}

void Formigueiro::setQtdeOP(int qtdeOP){
    this->qtdeOP = qtdeOP;
}

int Formigueiro::getQtdeSoldados() const{
    return qtdeSoldados;
}

void Formigueiro::setQtdeSoldados(int qtdeSoldados){
    this->qtdeSoldados = qtdeSoldados;
}

Formiga* Formigueiro::getRainha() const{
    return rainha;
}

void Formigueiro::setRainha(Formiga* rainha){
    this->rainha = rainha;
}

void Formigueiro::adicionaFormiga(Formiga* formiga){
    FourMigas.push_back(formiga);
    qtdFormigas++;
    if (formiga->getFuncao() == "Operaria"){
        qtdeOP++;
    }
    else if (formiga->getFuncao() == "Soldado"){
        qtdeSoldados++;
    }
    else if (formiga->getFuncao() == "Rainha"){
        qtdeOvos++;
    }
}

void Formigueiro::removeFormiga(string nome){
    for (int i = 0; i < qtdFormigas; i++){
        if (FourMigas[i]->getNome() == nome){
            if (FourMigas[i]->getFuncao() == "Operaria"){
                qtdeOP--;
            }
            else if (FourMigas[i]->getFuncao() == "Soldado"){
                qtdeSoldados--;
            }
            else if (FourMigas[i]->getFuncao() == "Rainha"){
                qtdeOvos--;
            }
            FourMigas.erase(FourMigas.begin() + i);
            qtdFormigas--;
            break;
        }
    }
}

Formiga* Formigueiro::getFormiga(string nome){
    for (int i = 0; i < qtdFormigas; i++){
        if (FourMigas[i]->getNome() == nome){
            return FourMigas[i];
        }
    }
    return NULL;
}

void Formigueiro::imprime() const{
    FormigaRainha * fr;
    fr = dynamic_cast<FormigaRainha*>(rainha);
    cout << "Comida: " << comida << endl;
    cout << "Quantidade de formigas: " << qtdFormigas << endl;
    cout << "Quantidade de ovos: " << qtdeOvos << endl;
    cout << "Quantidade de ovos ja postos: " << fr->getQtdOvosJaPostos() << endl;
    cout << "Quantidade de operarias: " << qtdeOP << endl;
    cout << "Quantidade de soldados: " << qtdeSoldados << endl;
    rainha->imprime();
    for (int i = 0; i < qtdFormigas; i++){
        FourMigas[i]->imprime();
    }
}

void Formigueiro::imprimeFormigas() const{
    for (int i = 0; i < qtdFormigas; i++){
        FourMigas[i]->imprime();
    }
}

void Formigueiro::imprimeFormigas(int tipo) const{
    for (int i = 0; i < qtdFormigas; i++){
        if (FourMigas[i]->getFuncao() == "Operaria" && tipo == 1){
            FourMigas[i]->imprime();
        }
        else if (FourMigas[i]->getFuncao() == "Soldado" && tipo == 2){
            FourMigas[i]->imprime();
        }
        else if (FourMigas[i]->getFuncao() == "Rainha" && tipo == 3){
            FourMigas[i]->imprime();
        }
    }
}

string Formigueiro::getNome() const{
    return nome;
}

void Formigueiro::setNome(string nome){
    this->nome = nome;
}

