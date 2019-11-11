//Jun Qi Li
//CSCI 335
//Home Project 3

#include"FastQueue.h"

//creates vector of size 10 with all values set as 0
template<typename T>
FastQueue<T>::FastQueue():number_of_elements{0}, size_of_container{10}, fast_q(10,0), head_index{5}, tail_index{5}
{}//end constructor



//adds a news element to the end of the queue
template<typename T>		
void FastQueue<T>::enqueue(T element){

 //if container is empty
	if (number_of_elements == 0)
	{
		fast_q[head_index] = element;
		number_of_elements++;
	}

 //if container is full?
	else if(size_of_container == number_of_elements)
	{
		int new_size = size_of_container*2;
		std::vector<T> temp(new_size, 0);


		for (int i = 0; i <= tail_index; i++){
			temp[i] = fast_q[i];
		}
		////////////
		for (auto item1:temp){
			std::cout << item1 << " ";
		}
		std::cout << std::endl;
		/////////////
		
		int size_of_container_copy = size_of_container;
		for (int j = new_size; head_index <= j; j--)
		{
			temp[j] = fast_q[size_of_container_copy];
			size_of_container_copy--;
		}
		////////////////
		for (auto item2:temp){
			std::cout << item2 << " ";
		}
		std::cout << std::endl;
		///////////////

		size_of_container = new_size;
		fast_q = std::move(temp);
		
		//insert new element
		fast_q[++tail_index] = element;
		number_of_elements++;
	}
	else if (tail_index < size_of_container - 1 && head_index <= tail_index)
	{
		fast_q[++tail_index] = element;
		number_of_elements++;
	}
	else if (tail_index < size_of_container - 1 && tail_index < head_index)
	{
		fast_q[++tail_index] = element;
		number_of_elements++;
	}
 //if out of range of container
	else if(tail_index == size_of_container-1)
	{
		tail_index = 0;
		fast_q[tail_index] = element;
		number_of_elements++;
	}
	
}//end enqueue
		

//removes an element from the head of the queue
//does nothing if queue is empty
template<typename T>
void FastQueue<T>::dequeue(){
	
	
}//end dequeue



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
}//end head

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
}//end tail


//returns reference to the index-th element of the queue.
//throws out of range if container size is less than index
template<typename T>
T& FastQueue<T>::at(int index){}//end at


//returns the number of elements in container
template<typename T>
int FastQueue<T>::size(){
	return number_of_elements;
}//end size


//returns size of allocated memory in terms of elements
template<typename T>
int FastQueue<T>::capacity(){
	return size_of_container;
}//end capacity


//shrinks the size of allocated memory to exactly fit the elements currently in queue
template<typename T>
void FastQueue<T>::shrink_to_fit(){}//end shrink_to_fit


template<typename T>
void FastQueue<T>::print(){
	for(T item: fast_q){
		std::cout << item << " ";
	}
	std::cout << std::endl;
}