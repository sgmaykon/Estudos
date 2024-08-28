//Algumas regras:
//pr-nil = Caminho top-down da raiz r ate um slot vazio
//1. TODo Noh eh VERMELHO OU PRETO
//2. A raiz r eh sempre PRETA
//3. Dois nos vermelhos nao podem ser adjacentes
//4. Para todo pr-nil tem o mesmo numero de nos pretos
#ifndef ARB_H
#define ARB_H
#include <iostream>
#include "No.h"
class ARB{
	private: 
		No* root;
		int altura;
	public:
		ARB(No* root);
		~ARB();
		void Insert(No z);
		void Delete();
		No getRoot() const;
		int getAltura() const;
		void Equilibra();
		void RotateLeft();
		void RotateRight();
		void checkP1();
		void checkP2();
		void checkP3();
		void checkP4();
};

#endif
