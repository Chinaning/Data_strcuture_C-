#ifndef _BITREE_H_
#define _BITREE_H_

using namespace std;

/*��㶨��*/
template <typename T>   /*templateΪ����ģ�壬������������Ϊ�������������Զ���һ�ຯ����*/
class BiTreeNode {
public:
	T data;
	BiTreeNode<T>* left; /*����ָ��*/
	BiTreeNode<T>* right;/*�Һ���ָ��*/
	BiTreeNode(T data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};
/*�ӿڶ���*/
template <typename T>
class BiTree {
private:
	int size;  /*���н��ĸ���*/
public:
	BiTreeNode<T>* root;/*������ָ��*/

	BiTree() { size = 0; root = NULL; };
	~BiTree() { remove(root); };   /*��������~���ͷſռ䣬��ԭ����*/

	bool insert_left(BiTreeNode<T>* node, T data); /*��data���뵽node������*/
	bool insert_right(BiTreeNode<T>* node, T data); /*��data���뵽node���Һ���*/
	bool remove(BiTreeNode<T>* &node); /*ɾ����nodeΪ��������*/
	bool preorderR(BiTreeNode<T>* node, list<T>* l); /*�ݹ�ʵ�֣����������nodeΪ����������������������浽l��*/
	bool preorderI(BiTreeNode<T>* node, list<T>* l); /*����ʵ�֣����������nodeΪ����������������������浽l��*/
	bool inorderR(BiTreeNode<T>* node, list<T>* l);/*�ݹ�ʵ�֣����������nodeΪ����������������������浽l��*/
	bool inorderI(BiTreeNode<T>* node, list<T>* l);/*����ʵ�֣����������nodeΪ����������������������浽l��*/
	bool postorderR(BiTreeNode<T>* node, list<T>* l);/*�ݹ�ʵ�֣����������nodeΪ����������������������浽l��*/
	bool postorderI(BiTreeNode<T>* node, list<T>* l);/*����ʵ�֣����������nodeΪ����������������������浽l��*/
	bool level(BiTreeNode<T>* node, list<T>* l);/*��α�����nodeΪ����������������������浽l��*/
	int height(BiTreeNode<T>* node);/*��nodeΪ�������ĸ߶�*/
};

/**************************************************************************
Function:insert_left
Description:��data���뵽node������
Input:���������node,����data
Output:�����Ƿ�ɹ�
***************************************************************************/
template <typename T>
bool BiTree<T>::insert_left(BiTreeNode<T>* node, T data) {
	if (node == NULL) {//�������������
		if (size>0)
			return false;
		else
			root = new BiTreeNode<T>(data);//����ʱ�����data��Ϊ���ڵ�
	}
	else {
		if (node->left != NULL)
			return false;
		else
			node->left = new BiTreeNode<T>(data);//��data���뵽node������
	}
	size++;//�������Ͻڵ������+1
	return true;
}
/**************************************************************************
Function:insert_right
Description:��data���뵽node���Һ���
Input:���������node,����data
Output:�����Ƿ�ɹ�
***************************************************************************/
template <typename T>
bool BiTree<T>::insert_right(BiTreeNode<T>* node, T data) {
	if (node == NULL) {
		if (size>0)
			return false;
		else
			root = new BiTreeNode<T>(data);
	}
	else {
		if (node->right != NULL)
			return false;
		else
			node->right = new BiTreeNode<T>(data);
	}
	size++;
	return true;
}

/**************************************************************************
Function:remove��������������Ĺ��ܣ�
Description:ɾ����nodeΪ��������������node��
Input:���������node������
Output:ɾ���Ƿ�ɹ�
***************************************************************************/
template <typename T>
bool BiTree<T>::remove(BiTreeNode<T>* &node) {
	/*֮����Ҫ����ָ������ã�����Ϊ����Ҫ�ͷ�nodeָ��Ŀռ䣬
	ͬ��Ҳ��Ҫ��node�ڱ���ĵ�ַ����ΪNULL*/
	if (node == NULL)
		return false;
	if (remove(node->left) && remove(node->right)) {
		delete node;//�ͷ�p�ڵ�ַָ����ڴ�ռ䣬������ռ�õ��ڴ�黹���ڴ��
		node = NULL;//���p�ڵĵ�ַ
		size--;
		return true;
	}
	else
		return false;
}

/**************************************************************************
Function:preorderR��preorderI
Description:���������nodeΪ����������������������浽l�У������ң�
Input:���������node���б�l
Output:�����Ƿ�ɹ�
***************************************************************************/

//�ݹ鷽������node����node->left�����node->right��
template <typename T>
bool BiTree<T>::preorderR(BiTreeNode<T>* node, list<T>* l) {
	if (node == NULL || l == NULL)
		return false;//�������б�ĵ�ַΪ��ʱ����
	l->push_back(node->data);//��������
	preorderR(node->left, l);//�ݹ��ҵ���node->leftΪ���ڵ����ִ��preorderR����
	preorderR(node->right, l);
	return true;
}



//������������node����node->left�����node->right��
template <typename T>
bool BiTree<T>::preorderI(BiTreeNode<T>* node, list<T>* l) {
	if (node == NULL || l == NULL)
		return false;
	stack<BiTreeNode<T>*> s;//����ջs
	BiTreeNode<T>* p = node;
	while (p != NULL || !s.empty()) {
		if (p != NULL) {
			//ѹ��ջʱ���
			l->push_back(p->data);
			s.push(p);
			p = p->left;
		}
		else {
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
	return true;
}

/**************************************************************************
Function:inorderR��inorderI
Description:���������nodeΪ����������������������浽l��
Input:���������node���б�l
Output:�����Ƿ�ɹ�
***************************************************************************/

//�ݹ鷽������node->left����node�����node->right��
template <typename T>
bool BiTree<T>::inorderR(BiTreeNode<T>* node, list<T>* l) {
	if (node == NULL || l == NULL)
		return false;
	inorderR(node->left, l);
	l->push_back(node->data);
	inorderR(node->right, l);
	return true;
}

//������������node->left����node�����node->right��
template <typename T>
bool BiTree<T>::inorderI(BiTreeNode<T>* node, list<T>* l) {
	if (node == NULL || l == NULL)
		return false;
	stack<BiTreeNode<T>*> s;
	BiTreeNode<T>* p = node;
	while (!s.empty() || p != NULL) {
		if (p != NULL) {
			s.push(p);
			p = p->left;//��һ���÷��ʵĽ��
		}
		else {
			p = s.top();
			s.pop();//Ҫ���ʾ͵���
			l->push_back(p->data);//����ջʱ���
			p = p->right;//��һ���÷��ʵĽ��
		}
	}
	return true;
}

/**************************************************************************
Function:postorderR��postorderI
Description:���������nodeΪ����������������������浽l��
Input:���������node���б�l
Output:�����Ƿ�ɹ�
***************************************************************************/

//�ݹ鷽������node->right����node->left�����node��
template <typename T>
bool BiTree<T>::postorderR(BiTreeNode<T>* node, list<T>* l) {
	if (node == NULL || l == NULL)
		return false;
	postorderR(node->left, l);
	postorderR(node->right, l);
	l->push_back(node->data);
	return true;
}

//������������node->right����node->left�����node��
template <typename T>
bool BiTree<T>::postorderI(BiTreeNode<T>* node, list<T>* l) {
	if (node == NULL || l == NULL)
		return false;
	stack<BiTreeNode<T>*> s;
	BiTreeNode<T>* p = node;
	BiTreeNode<T>* pre = NULL;//���ڱ����ǰ���ʹ��Ľ��
	while (!s.empty() || p != NULL) {
		if (p != NULL) {
			s.push(p);
			p = p->left;
		}
		else {
			BiTreeNode<T>* right = s.top()->right;
			if (right != NULL&&right != pre) {
				p = right;
			}
			else {
				//��p==NULL��right!=NULL&&right!=preʱ��˵��Ҫ����ջ�������
				pre = s.top();
				l->push_back(pre->data);
				s.pop();
			}
		}
	}
	return true;
}

/**************************************************************************
Function:level
Description:��α�����nodeΪ����������������������浽l��
Input:���������node���б�l
Output:�����Ƿ�ɹ�
***************************************************************************/
template <typename T>
bool BiTree<T>::level(BiTreeNode<T>* node, list<T>* l) {
	if (node == NULL || l == NULL)
		return false;
	queue<BiTreeNode<T>*> q;//��������
	q.push(node);
	BiTreeNode<T>* p = NULL;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		l->push_back(p->data);
		if (p->left != NULL)q.push(p->left);
		if (p->right != NULL)q.push(p->right);
	}
	return true;
}

/**************************************************************************
Function:height
Description:��nodeΪ�������ĸ߶�
Input:���������node
Output:���ĸ߶�
***************************************************************************/
template <typename T>
int BiTree<T>::height(BiTreeNode<T>* node) {
	if (node == NULL)
		return 0;
	int left_height = height(node->left);
	int right_height = height(node->right);
	return max(left_height, right_height) + 1;
}
#endif