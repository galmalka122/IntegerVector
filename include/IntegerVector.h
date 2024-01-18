#ifndef INTEGERVECTOR_H
#define INTEGERVECTOR_H

#include <iostream>
#include <vector>

//A class that represents an integer vector that should operate like std::vector<int> for several functions
class IntegerVector {

private:

	size_t _size;//the size of the vector
	size_t _capacity;//the capacity of the vector

	int* _data;//the vector's data

	void copy_data(const int* a, int** b, const size_t& size);

public:

	IntegerVector() : _size(0), _capacity(0), _data(nullptr) {};
	explicit IntegerVector(size_t, int);
	IntegerVector(size_t);
	IntegerVector(const IntegerVector&);
	IntegerVector(const std::initializer_list<int>);
	IntegerVector(IntegerVector&&) noexcept;
	~IntegerVector();

	auto operator<=>(const IntegerVector&) const = default;
	bool operator==(const std::vector<int>&) const;

	IntegerVector& operator= (const IntegerVector&);
	IntegerVector& operator= (IntegerVector&&)noexcept;
	IntegerVector& operator= (const std::initializer_list<int>);

	int& operator[] (size_t);
	const int& operator[] (size_t) const;
	const IntegerVector& operator[](const size_t& index) const { return this->_data[index]; }

	void push_back(const int&);
	void pop_back() { _size--; };

	void swap(IntegerVector&);

	void resize(size_t);
	void resize(size_t, const int&);

	void insert(size_t position, size_t index, const int& value);

	int& erase(const size_t position);
	int& erase(const size_t first, const size_t last);
	void clear() noexcept;

	bool empty() { return _size == 0; };

	const int& back() const { return _data[_size - 1]; };
	const int* data() const noexcept { return _data; };

	int* data() noexcept { return _data; };
	int& back() { return _data[_size - 1]; };

	int capacity() { return _capacity; };
	int size() { return _size; };
};

#endif // !INTEGERVECTOR_H
