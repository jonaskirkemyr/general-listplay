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
};
#endif