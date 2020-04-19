#ifndef AVLTree_H
#define AVLTree_H

/********************** AVL����㶨�� ***************************/
template<typename T>
class TreeNode
{
public:
	T data;//ֵ
	int height;//�߶�
	unsigned int freq;//Ƶ��
	TreeNode* left;//ָ������ӵĵ�ַ
	TreeNode* right;//ָ���Ҷ��ӵĵ�ַ
public:
	TreeNode() :left(NULL), right(NULL), freq(1), height(0) {}
};





/*******************  AVL��������Ժͷ�������(�ӿڣ�***********************/
template<typename T>
class AVLTree
{
private://ʵ�ַ�������˽�г�Ա������ֻ���ɱ���ĳ�Ա�������ʣ����ɱ��ⲿ��Ա���ʣ�Ҳ���ɱ���Ķ���ֱ�ӷ���
	TreeNode<T>* root;//���ڵ�
	void insertpri(TreeNode<T>* &node, T x);//���루����node���Ϊ���ڵ��AVL���в���ֵΪx�Ľ�㣩
	TreeNode<T>* findpri(TreeNode<T>* node, T x);//���ң�����node���Ϊ���ڵ��AVL���в���ֵΪx�Ľ�㣩
	void insubtree(TreeNode<T>* node);//�������
	void Deletepri(TreeNode<T>* &node, T x);//ɾ��
	int height(TreeNode<T>* node);//�����ĸ߶�
	void LL(TreeNode<T>* &k2);//��������µ���ת
	void RR(TreeNode<T>* &k2);//��������µ���ת
	void LR(TreeNode<T>* &k3);//��������µ���ת
	void RL(TreeNode<T>* &k3);//��������µ���ת
	int Max(int cmpa, int cmpb);//�����ֵ

public://�����ֲ�����ʵ�ַ�����װ����public�ӿڹ��ⲿ����Ķ������
	AVLTree() :root(NULL) {}
	void insert(T x);//����ӿ�
	TreeNode<T>* find(T x);//���ҽӿ�
	void Delete(T x);//ɾ���ӿ�
	void traversal();//�����ӿ�

};




/*******************  AVL����ķ������� ***********************/

//����ڵ�ĸ߶�
template<typename T>
int AVLTree<T>::height(TreeNode<T>* node)
{
	if (node != NULL)
		return node->height;
	return -1;
}



//�����ֵ
template<typename T>
int AVLTree<T>::Max(int cmpa, int cmpb)
{
	return cmpa>cmpb ? cmpa : cmpb;
}


//��������µ���ת
template<typename T>
void AVLTree<T>::LL(TreeNode<T>* &k2)
{
	TreeNode<T>* k1;
	k1 = k2->left;//�ҵ����ڵ�k2�����ӽ��

	k2->left = k1->right;
	k1->right = k2;//����

	k2->height = Max(height(k2->left), height(k2->right)) + 1;
	k1->height = Max(height(k1->left), k2->height) + 1;
}




//��������µ���ת
template<typename T>
void AVLTree<T>::RR(TreeNode<T>* &k2)
{
	TreeNode<T>* k1;
	k1 = k2->right;

	k2->right = k1->left;
	k1->left = k2;

	k2->height = Max(height(k2->left), height(k2->right)) + 1;
	k1->height = Max(height(k1->right), k2->height) + 1;
}



//�����������ת
template<typename T>
void AVLTree<T>::LR(TreeNode<T>* &k3)
{
	RR(k3->left);
	LL(k3);
}



//�����������ת
template<typename T>
void AVLTree<T>::RL(TreeNode<T>* &k3)
{
	LL(k3->right);
	RR(k3);
}



