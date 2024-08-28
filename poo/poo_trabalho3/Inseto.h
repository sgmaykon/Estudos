#ifndef INSETO_H
#define INSETO_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>
using namespace std;

class Inseto{
    private:
        string nome;
        double tamanho;
        int qtdePatas; 

    public:
        Inseto(string nome, double tamanho, int qtdePatas);
        ~Inseto();
        string getNome() const;
        void setNome(string nome);
        double getTamanho() const;
        void setTamanho(double tamanho);
        int getQtdePatas() const;
        void setQtdePatas(int qtdePatas);
        virtual void imprime() const;
        virtual string getEspecie() const=0;

};

#endif