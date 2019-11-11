//Jun Qi Li
//CSCI 335
//Home Project 3

#include"FastQueue.h"

//creates vector of size 10 with all values set as 0
template<typename T>
FastQueue<T>::FastQueue():number_of_elements{0}, size_of_container{10}, fast_q(10), head_index{5}, tail_index{5}
{}



//adds a news element to the end of the queue
template<typename T>		
void FastQueue<T>::enqueue(T element){}
		

//removes an element from the head of the queue
//does nothing if queue is empty
template<typename T>
void FastQueue<T>::dequeue(){
	
	
}



//returns reference to head_index
//throws out of range if container is empty
template<typename T>
T& FastQueue<T>::head(){
	try
	{
		if (size() == 0){
			throw std::out_of_range("OUT OF RANGE ERROR: empty container");
			
		}
	}
	catch(std::out_of_range& error_msg)
	{
		std::cerr << error_msg.what() << std::endl;
	}
	return head_index;
}

//returns reference to the last element of the queue
//throws out of range if the container is empty
template<typename T>
T& FastQueue<T>::tail(){
	try{
		if(size() == 0){
			throw std::out_of_range("OUT OF RANGE ERROR: empty container");
		}
	}
	catch(const std::out_of_range& error_msg)
	{
		std::cerr << error_msg.what() << std::endl;
	}
	return tail_index;
}


//returns reference to the index-th element of the queue.
//throws out of range if container size is less than index
template<typename T>
T& FastQueue<T>::at(int index){}


//returns the number of elements in container
template<typename T>
int FastQueue<T>::size(){
	return number_of_elements;
}


//returns size of allocated memory in terms of elements
template<typename T>
int FastQueue<T>::capacity(){
	return size_of_container;
}


//shrinks the size of allocated memory to exactly fit the elements currently in queue
template<typename T>
void FastQueue<T>::shrink_to_fit(){}
