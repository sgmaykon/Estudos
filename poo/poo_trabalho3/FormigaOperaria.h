#ifndef FORMIGAOP_H
#define FORMIGAOP_H
#include "Formiga.h"

class FormigaOP : public Formiga{
    private:
        string funcao;
        int QtdQueCarrega;
        double velocidade;
        double qtdJaCarregada;
        int tipo;
    public:
        FormigaOP(string nome, double tamanho, int qtdePatas, string especie, string cor, int cff, string funcao, int QtdQueCarrega, double velocidade);
        ~FormigaOP();
        string getFuncao() const;
        void setFuncao(string funcao);
        int getQtdQueCarrega() const;
        void setQtdQueCarrega(int QtdQueCarrega);
        double getVelocidade() const;
        void setVelocidade(double velocidade);
        virtual void imprime() const;
        double CarregaComida(); 
        double getQtdJaCarregada() const;
        virtual int getTipo() const;
        void setQtdJaCarregada(double qtdJaCarregada);
        

};

#endif