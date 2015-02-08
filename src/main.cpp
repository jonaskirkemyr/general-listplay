#include <iostream>


#include "NodePlay.h"
#include "DataNode.h"



using namespace std;

int main()
{
	NodePlay nodeplay(5);

	
	nodeplay.print();
	nodeplay.reverse();
	nodeplay.print();

	nodeplay.remove(9999);
	nodeplay.print();

	nodeplay.remove(-1);
	nodeplay.print();

	nodeplay.add(6,2);
	nodeplay.print();

	nodeplay.add(7,5);
	nodeplay.print();

	nodeplay.add(8,10);
	nodeplay.print(); 

	int id[5]={10,11,12,13,14};
	int pos[5]={0,5,2,12,6};
	nodeplay.add(id,pos,5);
	nodeplay.print();

	nodeplay.removeAll();
	nodeplay.print();

	nodeplay.add(1,10);//add one element

	cout<<nodeplay.isCircular()<<endl;//will add pointer to itself
	nodeplay.makeCircular();
	cout<<nodeplay.isCircular()<<endl;



	//starting datanode
	NodePlay data(5,false);
	DataNode<double> *test=new DataNode<double>(10,10);
	test->add(1.5);
	test->add(2.5);

	data.add(*test);

	DataNode<double>* first=(DataNode<double>*)&data.getNode(1);
	cout<<test->getId()<<test->getData(0)<<endl;

	test->add(3.5);
	 

	cout<<first->getId()<<first->getData()<<first->getData(1)<<first->getData(2)<<first->getData(3)<<endl;


	cin.get();


	return 0;
}