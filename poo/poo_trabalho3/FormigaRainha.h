#ifndef FORMIGARAINHA_H
#define FORMIGARAINHA_H
#include "Formiga.h"

class FormigaRainha : public Formiga{
    private:
        string funcao;
        int QtdOvos;
        int QtdOvosJaPostos;
        double requisito;
        int tipo;
        double constante;
    public:
        FormigaRainha(string nome, double tamanho, int qtdePatas, string especie, string cor, int cff, string funcao, int QtdOvos);
        ~FormigaRainha();
        string getFuncao() const;
        void setFuncao(string funcao);
        int getQtdOvos() const;
        void setQtdOvos(int QtdOvos);
        virtual void imprime() const;
        bool PostaOvo();
        int getQtdOvosJaPostos() const;
        double getRequisito() const;
        void setRequisito(double requisito);
        virtual int getTipo() const;
        void setQtdOvosJaPostos(int QtdOvosJaPostos);
};

#endif