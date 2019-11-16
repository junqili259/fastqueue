//Jun Qi Li
//CSCI 335
//Home Project 3
//FastQueue.h


#ifndef FAST_QUEUE_H
#define FAST_QUEUE_H 
#include<vector>
#include<stdexcept>
#include<iostream>

template <typename T>
class FastQueue
{
	public:
		FastQueue();
		void enqueue(const T& element);
		void dequeue();
		T& head();//return head_index
		T& tail();//return tail_index
		T& at(int index);//return element at index relative to head_index
		int size();//return number_of_elements
		int capacity();//return size_of_container
		void shrink_to_fit();

	private:
		std::vector<T> fast_q;
		int number_of_elements;
		int size_of_container;//allocated space for container
		T head_index;//head
		T tail_index;//tail

	
};//end FastQueue


#include "FastQueue.cpp"
#endif