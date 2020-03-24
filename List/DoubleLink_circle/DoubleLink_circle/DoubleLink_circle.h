/* content: ѭ��˫������*/

# ifndef _DOUBLELINK_H
# define _DOUBLELINK_H

/*˫������Ľ�㶨��*/
template <typename T>
class Node
{
public:
	Node() {//Ĭ���޲ι��캯��
		prev = nullptr;
		next = nullptr;
	}
	Node(T _value, Node<T>* _prev, Node<T>* _next)
		:value(_value), prev(_prev), next(_next) {}//���ι��캯���г�ʼ������

public:
	T value;//������
	Node<T>* prev;//ǰ��ָ����
	Node<T>* next;//���ָ����
};

/*˫��������*/
template<typename T>
class DoubleLink
{
public:
	typedef Node<T>* pointer;//��Node<T>*���������ض��壬������pointer��ʲô����Node<T>* ���͵Ķ��� 
public:
	DoubleLink();
	~DoubleLink() {};
public:
	Node<T>* insert(int index, T value);
	Node<T>* insert_front(T value);
	Node<T>* insert_last(T value);

	Node<T>* del(int index);
	Node<T>* delete_front();
	Node<T>* delete_last();

	bool isEmpty();
	int size();

	T get(int index);
	T get_front();
	T get_last();
	Node<T>* getHead();

private:
	Node<T>* head;
	int count;
private:
	Node<T>* getNode(int index);
};

/* ���캯��������ֻ����ͷ���Ŀձ�*/
template <typename T>
DoubleLink<T>::DoubleLink()
{
	head = new Node<T>;//����Node��Ĭ���޲ι��캯��Ϊͷ���head�����ڴ�ռ�
	head->next = head;//�ձ�ͷ���ǰ���ͺ�̾����Լ�
	head->prev = head;
	count = 0;//�����Ϊ��
};

/*��ȡͷ���*/
template<typename T>
Node<T>* DoubleLink<T>::getHead()
{
	return head;
}

/*����������*/
template <typename T>
int DoubleLink<T>::size()
{
	return count;
}

/*���ҽ�㣨ָ���±꣩*/
template <typename T>
Node<T>* DoubleLink<T>::getNode(int index)
{
	if (index >= count || index < 0)
		return nullptr;

	if (index <= count / 2) //�����ǰ�벿�־ʹ�ͷ��������ҿ���
	{
		Node<T>* node = head->next;
		while (index)
		{
			node = node->next;
			index--;
		}
		return node;
	}			//�ں�벿�־ʹ�ͷ�����ǰ�ҿ���

	index = count - index - 1;
	Node<T>* node = head->prev;
	while (index)
	{
		node = node->prev;
		index--;
	}
	return node;//����ָ���±�Ľ��
};

/*���½ڵ�嵽��һ��λ��*/
template <typename T>
Node<T>* DoubleLink<T>::insert_front(T value)
{
	Node<T>* newNode = new Node<int>(value, head, head->next);//�½�һ����㣬ǰ��ָ��ָ��ͷ��㣬���ָ��ָ��ͷ���ĺ�̽ڵ�
	head->next->prev = newNode;
	head->next = newNode;//ָ�����˳�򲻿ɵ�������Ϊ����ִ��phead->next_ptr = newNode������phead��newNode֮�������,��phead->next_ptr ->pre_ptr��ΪnewNode->pre_ptr=phead��Ȼ������phead��newNode֮������ӣ���û����newNode��ԭphead->next_ptr֮�佨�����ӡ�
	count++;//���������һ��
	return newNode;
};

/*���½ڵ�嵽����β��*/
template <typename T>
Node<T>* DoubleLink<T>::insert_last(T value)
{
	Node<T> * newNode = new Node<int>(value, head->prev, head);
	head->prev->next = newNode;
	head->prev = newNode;//˳�򲻿ɻ�������ͬ��
	count++;
	return newNode;
};

/*���ڵ�λ�ò嵽indexλ��֮ǰ*/
template <typename T>
Node<T>* DoubleLink<T>::insert(int index, T value)
{
	if (index == 0)
		return insert_front(value);

	Node<T>* node = getNode(index);
	if (node == nullptr)
		return nullptr;
	Node<T>* newNode = new Node<T>(value, node->prev, node);
	node->prev->next = newNode;
	node->prev = newNode;//˳�򲻿ɻ�������ͬ��
	count++;

	return newNode;
};

/*ɾ�������һ���ڵ㲢����ɾ���������һ���ڵ�*/
template<typename T>
Node<T>* DoubleLink<T>::delete_front()
{
	if (count == 0)		//����������nullptr
	{
		return nullptr;
	}
	Node<T>* node = head->next;
	head->next = node->next;
	node->next->prev = head;
	delete node;//�ͷ�ָ��pnodeָ����ڴ�
	count--;
	return head->next;
};

/*ɾ�������ĩβ�ڵ㲢����ɾ��������β��Ԫ��*/
template<typename T>
Node<T>* DoubleLink<T>::delete_last()
{
	if (count == 0)
	{
		return nullptr;
	}
	Node<T>*node = head->prev;
	node->prev->next = head;
	head->prev = node->prev;
	delete node;
	count--;
	return head->prev;
}

/*ɾ��ָ��λ�õ�Ԫ��*/
template <typename T>
Node<T>* DoubleLink<T>::del(int index)
{
	if (index == 0)
		return delete_front();
	if (index == count - 1)
		return delete_last();
	if (index >= count)
		return nullptr;
	Node<T>* node = getNode(index);
	node->prev->next = node->next;
	node->next->prev = node->prev;

	Node<T>* temp = node->prev;
	delete node;
	count--;
	return temp;
};

/*�ж������Ƿ�Ϊ��*/
template <typename T>
bool DoubleLink<T>::isEmpty()
{
	return count == 0;
};

/*��ȡ��һ���ڵ��ֵ*/
template<typename T>
T DoubleLink<T>::get_front()
{
	return head->next->value;
};

/*��ȡ���һ���ڵ��ֵ*/
template <typename T>
T DoubleLink<T>::get_last()
{
	return head->prev->value;
};

/*��ȡָ��λ�ýڵ��ֵ*/
template <typename T>
T DoubleLink<T>::get(int index)
{
	Node<T>  node = getNode(index);
	return node->value;
};
# endif