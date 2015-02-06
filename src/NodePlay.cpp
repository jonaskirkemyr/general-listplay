#include "NodePlay.h"

//private
void NodePlay::createNodes(int numb)
{
	Node *current=head;
	for(int i=0;i<numb;++i)
	{
		current->setNext(new Node(current->getId()+1));
		current=current->getNext();
	}
}


//public
NodePlay::NodePlay(int numb)
{
	head=new Node(0);
	createNodes(numb);
}

bool NodePlay::isCircular()
{
	Node * current=head;

	while((current=current->getNext())!=nullptr)
		if(head==current)
			return true;
	return false;
}

void NodePlay::makeCircular()
{
	Node *current=head;
	while(current->getNext()!=nullptr)
		current=current->getNext();
	current->setNext(head);
}

void NodePlay::print()
{
	Node *current=head;
	std::cout<<"Nodes:\n";

	while(current!=nullptr)
	{
		std::cout<<"\tid: "<<current->getId()<<std::endl;
		current=current->getNext();
	}
}

void NodePlay::reverse()
{
	if(this->isCircular())
		return;//can't reverse a circular list
	Node *previous=nullptr;
	Node * current=head;
	Node *next=nullptr;

	while(current!=nullptr)
	{
		next=current->getNext();
		current->setNext(previous);
		previous=current;
		current=next;
	}
	head=previous;
}
