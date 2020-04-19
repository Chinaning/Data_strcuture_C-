#ifndef MINHEAP_H
#define MINHEAP_H

/************  С���Ѷ���  **************/
template <typename T>
class MinHeap {
public:
	MinHeap(int cap = 10);//���캯��
	~MinHeap();//��������

	bool insert(T val);//����valԪ��
	bool remove(T val);//ɾ��valԪ��
	void print();//��ӡ��
	T getTop();//��ȡ�Ѷ�Ԫ��
	bool (createMinHeap(T a[], int length));//����ָ������������С��

private:
	int capacity;//�ѵ�����������̬����Ĵ�С
	int size;//�ѵ�ʵ�ʴ�С���������е���ЧԪ�ظ���
	T* heap;//�ײ�洢�ṹΪ����

private:
	void filterUp(int index);//������͸�������±�Ϊindex�Ľ������ڵ�����ѣ����ڲ��룩
	void filterDown(int begin, int end);//������͸�������±�Ϊbegin�Ľ����end��������ѣ�����ɾ����

};



/********** ���캯�� ******************/
template<typename T>
MinHeap<T>::MinHeap(int cap = 10) :capacity(cap), size(0), heap(nullptr) {//��������Ķ�������Ҫ��ǰȷ��
	heap = new T[capacity];
};





/************  ��������  *******************/
template<typename T>
MinHeap<T>::~MinHeap() {
	delete[]heap;//�ͷ������ڴ�ռ�
};



/************** ��ӡС����  *******************/
template <typename T>
void MinHeap<T>::print() {
	for (int i = 0; i < size; i++) {
		cout << heap[i] << "  ";//�����Ԫ�ش洢˳���ǰ��մ��ϵ��²�α���С�����������
	}
};



/*************  ��ȡ�Ѷ�Ԫ��  ***************/
template<typename T>
T MinHeap<T>::getTop() {
	if (size != 0)
		return heap[0];
};




/*************  ����Ԫ��  ***************/
template<typename T>
bool MinHeap<T>::insert(T val) {
	if (size == capacity)
		return false;
	heap[size] = val;//�Ƚ��������Ԫ�ط��������β��
	filterUp(size);//Ȼ��������͸�ҵ�����λ��
	size++;
	return true;
};



/******  ������͸  **************/
template<typename T>
void MinHeap<T>::filterUp(int index) {
	T value = heap[index];//����������͸��ʼ���±�Ϊindex�ĵ��ֵ
	while (index > 0) {
		int indexParent = (index - 1) / 2;//�ҵ��õ��˫��
		if (value >= heap[indexParent])//ֱ���õ��ֵ����˫�׵�ֵ�ͷ���Ҫ����
			break;
		else {
			heap[index] = heap[indexParent];
			index = indexParent;
		}
	}
	heap[index] = value;//��ֵvalue�����µ�index���±�ĵ㴦
};



/****************  ɾ��Ԫ��  ***********/
template<typename T>
bool MinHeap<T>::remove(T val){
	if (size == 0)
		return false;
	int index;
	for (index = 0; index < size; index++) {
		if (heap[index] == val)
			break;
	}
	if (index == size)
		return false;
	heap[index] = heap[size - 1];
	filterDown(index, size--);
	return true;
};




/************ ������͸  ****************/
template<typename T>
void MinHeap<T>::filterDown(int current, int end) {
	int child = current * 2 - 1;
	T value = heap[current];
	while (child <= end) {
		if (child<end && heap[child]>heap[child + 1])
			child++;
		if (value < heap[child])
			break;
		else {
			heap[current] = heap[child];
			current = child;
			child = child * 2 + 1;

		}
	 }
	heap[current] = value;
};



/**************** ����ָ�����鴴����С��  **************/
template<typename T>
bool MinHeap<T>::createMinHeap(T a[], int length) {
	if (length > capacity)
		return false;
	for (int i = 0; i < length; i++) {
		insert(a[i]);
	}
	return true;
};




#endif
