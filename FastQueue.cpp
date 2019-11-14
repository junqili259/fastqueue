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
	int size_copy = size_of_container;

 //if container is empty
	if (number_of_elements == 0)
	{
		fast_q[head_index] = element;
		number_of_elements++;
	}

 //if container is full?
	else if(size_of_container == number_of_elements)
	{
		int size_of_container_copy = size_of_container;
		int new_size = size_of_container*2;
		std::vector<T> temp(new_size,0);
		
		/*
		//insert all elements from 0 to tail_index into temp container
		for (int i = 0; i <= tail_index; i++)
		{
			temp[i] = fast_q[i];
		}
		
		//insert all elements from head_index to last element into temp container
		for (int j = new_size; new_size - head_index <= j; j--)
		{
			temp[j] = fast_q[size_of_container_copy];
			size_of_container_copy--;
		}
		
		//swap temp container to fast_q
		std::swap(fast_q, temp);
		
		//insert new element
		fast_q[++tail_index] = element;
		number_of_elements++;
		
		head_index = tail_index + size_of_container;
		size_of_container = new_size;
		*/

		/*
		int count = 0;
		for (int i = head_index; i < size_of_container; i++)
		{
			temp[count] = fast_q[i];
			count++;
		}
		*/

		for (int i = 0; i < size_of_container; i++)
		{
			temp[i] = fast_q[(head_index+number_of_elements)%size_of_container];
			head_index++;
		}
		head_index = 0;
		tail_index = size_of_container - 1;
		size_of_container = new_size;



		std::swap(fast_q, temp);

		fast_q[++tail_index] = element;
		number_of_elements++;
		
		//print();
		
		
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

	//if queue is empty, do nothing
	if (!size() == 0)
	{
		fast_q[head_index] = 0;
		number_of_elements--;
		head_index++;
		if (head_index == size_of_container)
		{
			head_index = 0;
		}
		
	}
}//end dequeue()



//returns reference to head_index
//throws out of range if container is empty
template<typename T>
T& FastQueue<T>::head(){
	try
	{
		if (size() == 0){
			throw std::out_of_range("OUT OF RANGE ERROR: empty container");
		}
		else
			return fast_q[head_index];
	}
	catch(std::out_of_range& error_msg)
	{
		std::cerr << error_msg.what() << std::endl;
	}
}//end head()

//returns reference to the last element of the queue
//throws out of range if the container is empty
template<typename T>
T& FastQueue<T>::tail(){
	try{
		//check if empty, if so then throw error
		if(size() == 0){
			throw std::out_of_range("OUT OF RANGE ERROR: empty container");
		}
		else
			//if not empty, return element at tail_index
			return fast_q[tail_index];
	}
	catch(const std::out_of_range& error_msg)
	{
		//error message if exception throw
		std::cerr << error_msg.what() << std::endl;
	}
}//end tail()


//returns reference to the index-th element of the queue.
//throws out of range if container size is less than index
template<typename T>
T& FastQueue<T>::at(int index){
	try
	{
		//throw out of range if there are less elements than index
		if (size() <= index){
			throw std::out_of_range("OUT OF RANGE ERROR: container size is less than index");
		}
		else
		{
			if (head_index + index < size_of_container)
			{
				return fast_q[head_index + index];
			}
			else
			{
				return fast_q[(head_index + index) - size_of_container];
			}
		}
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}//end at()


//returns the number of elements in container
template<typename T>
int FastQueue<T>::size(){
	return number_of_elements;
}//end size()


//returns size of allocated memory in terms of elements
template<typename T>
int FastQueue<T>::capacity(){
	return size_of_container;
}//end capacity()


//shrinks the size of allocated memory to exactly fit the elements currently in queue
template<typename T>
void FastQueue<T>::shrink_to_fit(){
	std::vector<T> new_v(number_of_elements);

	for (int i = 0; i < number_of_elements; i++)
	{
		new_v[i] = fast_q[(head_index + number_of_elements) % size_of_container];
	}

	std::swap(fast_q, new_v);

	head_index = 0;
	tail_index = number_of_elements - 1;

	print();
	
	
	
}//end shrink_to_fit()




//For debugging purposes only
//prints entire container
template<typename T>
void FastQueue<T>::print(){
	for(T item: fast_q){
		std::cout << item << " ";
	}
	std::cout << std::endl;
}