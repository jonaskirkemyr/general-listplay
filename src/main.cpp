#include <iostream>
#include "NodePlay.h"


using namespace std;

int main()
{
	NodePlay nodeplay;

	
	nodeplay.print();
	nodeplay.reverse();
	nodeplay.print();

	cout<<nodeplay.isCircular()<<endl;
	nodeplay.makeCircular();
	cout<<nodeplay.isCircular()<<endl;
	cin.get();
	return 0;
}