#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Pessoa.h"

namespace poo {
	class Professor : public Pessoa{
		private: 
			string universidade;
		public:
			Professor(string cpf, string nome, string universidade);
			~Professor();
			string getUniversidade() const;
			virtual void imprime() const;			
	
	};


}

#endif //PROFESSOR_H
