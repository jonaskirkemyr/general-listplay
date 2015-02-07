#include "Node.h"

Node::Node(int id)
{
	this->id=id;
	next=nullptr;
}

Node::Node(const Node & cpy)
{
	id=cpy.id;
	next=new Node(id);
}

Node::~Node()
{
	delete next;
	next=nullptr;
}

void Node::setNext(Node *next)
{
	this->next=next;
}

Node *Node::getNext() const
{
	return this->next;
}

int Node::getId()
{
	return this->id;
}