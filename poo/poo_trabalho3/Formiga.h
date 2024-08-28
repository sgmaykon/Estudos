#ifndef FORMIGA_H
#define FORMIGA_H
#include "Inseto.h"
class Formigueiro;
class Formiga : public Inseto{
    private:
        string especie;
        string cor;
        Formigueiro* formigueiro;
        int cff; //Cadastro de Formiga Fisica
    public:
        Formiga(string nome, double tamanho, int qtdePatas, string especie, string cor,int cff);
        ~Formiga();
        string getEspecie() const;
        void setEspecie(string especie);
        string getCor() const;
        void setCor(string cor);
        void imprime() const;
        virtual string getFuncao() const = 0;
        virtual int getTipo() const =0;
        void setFormigueiro(Formigueiro* formigueiro);
        Formigueiro* getFormigueiro() const;
        int getCff() const;
        void setCff(int cff);
        bool ComparaNome(Formiga* f);

};

#endif
