// Circular_Buffer.h -- starter code
// Tanner Cox - CS-318 - Fall 2024

/*  REQUIREMENTS NOTES:

	Functions that need to be written have a comment above the function or constructor

	Do not add any additional instance variables

	You may include the implementation/definition of functions in this header file
		-- no need to create a separate .cpp file
*/

#ifndef _CIRCULAR_BUFFER_H
#define _CIRCULAR_BUFFER_H

#include <array>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

template<typename T, int cap, typename Container = std::array<T, cap> >
class CircularBuffer {
public:
	//type T will be the data type in the Container declared in the template
	using value_type = T;

	//COMPLETE CONSTRUCTOR BELOW
	CircularBuffer() : _head(0), _tail(0), _size(0), _current(0), _capacity(cap) {};

	//COMPLETE THE FUNCTIONS BELOW USING THE FUNCTION PROTOTYPE GIVEN
	T& head() { return c[_head]; }
	T& tail() { return c[_tail]; }
	T const& head() const { return c[_head]; }
	T const& tail() const { return c[_tail]; }

	void push_back(T val) noexcept {
			// Insert the new value at tail
		c[_current] = val;	
			// Move tail forward
		_tail = _current;	
			// Track next write position (also works: _current = (_current + 1) % _capacity;)
		_current++;
			// Increase the size when buffer is not full
		if (_size != _capacity) {	
			_size++;
		}	// Move head forward
		else {	
			_head = (_head + 1) % _capacity;
		}
			// Move write position back to start (might not be needed)
		if (_current == _capacity) { 
			_current = 0;
		}
	}

	void pop() {
		if (_size <= 0) {
			throw std::underflow_error("pop(): empty buffer");
		}
			// Move head forward removing the oldest element
		_head = (_head + 1) % _capacity; 
			// Decrease size
		_size--;  
	}

	// COMPLETE THE FUNCTIONS BELOW
	int size() const noexcept {
		return _size;
	}

	int capacity() noexcept {
		return _capacity;
	}

	// Return true if buffer is empty
	bool empty() const noexcept {
		if (_size == 0) { return true; }
		else { return false; }
	}

	// Return true if buffer is full
	bool full() const noexcept {
		if (_size == _capacity) { return true; }
		else { return false; }
	}

	typename Container::iterator begin() { return c.begin(); }

	typename Container::iterator end() { return c.end(); }

	// COMPLETE THE OVERLOADED << OPERATOR
	friend std::ostream& operator<<(std::ostream& os, CircularBuffer& buf) {
		os << "Buffer Info: head: " << buf._head
			<< ", tail: " << buf._tail
			<< ", current: " << buf._current
			<< ", capacity: " << buf._capacity 
			<< ", size: " << buf._size << endl;
		
		os << " Container: ";
		for (int i = 0; i < buf._capacity; ++i) {
			os << buf.c[i] << " ";
		}
		os << "\n\n";
		return os;
	}

private:
	Container c;	// Will be std::array<T, cap>
	int _head;		// Oldest item in buffer
	int _tail;		// Newest item in buffer
	int _size;		// # of elem in buffer
	int _current;	// Next write position in buffer
	int _capacity;
};
#endif
