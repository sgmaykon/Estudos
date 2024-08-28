#include "Node.h"

Node::Node(int key){
	this->key=key;
	this->Parent=NULL;
	for(int i=0;i<2;i++){
		this->U[i]=NULL;
	}
}

Node::~Node(){}

void Node::setParent(Node Parent){
	this->Parent=Parent;
}

void Node::setkey(int key);



