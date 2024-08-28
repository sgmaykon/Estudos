#ifndef ALUNO_H
#define ALUNO_H
#include "Pessoa.h"
namespace poo{
	//Criacao da classe aluno com heranca, com chamada dos metodos de Pessoa como publicos
	class Aluno: public Pessoa{
		private:
			int ra;
			int p1,p2;
			int t1,t2,t3;
		
		public:
			Aluno(string cpf, string nome,int ra,int p1, int p2, int t1, int t2, int t3);
			~Aluno();
			int getRA() const;
			double Media();
			bool aprovado();
			bool pac();
			double notaPAC();
			void imprime();

	};
}

#endif //ALUNO_H
