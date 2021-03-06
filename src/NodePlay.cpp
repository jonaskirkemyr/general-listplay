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
NodePlay::NodePlay(int numb,bool create)
{
	head=new Node(0);
	if(create)
		createNodes(numb);
}

NodePlay::NodePlay(const NodePlay & cpy)
{
	if(cpy.head==nullptr)
		return;

	Node *current=cpy.head;
	head=new Node(current->getId());
	Node *temp=head;

	while(current!=nullptr) 
	{
		temp->setNext(new Node(current->getNext()->getId()));
		temp=temp->getNext();
		current=current->getNext();
	}
}

NodePlay::~NodePlay()
{
	while(head!=nullptr)
	{
		Node *temp=head->getNext();
	
		delete head;
		if(head==temp)//if circular
		{
			head=nullptr;
			break;
		}
		head=temp;
	}
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
	std::cout<<"\nNodes:\n";

	while(current!=nullptr)
	{
		std::cout<<"\tid: "<<current->getId()<<std::endl;
		current=current->getNext();
	}
	std::cout<<"End nodes\n\n";
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


bool NodePlay::remove(int pos)
{
	Node *current=head;
	Node *prev=nullptr;
	for(int i=0;i<pos && current!=nullptr;++i)//by checking current not nullptr, del last element instead
	{
		prev=current;
		current=current->getNext();
	}

	if(current==nullptr)//no node at pos (if head is nullptr)
		return false;

	Node *next=current->getNext();
	
	delete current;

	if(prev!=nullptr)
		prev->setNext(next);
	else//pos==0
	{
		head=next;
		if(next==nullptr)
			return false;//no more elements
		head->setNext(next->getNext());
	}
	return true;
}

void NodePlay::removeAll()
{
	while(remove(0));
}


bool NodePlay::add(int id,int pos)
{
	Node *current=head;
	Node *prev=nullptr;
	
	for(int i=0;i<pos && current!=nullptr;++i)//by checking current!=null, add at end of list
	{
		prev=current;
		current=current->getNext();
	}

	if(prev==nullptr)//check if head needs to be changed
		addFront(id);
	else
	{
		prev->setNext(new Node(id));
		prev->getNext()->setNext(current);
	}
	
	return true;
}

bool NodePlay::add(int *numbers,int *pos,int size)
{
	for(int i=0;i<size;++i)
		if(!this->add(numbers[i],pos[i]))
			return false;
	return true;
}

bool NodePlay::add(Node & a)
{
	if(head==nullptr)
	{
		head=new Node(a);
		return true;
	}
	Node *current=head;
	Node *prev=nullptr;

	while((current->getNext())!=nullptr)
		current=current->getNext();
	
	current->setNext(&a);
	return true;
}


void NodePlay::addFront(int id)
{
	Node *temp=new Node(id);
	temp->setNext(head);
	head=temp;
}


const Node& NodePlay::getNode(int pos) const
{
	Node *current=head;	
	for(int i=0;i<pos && current!=nullptr;++i)//by checking current!=null, add at end of list
		current=current->getNext();
	return *current;
	
}