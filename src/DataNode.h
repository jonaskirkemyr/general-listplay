#ifndef DATANODE_H
#define DATANODE_H

//#include "Node.h"

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

		DataNode(int=5,int=10);//element,max_size, increase with
		DataNode(T *,int);//elements, numb
		DataNode(int);//numb
		DataNode(const DataNode<T>&);

		virtual ~DataNode();

		const T& getData(int=0) const;
		T& getData(int=0);
		int getSize();

		void add(const T&);
		


};

#include "DataNode.cpp"
#endif