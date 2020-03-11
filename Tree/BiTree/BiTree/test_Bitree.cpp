#include <iostream>
#include <list> //�б�
#include <stack>//ջ
#include <queue>//����
#include"BiTree.h"//�����Զ���ͷ�ļ�

using namespace std;


/*������*/
int main() {
	BiTree<int>* biTree = new BiTree<int>();
	/*
	������������
	3
	6   2
	8 9
	*/
	biTree->insert_left(biTree->root, 3);
	biTree->insert_left(biTree->root, 6);
	biTree->insert_right(biTree->root, 2);
	biTree->insert_left(biTree->root->left, 8);
	biTree->insert_right(biTree->root->left, 9);
	list<int> l;
	list<int>::iterator iter;
	//�������
	biTree->preorderR(biTree->root, &l);
	cout << endl << "�������(�ݹ�)��";
	for (iter = l.begin(); iter != l.end(); iter++)
		cout << *iter << ",";
	l.clear();
	biTree->preorderI(biTree->root, &l);
	cout << endl << "�������(����)��";
	for (iter = l.begin(); iter != l.end(); iter++)
		cout << *iter << ",";
	l.clear();

	//�������
	biTree->inorderR(biTree->root, &l);
	cout << endl << "�������(�ݹ�)��";
	for (iter = l.begin(); iter != l.end(); iter++)
		cout << *iter << ",";
	l.clear();
	biTree->inorderI(biTree->root, &l);
	cout << endl << "�������(����)��";
	for (iter = l.begin(); iter != l.end(); iter++)
		cout << *iter << ",";
	l.clear();

	//�������
	biTree->postorderR(biTree->root, &l);
	cout << endl << "�������(�ݹ�)��";
	for (iter = l.begin(); iter != l.end(); iter++)
		cout << *iter << ",";
	l.clear();
	biTree->postorderI(biTree->root, &l);
	cout << endl << "�������(����)��";
	for (iter = l.begin(); iter != l.end(); iter++)
		cout << *iter << ",";
	l.clear();

	//��α���
	biTree->level(biTree->root, &l);
	cout << endl << "��α�����";
	for (iter = l.begin(); iter != l.end(); iter++)
		cout << *iter << ",";
	l.clear();
	cout << endl << biTree->height(biTree->root);
	delete biTree;
	system("pause");//���ڳ�������ʵ�����ã�����ĩβ������ʾVS�����н�����������н����һ���������޷�������
}