#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include <string>
#include "Constantes.h"
#include <vector>
#include <bits/stdc++.h>

using namespace std;
class Veiculo;
class Pessoa{
	private: 
		string nome;
		string CPF;
		vector<Veiculo*> frota;
		int carros;
		int caminhoes;
	public:
		Pessoa(string nome, string CPF);
		~Pessoa();
		void setNome(string);
		virtual string getNome() const;
		void setCPF(string);
		virtual string getCPF() const;
		bool adicionaVeiculo(Veiculo& veiculo);
		bool removeVeiculo(string placa);
		Veiculo* obtemVeiculo(string placa);
	        int qtdeVeiculos() const;
		int qtdeCarros() const;
		int qtdeCaminhoes() const;
		void imprime(int criterio) const; 	
};
#endif
