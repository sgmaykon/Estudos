#ifndef FORMIGUEIRO_H
#define FORMIGUEIRO_H

#include "Inseto.h"
#include "Formiga.h"
#include "FormigaOperaria.h"
#include "FormigaRainha.h"
#include "FormigaSoldado.h"


class Formigueiro{
    private:
        string nome;
        double comida;
        int qtdFormigas;
        int qtdeOvos;
        int qtdeOP;
        int qtdeSoldados;
        Formiga* rainha;
        vector <Formiga*> FourMigas;  //4migas hehe :D
    public:
        Formigueiro(string nome,double comida,Formiga* rainha);
        Formigueiro();
        ~Formigueiro();
        double getComida() const;
        void setComida(double comida);
        int getQtdFormigas() const;
        void setQtdFormigas(int qtdFormigas);
        int getQtdeOvos() const;
        void setQtdeOvos(int qtdeOvos);
        int getQtdeOP() const;
        void setQtdeOP(int qtdeOP);
        int getQtdeSoldados() const;
        void setQtdeSoldados(int qtdeSoldados);
        Formiga* getRainha() const;
        void setRainha(Formiga* rainha);
        void adicionaFormiga(Formiga* formiga);
        void removeFormiga(string nome);
        Formiga* getFormiga(string nome);
        void imprime() const;
        void imprimeFormigas() const;
        void imprimeFormigas(int tipo) const;
        string getNome() const;
        void setNome(string nome);
        

};


#endif