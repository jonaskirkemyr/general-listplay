#ifndef NODE_H
#define NODE_H

class Node
{
	private:
		int id;
		Node * next;
	public:
		Node(int);

		int getId();
		Node *getNext() const;
		void setNext(Node *);
};


#endif