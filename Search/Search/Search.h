#ifndef SEARCH_H
#define SEARCH_H
#include<vector>
using namespace std;

/********************************  ˳�����  *************************************/
class Sequential {

public:
	int Sequential_search(vector<int> &a, int value, int n)
	{

		for (int i = 0; i < n; i++)
			if (a[i] == value)
				return i;
		return -1;
	}
};



/********************************  ���ֲ��ң��۰���ң�  *************************************/
class Binary {
public:
	int Binary_search(vector<int>& a, int value, int n) {
		int low, high, mid;
		low = 0;
		high = n - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (a[mid] == value)
				return mid;
			if (a[mid] > value)
				high = mid - 1;
			if (a[mid] < value)
				low = mid + 1;
		}
		return -1;

	}
};

/********************************  ��ֵ����  *************************************/
class Interpolation {
public:
	int Interpolation_search(vector<int>&b, int value, int n) {
		int low = 0;//��λ�±�
		int high = n - 1;//��λ�±�
		int mid;//�м�ֵ�±�
		while (low <= high)
		{
			mid = (high - low)*(value - b[low]) / (b[high] -b[low]);
			//��ֵ(��������Ԫ�ص�����������ϵ��mid��������һ�ָ������ܵĶ��ֲ���
			if (value < b[mid])
			{
				high = mid - 1;
			}
			else if (value > b[mid])
			{
				low = mid + 1;
			}
			else
			{
				return mid;
			}
		}
		return -1;
	}
};


/********************************  쳲���������  *************************************/
class FibonacciSearch {
public:
	const int max_size = 20;
public:
	void Fibonacci(vector<int>& F,int size)
	{
		F[0] = 0;
		F[1] = 1;
		for (int i = 2; i<size; ++i)
			F[i] = F[i - 1] + F[i - 2];
	}

	int Fibonacci_search(vector<int>&a, int value, int n)
	{
		
		int low = 0, k = 0;
		int high = n - 1;
		vector<int>F(max_size);
		Fibonacci(F,max_size);       //����һ��쳲���������F 
		while (n > F[k] - 1)   //����nλ��쳲��������е�λ��
			++k;

		//int* temp = new int[F[k] - 1];    //������a��չ��F[k]-1�ĳ���
	//	memcpy(temp, a, n * sizeof(int));

		for (int i = n; i < F[k] - 1; ++i)
			a.push_back( a[n - 1]);//������������Ԫ�صĸ���n��F[k] - 1��

		while (low <= high)
		{
			int mid = low + F[k - 1] - 1;
			if (value < a[mid])
			{
				high = mid - 1;
				k -= 1;
			}
			else if (value > a[mid])
			{
				low = mid + 1;
				k -= 2;
			}
			else
			{
				if (mid < n) return mid; //�������˵��mid��Ϊ���ҵ���λ��
				else        return n - 1; //��mid>=n��˵������չ����ֵ,����n-1
			}
		}
		return -1;
	}
	
};

/********************************  �ֿ����  *************************************/
class Block {
public:
	struct blocking//�ṹ������������ֿ�
	{
		int key;
		int start;
		int end;
	}blocking[2];

	int Block_search(vector<int>&a,int key,int n)
	{
		int j=0;
		for (int i = 0; i<2; i++)
		{
			blocking[i].start = j ;//ȷ��ÿ�������ʼλ��
			blocking[i].end = j+3 ;//ȷ��ÿ����Ľ���λ��
			blocking[i].key = a[j+3];//ȷ��ÿ���鷶Χ�е�Ԫ�����ֵ
			j = j + 4;
		}
		int num = 0;
		while (num<2 && key>blocking[num].key)//ȷ�����ĸ�����
			num++;
		if (num >= 2)//���ڷֵõĿ�������-1
			return -1;
		j = blocking[num].start;//j���ڿ鷶Χ����ʼֵ
		while (j <= blocking[num].end && a[j] != key)//��ȷ���Ŀ��ڽ��в���
			j++;
		if (j>blocking[num].end)//������ڿ鷶Χ�Ľ���ֵ ��˵��û��Ҫ���ҵ��� j��0
			j= -1;
		return j;
		
	}
};


#endif // !SEARCH_H
