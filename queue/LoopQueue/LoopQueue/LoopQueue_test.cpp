/*
* Chinaning
* 20200324
*/


#include<iostream>
#include"LoopQueue.h"
#include<string>
using namespace std;
int main()
{
	LoopQueue<string> queue(6);
	queue.push("one");
	queue.push("two");
	queue.push("three");
	queue.push("four");
	queue.push("five");
	cout << "���г���" << queue.size() << endl;
	while (!queue.isEmpty())
	{
		cout << queue.front() << endl;
		queue.pop();
	}
	getchar();//����VSһ�������ķ���֮һ
	return 0;

}