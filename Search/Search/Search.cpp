#include <iostream>
#include<vector>
#include"Search.h"
using namespace  std;

int main() {
	int temp[] = { 1,2,3,4,5,6,7,8 };
	vector<int> vec1(temp,temp+8);//�������������ֵ
	vector<int> vec2(vec1);//��vec1��vec2��ֵ
	vector<int> vec3(vec1);//��vec1��vec3��ֵ
	vector<int> vec4(vec1);//��vec1��vec4��ֵ
	int n = vec1.size();
	int key;

	//˳�����
	cout << "��������Ҫ˳����ҵ�ֵ��" << endl;
	cin >> key;
	Sequential sequence;
	int num1 =sequence.Sequential_search(vec1, key, n);
	cout << num1<<endl;



	//���ֲ���
	cout << "��������Ҫ���ֲ��ҵ�ֵ��" << endl;
	cin >> key;
	Binary binary;
	int num2 = binary.Binary_search(vec1, key, n);
	cout << num2<<endl;



	//��ֵ����
	cout << "��������Ҫ��ֵ���ҵ�ֵ��" << endl;
	cin >> key;
	Interpolation interpolation;
	int num3 = interpolation.Interpolation_search(vec2, key, n);
	cout << num3 << endl;



	//쳲���������
	cout << "��������Ҫ쳲��������ҵ�ֵ��" << endl;
	cin >> key;
	FibonacciSearch fibonacci;
	int num4 = fibonacci.Fibonacci_search(vec3, key, n);
	cout << num4 << endl;


	//�ֿ����
	cout << "��������Ҫ�ֿ���ҵ�ֵ��" << endl;
	cin >> key;
	Block block;
	int num5 = block.Block_search(vec4, key,n);
	cout << num5 << endl;


	system("pause");
}