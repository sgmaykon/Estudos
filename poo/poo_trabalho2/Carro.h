#ifndef CARRO_H
#define CARRO_H
#include "Veiculo.h"

class Carro : public Veiculo{ 
	private:
		double volume;
	public:
		Carro(string placa, string marca, string cor, int ano, double volume);
		~Carro();
		void setVolume(double);
		double getVolume() const;
		virtual int getCategoria() const; //1
		virtual void imprime() const;
};

#endif
