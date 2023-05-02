// CircularFIFOQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include "circular_queue.h"

void push_function(circular_queue& a_circular_queue);
void pop_function(circular_queue& a_circular_queue);
const int MAX_VALUE = 9;
int main()
{
	circular_queue m_circular_queue;
	auto publisher =
		std::thread(push_function, std::ref(m_circular_queue));
	publisher.join();

	auto consumer =
		std::thread(pop_function, std::ref(m_circular_queue));
	consumer.join();

	return 0;
}

void push_function(circular_queue& a_circular_queue)
{
	int count = 0;
	while (count <= MAX_VALUE)
	{
		if (a_circular_queue.push(count))
		{
			std::cout << "Pushed " << count << " to the queue" << std::endl;
			count++;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
void pop_function(circular_queue& a_circular_queue)
{
	int value = 0;
	while (value < MAX_VALUE)
	{
		if (a_circular_queue.pop(value))
		{
			std::cout << "Popped " << value << " from the queue" << std::endl;
			value++;
		}
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
}
