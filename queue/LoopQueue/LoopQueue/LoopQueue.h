/*
* ѭ������
* Chinaning
* date: 2020/03/23
*
*/
#ifndef LOOPQUEUE_H
#define LOOPQUEUE_H

template <typename T>
class LoopQueue
{
public:
	LoopQueue(int c = 10);//���е���󳤶�һ������Ϊ���ھ�̬���飩
	~LoopQueue();
public:
	bool isEmpty();		//���е��п�
	int size();			//���еĴ�С
	bool push(T t);		//���
	bool pop();			//����
	T front();			//����Ԫ��

private:
	int capacity;//��������
	int begin;//��������
	int end;//��β����
	T*  queue;
};





/***********************  ���캯������������һ���Ŀն��У�  **********************************/
template<typename T>
LoopQueue<T>::LoopQueue(int c = 10)//���ú��ι��캯��
	: capacity(c), begin(0), end(0), queue(nullptr)
{
	queue = new T[capacity];//���ô洢�ṹΪ��̬���飨����Ĵ�С��Ҫ����0��
};






/***********************  ����������ɾ������ָ�뼰Ϊ���з�����ڴ�ռ䣩  **********************************/
template<typename T>
LoopQueue<T>::~LoopQueue()
{
	delete[]queue;
	queue = nullptr;
}







/***********************  �ж϶����Ƿ�Ϊ��  **********************************/
template <typename T>
bool LoopQueue<T>::isEmpty()
{
	if (begin == end)
		return true;
	return false;
};




/***********************  ���г���  **********************************/
template<typename T>
int LoopQueue<T>::size()
{
	return (end - begin + capacity) % capacity; //������г���
};






/***********************  ���  **********************************/
template<typename T>
bool LoopQueue<T>::push(T t)
{
	if (end + 1 % capacity == begin) //�ж϶����Ƿ�����
	{
		return false;
	}
	queue[end] = t;
	end = (end + 1) % capacity;
	return true;
};





/***********************  ����  **********************************/
template <typename T>
bool LoopQueue<T>::pop()
{
	if (end == begin) //�ж϶����Ƿ�Ϊ��
	{
		return false;
	}
	begin = (begin + 1) % capacity;
	return true;
};




/***********************  ���ض���Ԫ��  **********************************/
template <typename T>
T LoopQueue<T>::front()
{
	if (end == begin)
	{
		return false;
	}
	return queue[begin];
};

# endif


