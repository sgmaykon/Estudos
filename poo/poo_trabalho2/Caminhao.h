#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "Veiculo.h"

class Caminhao : public Veiculo{
	private: 
		int eixos;
	public:
		Caminhao(string placa, string marca, string cor, int ano, int eixos);
		~Caminhao();
		void setEixos(int);
		int getEixos() const;
		virtual int getCategoria() const;
		virtual void imprime() const;
};

#endif

