#include<iostream>
#include<string>
#include"LinkStack.h"
using namespace std;


int main()
{
	LinkStack <string> lstack;
	lstack.push("hello");
	lstack.push("to");
	lstack.push("you");
	int SIZE = lstack.size();
	string TOP = lstack.top();
	cout << "ջ�Ĵ�С:" << SIZE << endl;
	cout << "ջ��Ԫ��:" << TOP << endl;

	while (!lstack.isEmpty())
	{
		lstack.pop();
	}


	getchar();
	return 0;
}
