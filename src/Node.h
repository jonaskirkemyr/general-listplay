#ifndef NODE_H
#define NODE_H

class Node
{
	private:
		int id;
		Node * next;
	public:
		Node(int);
		Node(const Node&);

		virtual ~Node();

		int getId();
		Node *getNext() const;
		void setNext(Node *);
};


#endif