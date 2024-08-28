#ifndef FORMIGASOLDADO_H
#define FORMIGASOLDADO_H
#include "Formiga.h"


class FormigaSoldado : public Formiga{
    private:
        string funcao;
        string patente;
        int experiencia;
        int tipo;
    public:
        FormigaSoldado(string nome, double tamanho, int qtdePatas, string especie, string cor,int cff, string funcao, string patente, int experiencia);
        ~FormigaSoldado();
        string getFuncao() const;
        void setFuncao(string funcao);
        string getPatente() const;
        void setPatente(string patente);
        int getExperiencia() const;
        void setExperiencia(int experiencia);
        void imprime() const;
        virtual int getTipo() const;
};

#endif