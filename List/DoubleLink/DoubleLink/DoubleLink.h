#ifndef DOUBLELINK_H
#define DOUBLELINK_H
#include <iostream>

/********** ��㶨�� *************/

template <typename T>
class Node
{
public://����
	Node() = default;
	Node(T _data, Node<T>*_prev, Node<T>* _next)//���ι��캯����ʼ������
		:value(_data), prev(_prev), next(_next) { }
public://����
	T value;//ֵ
	Node<T> *prev;//ָ��ֱ��ǰ����ָ�루ǰ��ָ�룩
	Node<T> *next;//ָ��ֱ�Ӻ�̵�ָ�루���ָ�룩
};





/********* �����壨�ӿڣ� ***********/

template <class T>
class DoubleLink
{
public:
	DoubleLink();//Ĭ�Ϲ��캯��
	DoubleLink(const DoubleLink& ln);//�������캯��
	~DoubleLink();//��������
	void add_front(T e);//��������ǰ�����ֵvalue�Ľ��
	void add_last(T e);//������������ֵvalue�Ľ��
	void addin(int index, T value);//�������±�indexǰ����ֵvalue�Ľ��
	void ascSort();//��������
	void remove(T index);//ɾ��ĳ�����
	Node<T>* pfind(int index);//���ҽ�㲢���ؽ��ָ��
	T find(int index);//���ҽ�㲢���ؽ���value
	bool isEmpty();//�ж��Ƿ�Ϊ��
	int size();//������
	void show();//�������
	void resShow();//�����������
	void removeAll();//ɾ��ȫ�����
private:
	Node<T> *head;//ͷ���
	Node<T> *tail;//β���
	int count;//������
};





/******** Ĭ�Ϲ��캯��������ֻ����ͷ����β�������� **************/

template <typename T>
DoubleLink<T>::DoubleLink()
{
	head = new Node<T>(0, nullptr, nullptr);//Ϊͷ��������ڴ�ռ�
	tail = new Node<T>(0, nullptr, nullptr);//Ϊβ��������ڴ�ռ�
	//�յ�˫��������Ҫͷ����β�����ĸ�ָ���ϵ
	head->next = tail;//ͷ�������β���
	head->prev = nullptr;//ͷ����ǰ��ָ��Ϊ��
	tail->next = nullptr;//β���ĺ��ָ��Ϊ��
	tail->prev = head;//β���ǰ����ͷ���
	count = 0;//�յ�˫��������Ϊ0
}





/********* �������캯�������ж�����¶���ֵ��**********/

template <typename T>
DoubleLink<T>::DoubleLink(const DoubleLink &ln)
{
	head = new Node<T>;
	head->prev = nullptr;
	tail = new Node<T>;
	head->next = tail;
	tail->prev = head;
	count = 0;
	Node<T>* temp = ln.head;
	while (temp->next != ln.tail)
	{
		//��β��㸳ֵ���½�β���
		temp = temp->next;
		tail->value = temp->value;
		Node<T> *node = new Node<T>;
		node->prev = tail;
		tail->next = node;
		tail = node;
		count++;
	}
	tail->next = nullptr;
}




/************ ���� ********************/

//������ǰ���������value
template<typename T>
void DoubleLink<T>::add_front(T value)
{
	Node<T>*node = new Node<T>(value, head, head->next);
	head->next->prev = node;
	head->next = node;
	count++;
	return;
}
//������ĩβ�������value
template <typename T>
void DoubleLink<T>::add_last(T value)
{
	Node<T>* node = new Node<T>(value, tail->prev, tail);
	/*�½�ָ�벢����ҪΪָ����ָ�Ķ���ִ�в�������ҪΪ������ڴ�ռ䣬
	�ڷ���ռ��ͬʱ���ԶԿռ����ݽ��г�ʼ����
	������node�ܹ���Ҫȷ���ĸ�ָ���ϵ�ͽ���valueֵ���ĸ�ָ���ϵ�ֱ��ǣ�
	node->prev,node->prev->next,node->next,node->next->prev,
	��ʼ��������valueֵ��node->prev��node->next����ָ���Ѿ�ȷ����ʣ������ָ��ͨ������
	���ִ��*/
	//��ͬ�ڣ�Node<T> node (VALUE, tail->prev, tail);
	tail->prev->next = node;
	tail->prev = node;
	count++;

}
//���±�Ϊintex���֮ǰ����VALUE
template<typename T>
void DoubleLink<T>::addin(int index, T VALUE) {
	if (index >= count || index < 0) return;
	Node<T>* index_node = pfind(index);
	Node<T>* node = new Node<T>(VALUE, index_node->prev, index_node);
	index_node->prev->next = node;
	index_node->prev = node;
	count++;
	return;
}



