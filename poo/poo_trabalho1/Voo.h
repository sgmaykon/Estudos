#ifndef VOO_H
#define VOO_H
#include "Pessoa.h"
#include "Companhia.h"
#include "DataHorario.h"
namespace poo{ 
	class Voo{
		private:
			Companhia companhia;
			string origem;
			string destino;
			DataHorario datah;
			Pessoa *lugar[25][6];  //Declaracao de uma matriz de Objetos da classe Pessoa
		public:
			Voo(Companhia&, string origem, string destino, DataHorario&);
			~Voo();
			string proximoLivre();
			bool Verifica(string);
			bool ocupa(string, Pessoa&);
			bool desocupa(string);
			int Vagas();
			void imprime();
			static  Pessoa vazio; //Pessoa vazio que e utilizada por todos os metodos de voo


	};
}
#endif //VOO_H
