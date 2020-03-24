#ifndef SINGLELINK_H
#define SINGLELINK_H
#include<vector>

using namespace std;

/****************** ��㶨�� ********************/

template<typename T>
class Node {
public:
	T value;//ֵ
	Node<T>*next;//ָ��
public:
	Node() { next = nullptr; };
	Node(T _value, Node<T>*_next) :value(_value), next(_next) {}
};



/***************** �����壨�ӿڣ� **********************/

template<typename T>
class SingleLink {
private://˽�г�Աֻ�ܳ�Ա��������
	Node<T>*head;
	int count;
public:
	SingleLink();//���캯�������ɿձ�
	Node<T>*find_index(int index);//�����±�Ϊindex�Ľ�㲢����ָ�����ָ��
	vector<int>*find_value(T value);//����ֵΪvalue�Ľ�㲢����ָ����������ָ��
	int find_value_aid(T VALUE);//����ֵΪvalue�Ľ�㲢���ظ���
	void add_front(T value);//ǰ��
	void add_last(int index, T value);//���
	void add(int index, T value);//�±�index�����
	void del_index(int index);//ɾ���±�index�Ľ��
	void del_value(T VALUE);//ɾ��ֵΪVALUE�Ľ��
	int size();//������
	bool isEmpty();//�Ƿ�Ϊ��
	void show();//�������
	
};





/***************  ���캯�������ɿձ�  ******************/

template<typename T>
SingleLink<T>::SingleLink() {
	head = new Node<T>;//����Node���Ĭ���޲ι��캯����ֻ��ָ�븳ֵnullptr
	count = 0;
}





/***************************  ����  *******************************/

//�����±�Ϊindex�Ľ�㲢����ָ��ý��ָ��
template<typename T>
Node<T>*SingleLink<T>::find_index(int index) {
	if (index < 0 || index >= count) return nullptr;
	Node<T>*node = head->next;
	while (index) {
		node = node->next;
		index--;
	}
	return node;
}

//����ֵΪVALUE�Ľ�㲢���ؽ���index����ָ��
template<typename T>
vector<int>* SingleLink<T>::find_value(T VALUE) {
	vector<int> *VECTOR = new vector<int>();
	Node<T>*node = head->next;
	int index = 0;
	int num = 0;
	while (node != nullptr) {
		if (node->value = VALUE) {
			VECTOR->push_back(index);
			num++;
		};
		node = node->next;
		index++;
	}
	return VECTOR;
}

//����ֵΪVALUE�Ľ�㲢���ؽ�����
template<typename T>
int SingleLink<T>::find_value_aid(T VALUE) {
	vector<int> VECTOR;
	Node<T>*node = head->next;
	int index = 0;
	int num = 0;
	while (node != nullptr) {
		if (node->value = VALUE) {
			VECTOR.push_back(index);
			num++;
		};
		node = node->next;
		index++;
	}
	return num;
}








/*****************  ����  ********************************/

//��ǰ�����ֵΪvalue�Ľ��
template<typename T>
void SingleLink<T>::add_front(T value) {
	Node<T>* node = new Node<T>(value, head->next);
	head->next = node;
	count++;
	return;
}

//�±�index�Ľ������ֵΪvalue�Ľ��(index=count-1)
template<typename T>
void SingleLink<T>::add(int index, T value) {
	if (index < 0 || index >= count) return;
	Node<T>*index_node = find_index(index);//ע������index������룬�����index���ǰ������Ҫfind(index-1)������Ҫ�ı�
	Node<T>*node = new Node<T>(value, index_node->next);
	index_node->next = node;
	count++;
	return;
}

//��������ֵΪvalue�Ľ��
template<typename T>
void SingleLink<T>::add_last(int index, T value) {
	add(index, value);
	return;
}






/***********************  ɾ��  ***************************************/

//ɾ���±�Ϊindex�Ľ��
template<typename T>
void SingleLink<T>::del_index(int index) {
	if (index < 0 || index >= count) return;
	if (index == 0) {
		Node<T>*temp = head->next;//�½�һ����ʱ�ڵ�洢δ�ı��head->next����ɾ��
		head->next = head->next->next;
		delete temp;
		temp = nullptr;
		count--;
		return;
	}
	Node<T>*node = find_index(index);//�ҵ��±�Ϊindex�Ľ��
	Node<T>*node_front = find_index(index - 1);//�ҵ��±�Ϊindex-1�Ľ��
	node_front->next = node->next;//��index-1����ָ��ָ��index->next
	delete node;
	node = nullptr;
	count--;
	return;

}

//ɾ��ֵΪvalue�Ľ�㣨���ܲ�ֹһ���ڵ��ֵΪVALUE��
template <typename T>
void SingleLink<T>::del_value(T VALUE) {
	if (isEmpty()) return;
	Node<T>*node_front = head;
	Node<T>*node = node_front->next;
	while (node != nullptr) {
		Node<T>*temp = node;//�½�һ����ʱ�ڵ�洢δ�ı��node����ɾ��
		if (node->value == VALUE) {
			node_front->next = node->next;
			node = node->next;
			delete temp;
			temp = nullptr;
			count--;

		}
		else {
			node_front = node_front->next;
			node = node->next;
		}


	}
	return;

}







/***********************  ����б��value  *************************/

//˳������б�ֵ�����������
template<typename T>
void SingleLink<T>::show() {
	Node<T>*node = head->next;
	while (node != nullptr) {
		cout << node->value << "  ";
		node = node->next;
	}
	cout << endl << count << endl;
	return;
}






/***************   �ж������Ƿ�Ϊ��  **********************************/
template<typename T>
bool SingleLink<T>::isEmpty() {
	if (count == 0) {
		cout << "������" << endl;
		return true;
	}
	else {
		cout << "���ǿ�����" << endl;
		return false;
	}
}




/***********************  ������  ************************************/

template<typename T>
int SingleLink<T>::size() {
	return count;
}


#endif


