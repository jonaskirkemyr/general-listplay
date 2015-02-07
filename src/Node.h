#ifndef NODE_H
#define NODE_H

class Node
{
	private:
		int id;
		Node * next;
	public:
		Node(int);
		virtual ~Node();

		int getId();
		Node *getNext() const;
		void setNext(Node *);
};


#endif