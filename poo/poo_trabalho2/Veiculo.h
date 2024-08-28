#ifndef VEICULO_H
#define VEICULO_H
#include "Pessoa.h"
class Veiculo{
	private:
		string placa;
		string marca;
		string cor;
		int ano;
		Pessoa* dono;
	public:
		Veiculo(string placa, string marca, string cor, int ano);
		~Veiculo();
		void setPlaca(string placa);
		void setMarca(string marca);
		void setCor(string cor);
		void setAno(int ano);
		void setDono(Pessoa* p1);
		virtual string getPlaca() const;
		virtual string getMarca() const;
		virtual string getCor() const;
		virtual int getAno() const;

		virtual int getCategoria() const = 0;
		bool static comparaPlaca(Veiculo* v1, Veiculo* v2);
	      	bool static comparaAno(Veiculo* v1, Veiculo* v2);
		bool static comparaCategoria(Veiculo* v1,Veiculo* v2);	
		virtual void imprime() const;
		
};

#endif
