#include <iostream> 


class Node{	
	private:
		Node* Parent;
		int key;
		Node* U[1];
	public:
		Node(int key);
		~Node();
		void setParent(Node Parent);
		void setKey (int key);
		void setU(Node U[]);
		Node getParent() const;
		int getKey()const;
		Node getNo() const;

};
