#include "Aluno.h"

namespace poo{

	Aluno::Aluno(string cpf, string nome,int ra, int p1, int p2, int t1, int t2, int t3) : Pessoa( cpf, nome),
		ra(ra), p1(p1),p2(p2),t1(t1),t2(t2),t3(t3) {
	}


	Aluno::~Aluno() {
	}
//Metodo que obtem o RA
int Aluno::getRA() const{ 
	return ra;
}
//Metodo que obtem a media
double Aluno::Media() {
	double MP,MF,MT;
	MT = (( (t1) + (2*t2) +(3*t3)) / 6);
	MP = (p1+p2)/2;
	MF = ( (MP*8) + (MT*2) )/10;
	return MF;
}

//Metodo para verificar se o aluno foi aprovado
bool Aluno::aprovado() {
	if (Media() >= 6)
		return 1;
	else return 0;
}

//Metodo para verificar se o aluno pode fazer uma PAC
bool Aluno::pac(){
	if(Media() >5 && Aluno::Media() <6) 
	return 1;
	else return 0;
}
//Retorna a nota da PAC necessaria para passar
double Aluno::notaPAC(){
	if (pac() == 0)
		return 0;
	else return abs((Aluno::Media() - 12)); 
}

void Aluno::imprime(){ 
	Pessoa::imprime(); 
	cout << "RA: " << ra << endl;
	cout << "Media: " << Media() << endl;
}
};

