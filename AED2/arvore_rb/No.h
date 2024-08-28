#ifndef NO_H
#define NO_H
#include <iostream>
class No{
	private:
		int p;
                int key;
                char color;
                No* left;
                No* right;
	public:
                No(int p, int key, char color);
                ~No();
                void setP(int p); 
                void setKey(int key);
                void setColor(char color);
                void setLeft(No* left);
                void setRight(No* right);

                int getP() const;
                int getKey() const;
                char getColor() const;
                No* getLeft() const;
		No* getRight() const;
		
		bool isRight() const;
		bool isLeft() const;

};
#endif
