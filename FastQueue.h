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
		void enqueue(T element);
		void dequeue();
		T& head();
		T& tail();
		T& at(int index);
		int size();
		int capacity();
		void shrink_to_fit();

		void print();
	private:
		std::vector<T> fast_q;
		int number_of_elements;
		int size_of_container;
		T head_index;
		T tail_index;

	
};



#include "FastQueue.cpp"
#endif