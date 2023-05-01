#pragma once
#include <iostream>

class circular_queue
{
public:
	circular_queue();
	~circular_queue();
	bool push(const int& item);
	bool pop(int& item);
	bool is_empty() const;
	bool is_full() const;
private:
	size_t increment(size_t index) const;
	std::atomic<size_t> m_read_index;
	std::atomic<size_t> m_write_index;
	static const int SIZE = 11;
	int m_data[SIZE];
};

// C++ Atomic Variables: https://studiofreya.com/cpp/volatile-and-atomic-variables-in-cpp/ 
//Objects of type Atomic are protected from data races, and if one thread tries to write to atomic objects 
//while another thread is extracting values from it, the result is well defined.This comes from the fact 
//that atomic operations modify data on a single clock tick. This makes it impossible for other threads
// to access the variable at the same time. If the variable cannot be modified during a single tick,
// the compiler will insert thread guards before and after the variable.
// https://en.cppreference.com/w/cpp/atomic/atomic
