/*���ݽṹ�����������*/
#ifndef BSTREE_H
#define BSTREE_H
#include<queue>

/*�����*/
template <typename K, typename V>
class Node {
public:
	K key;
	V val;
	Node<K, V>* left;
	Node<K, V>* right;
	int N;//�Ըý��Ϊ���������Ľ����
		  //���캯��
	Node(K key, V val, int N) {
		this->key = key;
		this->val = val;
		this->N = N;
		this->left = NULL;
		this->right = NULL;
	}
	//�������캯��
	Node(const Node<K, V>& node) {
		this->key = node.key;
		this->val = node.val;
		this->N = node.N;
		this->left = node.left;
		this->right = node.right;
	}
};




/*���������*/
template <typename K, typename V>
class BSTree {
private:
	Node<K, V>* root = NULL;
	/*������xΪ�����������еĽ����*/
	int size(Node<K, V>* x);
	/*������xΪ����㣬��ֵkey��Ӧ��valֵ*/
	V get(Node<K, V>* x, K key);
	/*��<key,val>������xΪ�����Ķ���������У������ز��������ĸ����*/
	Node<K, V>* put(Node<K, V>* x, K key, V val);
	/*���������nodeΪ�����Ķ�����*/
	void inorder(Node<K, V>* x);
	/*������xΪ�����Ķ����������keyֵ��С�Ľ��*/
	Node<K, V>* min(Node<K, V>* x);
	/*������xΪ�����Ķ����������keyֵ���Ľ��*/
	Node<K, V>* max(Node<K, V>* x);
	/*������xΪ�����Ķ��������������С��key�ļ������ļ��Ľ��*/
	Node<K, V>* floor(Node<K, V>* x, K key);
	/*������xΪ�����Ķ�������������д���key�ļ�����С�ļ��Ľ��*/
	Node<K, V>* ceiling(Node<K, V>* x, K key);
	/*������xΪ�����Ķ���������м�ֵ����Ϊr�Ľ��*/
	Node<K, V>* select(Node<K, V>* x, int r);
	/*������xΪ�����Ķ���������м�ֵkey������*/
	int rank(Node<K, V>* x, K key);
	/*����xΪ�����Ķ����������ɾ����ֵ��С�Ľ�㣬������ɾ������Ķ���������ĸ����*/
	Node<K, V>* deleteMin(Node<K, V>* x);
	/*����xΪ�����Ķ����������ɾ����ֵ���Ľ�㣬������ɾ������Ķ���������ĸ����*/
	Node<K, V>* deleteMax(Node<K, V>* x);
	/*����xΪ�����Ķ����������ɾ����ֵΪkey�Ľ�㣬������ɾ������Ķ���������ĸ����*/
	Node<K, V>* Delete(Node<K, V>* x, K key);
	/*����xΪ�����Ķ���������м�ֵ������[lo,hi]�����м�ֵ���뵽����q��*/
	void keys(Node<K, V>* x, queue<K>& q, K lo, K hi);
public:
	/*�������Ŷ���������еĽ����*/
	int size();
	/*�������Ŷ���������У���ֵkey��Ӧ��valֵ*/
	V get(K key);
	/*��<key,val>���뵽�����������*/
	void put(K key, V val);
	/*����������������*/
	void inorder();
	/*���ض������������С��keyֵ*/
	K min();
	/*���ض��������������keyֵ*/
	K max();
	/*���ض��������������С��key�ļ������ļ�ֵ*/
	K floor(K key);
	/*���ض�������������д���key�ļ�����С�ļ�ֵ*/
	K ceiling(K key);
	/*���ض���������м�ֵ����Ϊr�ļ�ֵ*/
	K select(int r);
	/*���ض���������м�ֵkey������*/
	int rank(K key);
	/*�Ӷ����������ɾ����ֵ��С�Ľ��*/
	void deleteMin();
	/*�Ӷ����������ɾ����ֵ���Ľ��*/
	void deleteMax();
	/*�Ӷ����������ɾ����ֵΪkey�Ľ��*/
	void Delete(K key);
	/*������������м�ֵ������[lo,hi]�����м�ֵ���뵽����q��*/
	queue<K> keys(K lo, K hi);
	/*���ض���������е����м�ֵ*/
	queue<K> keys();
};

template <typename K, typename V>
int BSTree<K, V>::size(Node<K, V>* x) {
	if (x == NULL)return 0;
	else return x->N;
}
template <typename K, typename V>
int BSTree<K, V>::size() {
	return size(root);
}

/*���ң���key���в��ң�������з��ض�Ӧ��val�����򷵻�NULL;*/
template <typename K, typename V>
V BSTree<K, V>::get(Node<K, V>* x, K key) {
	if (x == NULL)
		return NULL;
	if (key>x->key)return get(x->right, key);
	else if (key<x->key)return get(x->left, key);
	else return x->val;
}
template <typename K, typename V>
V BSTree<K, V>::get(K key) {
	return get(root, key);
}

