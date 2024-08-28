/*
Maykon dos Santos Gonçalves
RA: 821653
Cadastro de Formigas em um Formigueiro
O cadastro está funcionando, mas não consegui implementar a recuperacao do arquivo, infelizmente*/


#include "Cadastro.h"

int main(){
char op;
int cff;
Cadastro cadastro("ForAmigas.dat");

do {
    op = Cadastro::opcao();
    switch(op){
        case 'a':
            cadastro.adiciona();
            break;
        case 'r':
            cout << "Digite o CFF da formiga que deseja remover: ";
            cin >> cff;
            cadastro.remove(cff);
            break;
        case 'i':
            cadastro.imprime();
            break;
        case 'u': 
            cout << "Digite o CFF da formiga que deseja atualizar: ";
            cin >> cff;
            cadastro.atualiza(cff);
            break;
        case 's':
            cout <<"Saindo... Até logo!" << endl;
            break;
    }
}while (op != 's');
    return 0;
}



