#include "Voo.h"
namespace poo{

//------------Funcoes de conversao----------------//

//int para string 
string itos(int linha, int coluna){
	string poltrona = to_string(linha + 1); 
	poltrona.append(1, ((char) ('A' + coluna))); 
	poltrona.insert(0, 3 - poltrona.size(), '0');
return poltrona;
}

//string para int. O nome está assim para nao ocorrer conflito com o namespace std
int stoii(string poltrona) {
	int linha = stoi(poltrona.substr(0,2)) - 1;
	int coluna = poltrona[2] - 'A';
	return ((linha*100) + (coluna*10)); //Fiz essa implementacao para separar as linhas e colunas
					    //Para tal, observe que a linha e a coluna fica em casas decimais diferentes
					    //Esta dessa forma porque e mais facil para separa-las depois
}

 

Pessoa Voo::vazio("vazio","vazio");  //Declaracao de pessoa vazio que pode ser usada por todos os metodos de Voo
Voo::Voo(Companhia& companhia, string origem, string destino, DataHorario& datah): companhia(companhia),
		origem(origem),destino(destino),datah(datah){
			for (int linhas=0; linhas<25; linhas++) {
				for( int colunas = 0 ;colunas<6 ; colunas++) {
					lugar[linhas][colunas] = new Pessoa("vazio","vazio"); //Alocacao dinamica de objetos pessoa para os enderecos da matriz
				}
			}
		}

Voo::~Voo() {
	for (int linhas = 0; linhas < 25; linhas++) {
          for (int colunas = 0; colunas < 6; colunas++) {
                delete lugar[linhas][colunas];  //Destrutor que desaloca o que foi alocado dinamicamente
            }
        }

 }


string Voo::proximoLivre(){ 
	for (int linhas=0; linhas<25; linhas++) { //laco pra percorrer matriz
		for( int colunas = 0 ;colunas<6 ; colunas++) {
			if ((*lugar[linhas][colunas] == vazio) ){ 		
				string poltrona = itos(linhas,colunas);	 //Converte de inteiro para string, e salva em poltrona
				return poltrona;	
			}
	}
	}
	return "cheio"; //Retorna cheio caso nenhuma poltrona esteja vazia
}

bool Voo::Verifica(string a) { 
	int indice = stoii(a); //Converte de string para inteiro, e salva o valor na variavel indice
	int linhas = indice/100; // Para obter as linhas, divide-se por 100
	int colunas = (indice%100)/10; //Para obter as colunas, faz-se o indice modulo 100 e divide por 10
	if(*lugar[linhas][colunas] != vazio){ //Se � diferente de vazio, Sim, est� ocupado
		 return 1; //Retorna verdadeiro
	} 
	else {
	       return 0; //Nao esta ocupado, retorna falso
	} 
}

bool Voo::ocupa(string a, Pessoa &p){
	if (Verifica(a))  //verifica se esta ocupado. Se Verifica retorna 1, entao esta ocupado
		return 0;  //Retorna false, pois nao e possivel ocupar, uma vez que ja esta ocupado
	else{ 
		int indice = stoii(a); //Converte de string para inteiro, e salva o valor na variavel indice
		int linhas = indice/100; //Separa a linha
		int colunas = (indice%100)/10; //Separa a coluna
		*lugar[linhas][colunas]=p;  //Aloca a pessoa na poltrona de posicao desejada
		return 1; //Retorna true, pois a operacao foi bem sucedida
	}
}

bool Voo::desocupa(string a){
	if (Verifica(a)){   //Só pode desocupar se esta ocupado
		int indice = stoii(a);
		int linhas = indice/100;
		int colunas = (indice%100)/10;
		*lugar[linhas][colunas] = vazio;  //Aloca o objeto Pessoa vazio para o indice da matriz
		return 1;  //Bem sucedido
	}
	else
		return 0; //Só pode desocupar se esta ocupado
}
		
int Voo::Vagas(){		
	int counter =0; //Contador para as vagas
	for (int linhas=0; linhas<25; linhas++) { //laco pra percorrer matriz
		for( int colunas = 0 ;colunas<6 ; colunas++) {
			if (*lugar[linhas][colunas] == vazio){ 	 //Se esta vazio, tem vaga, e soma o contador
				counter++;
			}
		}
	}	

return counter;  //Retorna numero de vagas
}

void Voo::imprime(){
	string poltrona;
	cout << "============================= Detalhes do seu Voo! =====================================" << endl;
        cout <<"Origem: " << origem << endl;
	cout <<"Destino: " << destino << endl;
	companhia.imprime(); 
	datah.imprime(true);
	for (int linhas=0; linhas<25; linhas++) { //laco pra percorrer matriz
		for( int colunas = 0 ;colunas<6 ; colunas++) {
			if(*lugar[linhas][colunas] !=vazio) {
			       	poltrona = itos (linhas, colunas);  //Inteiro pra string, para exibir qual éa poltrona
				lugar[linhas][colunas]->imprime();
				cout << "Poltrona: " << poltrona << endl << endl;
			}
			else{
			       	poltrona = itos (linhas, colunas);  //Inteiro pra string, para exibir qual éa poltrona
				cout << "Vazio!" << endl; //Nao tem ninguem na vaga
				cout << "Poltrona: " << poltrona << endl << endl;
			}
		}
	}
	cout << "=========================== Obrigado por voar com a gente! ================================" << endl;
}
}
