#ifndef CADASTRO_H
#define CADASTRO_H
#include "Formiga.h"
#include "Formigueiro.h"
#include "FormigaSoldado.h"
#include "FormigaOperaria.h"
#include "FormigaRainha.h"
#include "Inseto.h"

class Cadastro {
public:
    Cadastro(string fileName);
    virtual ~Cadastro();
    bool adiciona();
    void imprime(bool sorted = false);
    void imprime(int CFF);
    bool remove(int CFF);
    bool atualiza(int CFF);
    static char opcao();
private:
    void grava();
    void recupera();
    int indice(int CFF);

    string fileName;
    vector<Formiga*> Formigas;
};

#endif /* CADASTRO_H */