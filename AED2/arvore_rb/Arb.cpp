#include "Arb.h"

ARB::ARB(No* root){
	altura=1;
}

ARB::~ARB(){}

void ARB::Insert(No z){
	x = ARB.root;
	y =NULL;
	while(x!=NULL){
		y=x;
		if (z.key < x.key)
			x=x.left;
		else
			x=x.right;
	}
	z.p =y;
	if y==NULL;
		ARB.root = z;
	elif (z.key<y.key)
		y.left=z;
	else
		y.right=z;
	z.color=0; //(vermelho)
	z.right = NULL;
	z.left = NULL;
	ARB.Equilibra();
}
void ARB::Delete(){}

No ARB::getRoot() const{
	return *root;
}

int ARB::getAltura() const{
	return altura;
}

void ARB::Equilibra() {


}
