/*
*���ڵ�����ʵ�ֵĶ���
*Chinaning
*2020/03/24
*/

# ifndef LINKQUEUE_H
# define LINKQUEUE_H



/*****************  ����������  ********************/
template<typename T>
class Node
{
public:
	Node(T t) :value(t), next(nullptr) {}//�Զ��庬�ι��캯��
	Node()=default;//����Ĭ���޲ι��캯��������Ϊdefault,��Ȼ�����Զ���Ĺ��캯����ϵͳ�Ͳ����Զ�����Ĭ�Ϲ��캯��
public:
	T value;
	Node<T> * next;
};


/*****************  ���嵥�������  ********************/
template<typename T>
class LinkQueue
{
public:
	LinkQueue();
	~LinkQueue();

	bool isEmpty();
	int size();
	bool pop();
	void push(T t);
	T front();

private:
	Node<T>* head;//ָ��ͷ����ָ�루ͷ��㲻�洢Ԫ�أ���Ϊ��㣩
	Node<T>* pend;//ָ��β����ָ�루β����Ǵ洢Ԫ�ص�ʵ�����һ����㣩
	int count;
};


/*****************  ���캯��  ********************/
template<typename T>
LinkQueue<T>::LinkQueue()
	:head(nullptr), pend(nullptr), count(0)
{
	head = new Node<T>();
	pend = head;//ͷָ���βָ�붼ָ��ͬһ�����
	count = 0;
};






/*****************  ��������  ********************/
template <typename T>
LinkQueue<T>::~LinkQueue()
{
	while (head->next != nullptr)
	{
		Node<T> * pnode = head;
		head = head->next;
	}
};





/*****************  �ж϶����Ƿ�Ϊ��  ********************/
template <typename T>
bool LinkQueue<T>::isEmpty()
{
	return count == 0;
};



/*****************  ���д�С  ********************/
template <typename T>
int LinkQueue<T>::size()
{
	return count;
};






/*****************  ��β���  ********************/
template <typename T>
void LinkQueue<T>::push(T t)
{
	Node<T>* pnode = new Node<T>(t);
	pend->next = pnode;
	pend = pnode;//����ӵĽ����Ϊβ���
	count++;
};





/*****************  ���׳���  ********************/
template <typename T>
bool LinkQueue<T>::pop()
{
	if (count == 0)
		return false;
	Node<T>* pnode = head->next;
	head->next = head->next->next;
	delete pnode;
	pnode = nullptr;
	count--;
	return true;
};

/*****************  ��ȡ����Ԫ��  ********************/
template<typename T>
T LinkQueue<T>::front()
{
	return head->next->value;
};

# endif
