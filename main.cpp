#include"FastQueue.h"
#include<iostream>
using std::cout;
using std::endl;

int main()
{
	FastQueue<int> obj;
	//cout << obj.size() << endl;
	//cout << obj.head() << endl;
	//cout << obj.tail() << endl;
	//cout << obj.capacity() << endl;
	//obj.dequeue();

	//cout << obj.head() << endl;

	
	obj.enqueue(1);
	//cout << "Size: " << obj.size() << endl;

	cout << obj.head() << endl;
	cout << obj.tail() << endl;

	
	obj.print();

	return 0;
}