/***************** ���� *********************/

//���ҽ��(����ָ�룩
template <typename T>
Node<T>* DoubleLink<T>::pfind(int index)
{
	Node<T> *node = new Node<T>;
	if (count == 0)
	{
		cout << "List is empty";
		return nullptr;
	}
	if (index >= count || index < 0)
	{
		cout << "Out of bounds";
		return nullptr;
	}


	if (index <= count / 2)
	{
		node = head->next;
		while (index)
		{
			node = node->next;
			index--;
		}
	}
	else {
		index = count - index - 1;
		node = tail->prev;
		while (index)
		{
			node = node->prev;
		}
	}
	return node;
}


//���ҽ��(���ؽ���ֵ��
template <typename T>
T DoubleLink<T>::find(int index)
{
	Node<T> *node = new Node<T>;
	if (count == 0)
	{
		cout << "List is empty";
		return NULL;
	}
	if (index >= count || index < 0)
	{
		cout << "Out of bounds";
		return NULL;
	}


	if (index <= count / 2)
	{
		node = head->next;
		while (index)
		{
			node = node->next;
			index--;
		}
	}
	else {
		index = count - index - 1;
		node = tail->prev;
		while (index)
		{
			node = node->prev;
		}
	}
	return node->value;
	//return (*node).value;
}




/***************** ɾ��*********************/

//ɾ�����(ָ��VALUE)
template <typename T>
void DoubleLink<T>::remove(T VALUE)
{
	if (count == 0)
	{
		cout << "List is empty";
		return;
	}
	Node<T> *node = head;
	while (node->next != nullptr)
	{
		node = node->next;
		if (node->value == VALUE)
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;

			delete node;
			node = nullptr;
			count--;
			return;
		}
	}
}
//ɾ�����н��(����ֻʣͷ���head��β���tail)
template <typename T>
void DoubleLink<T>::removeAll()
{
	if (count == 0)
	{
		return;
	}
	Node<T> *node = head->next;
	while (node != tail)
	{
		Node<T>* temp = node;
		node = node->next;
		delete temp;//�ͷ�ָ��tempָ����ڴ�ռ�
		temp = nullptr;//ɾ��ָ���������
	}
	head->next = tail;
	tail->prev = head;
	count = 0;
}




/*************** ���� *********************/

//��������ֻ��value����ѡ������˼�룩
template <typename T>
void DoubleLink<T>::ascSort()
{
	if (count <= 1) return;
	Node<T> *node = head->next;
	for (int i = 0; i < count - 1; i++)
	{
		Node<T> *comp = node->next;
		for (int j = i + 1; j < count; j++)
		{
			if (node->value > comp->value)
			{
				T temp = temp->value;//����
				temp->value = node->value;
				node->value = temp;
			}
			comp = comp->next;
		}
		node = node->next;
	}
}





/*******************  �ж��Ƿ�Ϊ�� **********************/
template <typename T>
bool DoubleLink<T>::isEmpty()
{
	if (count == 0)
	{
		return true;
	}
	else {
		return false;
	}
}





/***********************  ������  ***********************/
template <typename T>
int DoubleLink<T>::size()
{
	return count;
}






/********************  �������  ************************/
//˳���������
template <typename T>
void DoubleLink<T>::show()
{
	if (count == 0)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	Node<T> *node = head->next;
	while (node != tail)
	{
		std::cout << node->value << " ";
		node = node->next;
	}
	std::cout << std::endl;
}
//�����������
template <typename T>
void DoubleLink<T>::resShow()
{
	if (count == 0) return;
	Node<T> *node = tail->prev;
	while (node != head)
	{
		std::cout << node->value << " ";
		node = node->prev;
	}
	std::cout << std::endl;
}





/*************************  ��������  ***************************/
template <typename T>
DoubleLink<T>::~DoubleLink()
{
	if (count == 0)
	{
		delete head;
		head = nullptr;
		delete tail;
		tail = nullptr;
		return;
	}
	while (head->next != nullptr)
	{
		Node<T> *node = head;
		head = head->next;
		delete node;
	}
	delete head;
	head = nullptr;
}



#endif 