//����
template<typename T>
void AVLTree<T>::insertpri(TreeNode<T>* &node, T x)
{
	if (node == NULL)//����ڵ�Ϊ��,���ڴ˽ڵ㴦����x��Ϣ
	{
		node = new TreeNode<T>();
		node->data = x;
		return;
	}
	if (node->data>x)//���xС�ڽڵ��ֵ,�ͼ����ڽڵ���������в���x
	{
		insertpri(node->left, x);
		if (2 == height(node->left) - height(node->right))//����߶�֮��Ϊ2�Ļ���ʧȥ��ƽ��,��Ҫ��ת
			if (x<node->left->data)
				LL(node);
			else
				LR(node);
	}
	else if (node->data<x)//���x���ڽڵ��ֵ,�ͼ����ڽڵ���������в���x
	{
		insertpri(node->right, x);
		if (2 == height(node->right) - height(node->left))//����߶�֮��Ϊ2�Ļ���ʧȥ��ƽ��,��Ҫ��ת
			if (x>node->right->data)
				RR(node);
			else
				RL(node);
	}
	else ++(node->freq);//������,�Ͱ�Ƶ�ʼ�1
	node->height = Max(height(node->left), height(node->right));
}
//����ӿ�
template<typename T>
void AVLTree<T>::insert(T x)
{
	insertpri(root, x);
}


//����
template<typename T>
TreeNode<T>* AVLTree<T>::findpri(TreeNode<T>* node, T x)
{
	if (node == NULL)//����ڵ�Ϊ��˵��û�ҵ�,����NULL
	{
		return NULL;
	}
	if (node->data>x)//���xС�ڽڵ��ֵ,�ͼ����ڽڵ���������в���x
	{
		return findpri(node->left, x);
	}
	else if (node->data<x)//���x���ڽڵ��ֵ,�ͼ����ڽڵ���������в���x
	{
		return findpri(node->right, x);
	}
	else return node;//������,���ҵ��˴˽ڵ�
}
//���ҽӿ�
template<class T>
TreeNode<T>* AVLTree<T>::find(T x)
{
	return findpri(root, x);
}



//ɾ��
template<typename T>
void AVLTree<T>::Deletepri(TreeNode<T>* &node, T x)
{
	if (node == NULL) return;//û���ҵ�ֵ��x�Ľڵ�
	if (x < node->data)
	{
		Deletepri(node->left, x);//���xС�ڽڵ��ֵ,�ͼ����ڽڵ����������ɾ��x
		if (2 == height(node->right) - height(node->left))//����߶�֮��Ϊ2�Ļ���ʧȥ��ƽ��,��Ҫ��ת
			if (node->right->left != NULL && (height(node->right->left)>height(node->right->right)))
				RL(node);
			else
				RR(node);
	}

	else if (x > node->data)
	{
		Deletepri(node->right, x);//���x���ڽڵ��ֵ,�ͼ����ڽڵ����������ɾ��x
		if (2 == height(node->left) - height(node->right))
			if (node->left->right != NULL && (height(node->left->right)>height(node->left->left)))
				LR(node);
			else
				LL(node);
	}

	else//������,�˽ڵ����Ҫɾ���Ľڵ�
	{
		if (node->left&&node->right)//�˽ڵ�����������
		{
			TreeNode<T>* temp = node->right;//tempָ��ڵ���Ҷ���
			while (temp->left != NULL) temp = temp->left;//�ҵ���������ֵ��С�Ľڵ�
														 //������������С�ڵ��ֵ��ֵ�����ڵ�
			node->data = temp->data;
			node->freq = temp->freq;
			Deletepri(node->right, temp->data);//ɾ������������Сֵ�Ľڵ�
			if (2 == height(node->left) - height(node->right))
			{
				if (node->left->right != NULL && (height(node->left->right)>height(node->left->left)))
					LR(node);
				else
					LL(node);
			}
		}
		else//�˽ڵ���1����0������
		{
			TreeNode<T>* temp = node;
			if (node->left == NULL)//���Ҷ��ӻ���û�ж���
				node = node->right;
			else if (node->right == NULL)//�������
				node = node->left;
			delete(temp);
			temp = NULL;
		}
	}
	if (node == NULL) return;
	node->height = Max(height(node->left), height(node->right)) + 1;
	return;
}
//ɾ���ӿ�
template<typename T>
void AVLTree<T>::Delete(T x)
{
	Deletepri(root, x);
}


//�����������
template<typename T>
void AVLTree<T>::insubtree(TreeNode<T>* node)
{
	if (node == NULL) return;
	insubtree(node->left);//�ȱ���������
	cout << node->data << " ";//������ڵ�
	insubtree(node->right);//�ٱ���������
}
//��������ӿ�
template<typename T>
void AVLTree<T>::traversal()
{
	insubtree(root);
}

#endif