/*���룺��key,val��������*/
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::put(Node<K, V>* x, K key, V val) {
	if (x == NULL)return new Node<K, V>(key, val, 1);
	if (key>x->key)x->right = put(x->right, key, val);//��key����������
	else if (key<x->key)x->left = put(x->left, key, val);//��key����������
	else x->val = val;//����ԭʼֵ
	x->N = size(x->left) + size(x->right) + 1;//ά��Nֵ
	return x;
}
template <typename K, typename V>
void BSTree<K, V>::put(K key, V val) {
	root = put(root, key, val);
}
/*�������*/
template <typename K, typename V>
void BSTree<K, V>::inorder(Node<K, V>* x) {
	if (x == NULL)
		return;
	inorder(x->left);
	cout << x->key << " ";
	inorder(x->right);
}
template <typename K, typename V>
void BSTree<K, V>::inorder() {
	inorder(root);
}
/*��Сֵ�����ֵ*/
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::min(Node<K, V>* x) {
	if (x->left == NULL)return x;
	return min(x->left);
}
template <typename K, typename V>
K BSTree<K, V>::min() {
	return min(root)->key;
}
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::max(Node<K, V>* x) {
	if (x->right == NULL)return x;
	return max(x->right);
}
template <typename K, typename V>
K BSTree<K, V>::max() {
	return max(root)->key;
}
/*��ȡ������ȡ��*/
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::floor(Node<K, V>* x, K key) {
	if (x == NULL)return NULL;
	if (key == x->key)return x;
	if (key<x->key)return floor(x->left, key);
	//��key>x->keyʱ��floor�п�����x->right�����У�Ҳ�п��ܾ���x
	Node<K, V>* t = floor(x->right, key);
	if (t != NULL)return t;
	else return x;
}
template <typename K, typename V>
K BSTree<K, V>::floor(K key) {
	Node<K, V>* x = floor(root, key);
	if (x == NULL)return NULL;
	return x->key;
}
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::ceiling(Node<K, V>* x, K key) {
	if (x == NULL)return NULL;
	if (key == x->key)return x;
	if (key>x->key)return ceiling(x->right, key);
	//��key<x->keyʱ��ceiling�п�����x->left�����У�Ҳ�п��ܾ���x
	Node<K, V>* t = ceiling(x->left, key);
	if (t != NULL)return t;
	else return x;
}
template <typename K, typename V>
K BSTree<K, V>::ceiling(K key) {
	Node<K, V>* x = ceiling(root, key);
	if (x == NULL)return NULL;
	return x->key;
}
/*ѡ��*/
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::select(Node<K, V>* x, int r) {
	if (x == NULL)return NULL;
	int t = size(x->left);
	if (r<t)return select(x->left, r);
	else if (r>t)return select(x->right, r - t - 1);
	else return x;
}
template <typename K, typename V>
K BSTree<K, V>::select(int r) {
	return select(root, r)->key;
}
/*����*/
template <typename K, typename V>
int BSTree<K, V>::rank(Node<K, V>* x, K key) {
	//С�ڼ�ֵkey�ļ�������
	if (x == NULL)return 0;
	if (key<x->key)return rank(x->left, key);
	else if (key>x->key)return size(x->left) + 1 + rank(x->right, key);
	else return size(x->left);
}
template <typename K, typename V>
int BSTree<K, V>::rank(K key) {
	return rank(root, key);
}
/*ɾ����Сֵ�����ֵ*/
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::deleteMin(Node<K, V>* x) {
	if (x == NULL)return NULL;
	Node<K, V>* right = NULL;
	if (x->left == NULL) {
		right = x->right;
		delete x;
		return right;
	}
	x->left = deleteMin(x->left);
	x->N = size(x->left) + size(x->right) + 1;
	return x;
}
template <typename K, typename V>
void BSTree<K, V>::deleteMin() {
	root = deleteMin(root);
}
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::deleteMax(Node<K, V>* x) {
	if (x == NULL)return NULL;
	Node<K, V>* left = NULL;
	if (x->right == NULL) {
		left = x->left;
		delete x;
		return left;
	}
	x->right = deleteMax(x->right);
	x->N = size(x->left) + size(x->right) + 1;
	return x;
}
template <typename K, typename V>
void BSTree<K, V>::deleteMax() {
	root = deleteMax(root);
}
/*ɾ��������*/
template <typename K, typename V>
Node<K, V>* BSTree<K, V>::Delete(Node<K, V>* x, K key) {
	if (x == NULL)return NULL;
	if (key<x->key)x->left = Delete(x->left, key);
	else if (key>x->key)x->right = Delete(x->right, key);
	else {
		if (x->right == NULL)return x->left;
		if (x->left == NULL)return x->right;
		//x->right!=NULL&x->left!=NULL
		Node<K, V>* t = x;
		x = new Node<K, V>(*min(t->right));
		x->right = deleteMin(t->right);
		x->left = t->left;
		delete t;
	}
	x->N = size(x->left) + size(x->right) + 1;
	return x;
}
template <typename K, typename V>
void BSTree<K, V>::Delete(K key) {
	root = Delete(root, key);
}
/*����ָ������ļ�ֵ*/
template <typename K, typename V>
void BSTree<K, V>::keys(Node<K, V>* x, queue<K>& q, K lo, K hi) {
	if (x == NULL)return;
	//���lo<x->key��˵���б����������ı�Ҫ
	if (x->key>lo)keys(x->left, q, lo, hi);
	//ɨ�赱ǰ���
	if (x->key >= lo&&x->key <= hi)q.push(x->key);
	//���x->key<hi��˵���б����������ı�Ҫ
	if (x->key<hi)keys(x->right, q, lo, hi);
}
template <typename K, typename V>
queue<K> BSTree<K, V>::keys(K lo, K hi) {
	queue<K> q;
	keys(root, q, lo, hi);
	return q;
}

template <typename K, typename V>
queue<K> BSTree<K, V>::keys() {
	return keys(min(), max());
}
#endif