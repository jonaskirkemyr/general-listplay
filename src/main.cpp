#include <iostream>
#include "NodePlay.h"


using namespace std;

int main()
{
	NodePlay nodeplay(1537);

	
	nodeplay.print();
	nodeplay.reverse();
	nodeplay.print();

	nodeplay.remove(9999);
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


	cin.get();
	return 0;
}