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


	for (int i = 1; i <= 11; i++)
	{
		obj.enqueue(i);
	}
	cout << "number of elements = " << obj.size() << endl;
	


	
	
	obj.print();
	cout << obj.head() << endl;
	cout << obj.tail() << endl;
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.print();
	cout << "head = " << obj.head() << endl;
	cout << "number of elements = " << obj.size() << endl;

	return 0;
}