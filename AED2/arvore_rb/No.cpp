#include "No.h"


No::No(int p, int key, char color){
	this->p =p; this->key=key; this->color=color;
	this->left =NULL;
	this->right=NULL;
}

void No::setLeft(No* left){
	this->left=left;
}

void No::setRight(No* right){
	this->right=right;
}


No* No::getLeft() const{
	return left;
}

No * No::getRight() const{
	return right;
}

bool isRight() const{
}

bool isLeft() const{
}

