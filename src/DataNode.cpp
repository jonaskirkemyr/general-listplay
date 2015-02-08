#ifdef DATANODE_H

//private
template <typename T>
void DataNode<T>::initData(int max) 
{
	this->size=0;
	this->max_size=max;

	this->data=new T[this->max_size];
}

template <typename T>
void DataNode<T>::increase()
{
	T *temp=new T[max_size];//copy old values before increasing size of data

	for(int i=0;i<size;++i)
		temp[i]=data[i];
	delete[] data;//make sure to free memory
	
	max_size+=INCREASE;
	data=new T[max_size];

	for(int i=0;i<size;++i)
		data[i]=temp[i];
	delete[] temp;//make sure to free memory
}



//public
template <typename T>
DataNode<T>::DataNode(int max,int inc) : Node(1337),INCREASE(inc)
{
	this->initData(max);
}

template <typename T>
DataNode<T>::DataNode(T* elems,int size) : Node(0),INCREASE(size)
{
	initData(size);
	for(int i=0;i<size;++i)
		this->add(elems[i]);
}

template <typename T>
DataNode<T>::DataNode(int size) : Node(1337),INCREASE(size)
{
	initData(size);
}

template <typename T>
DataNode<T>::DataNode(const DataNode<T>& cpy) : id(cpy.id), INCREASE(cpy.INCREASE)
{
	size=cpy.size;
	max_size=cpy.max_size;
	
	data=new T[max_size];

	for(int i=0;i<++size;++i)
		data[i]=cpy.data[i];
}


template <typename T>
DataNode<T>::~DataNode()
{
	delete[] data;
	data=nullptr;
} 




template<typename T>
const T& DataNode<T>::getData(int pos) const
{
	if(pos<0 || pos>=size)//make sure retrieving from pos that exists
		pos=0;
	return data[pos];
	 
}

template<typename T>
T& DataNode<T>::getData(int pos)
{
	if(pos<0 || pos>=size)//make sure retrieving from pos that exists
		pos=0;
	return data[pos];
}


template <typename T>
void DataNode<T>::add(const T& add)
{
	if(size>=max_size)
		increase();
	data[this->size]=add;
	++this->size;
}

#endif