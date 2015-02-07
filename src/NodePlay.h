#ifndef NODEPLAY_H
#define NODEPLAY_H

#include <iostream>
#include "Node.h"
class NodePlay
{
	private:
		Node *head;
		void createNodes(int=5);
	public:
		NodePlay(int=5);//#node to create

		bool isCircular();

		void makeCircular();

		void print();

		void reverse();

		bool remove(int);//pos
		void removeAll();

		bool add(int,int);//id,pos
		bool add(int *,int*,int);//array of ids,array of pos,size
		void addFront(int);//id

		
};
#endif