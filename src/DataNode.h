#ifndef DATANODE_H
#define DATANODE_H

#include "Node.h"

template <typename T>
class DataNode : public Node
{
	private:
		const int INCREASE;

		T * data;
		int size;
		int max_size;

		void initData(int=5);
		void increase();

	public:
		DataNode(T,int=5,int=10);//element,max_size, increase with
		DataNode(T *,int);//elements, numb
		DataNode(int);//numb


		const T& getData(int=0) const;
		int getSize();

		void add(const T&);
		


};

#endif