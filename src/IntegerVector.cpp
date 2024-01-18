#include "IntegerVector.h"

/*
* Main consturctor - gets size and value and initalizes the vector.
*/
IntegerVector::IntegerVector(size_t size = 0, int value = 0) : _size(size), _capacity(size) {

	_data = new int[_capacity];
	for (size_t index = 0; index < _size; index++) {
		_data[index] = value;
	}

}

/*
* Size consturctor - gets size and initalizes the vector with size * elements with the value 0.
*/
IntegerVector::IntegerVector(size_t size) : _size(size), _capacity(size) {

	_data = new int[_capacity];

	for (size_t index = 0; index < _size; index++) {
		_data[index] = 0;
	}
}

/*
* Copy consturctor - copy the argument vector data into the created vector.
*/
IntegerVector::IntegerVector(const IntegerVector& other) {

	_size = other._size;
	_capacity = other._capacity;
	_data = new int[_capacity];
	copy_data(other._data, &_data, other._size);

}

/*
* Move consturctor - move the argument vector's data control into the created vector.
*/
IntegerVector::IntegerVector(IntegerVector&& other) noexcept {

	_size = other._size;
	_capacity = other._capacity;
	_data = other._data;
	other._data = nullptr;
}

/*
* Initializer list consturctor - construct the vector's data from initializer values.
*/
IntegerVector::IntegerVector(const std::initializer_list<int> initializer) {

	_size = initializer.size();
	_capacity = _size;
	_data = new int[_capacity];
	copy_data(initializer.begin(), &_data, _size);
}

/*
* Destructor - deallocate vector's memory
*/
IntegerVector::~IntegerVector() {

	if (_data) {

		delete[] _data;
	}
}

/*
* operator[] - for random access to vector's values.
*/
int& IntegerVector::operator[] (size_t index) {

	if (index < 0 || index > _size - 1) {

		throw std::out_of_range("Array index out of bounds.");
	}
	return *(_data + index);
}

/*
* const operator[] - for random access to vector's values without changing any of the data.
*/
const int& IntegerVector::operator[] (size_t index) const {

	if (index < 0 || index > _size - 1) {

		throw std::out_of_range("Array index out of bounds.");
	}

	return *(_data + index);
}

/*
* operator= - copy the argument vector data into the vector and deallocate previous data.
*/
IntegerVector& IntegerVector::operator= (const IntegerVector& other) {

	if (this != &other) {

		_size = other._size;
		_capacity = other._capacity;
		if (_data)
			delete[] _data;
		_data = new int[_capacity];
		copy_data(other._data, &_data, other._size);
	}

	return *this;
}

/*
* operator= - moves the argument vector data control into the vector and deallocate previous data.
*/
IntegerVector& IntegerVector::operator= (IntegerVector&& other)noexcept {

	if (this != &other) {

		delete[] _data;
		_size = other._size;
		_capacity = other._capacity;
		_data = other._data;
		other._data = nullptr;
	}

	return *this;
};

/*
* operator= - copy the initializer list data into the vector and deallocate previous data.
*/
IntegerVector& IntegerVector::operator= (const std::initializer_list<int> initializer) {
	_size = initializer.size();
	_capacity = _size;
	delete[] _data;
	_data = new int[_capacity];
	copy_data(initializer.begin(), &_data, _size);
	return *this;
};

/*
* swap - swaps the data between two vectors.
*/
void IntegerVector::swap(IntegerVector& other) {

	//swap capacity
	other._capacity += _capacity;
	_capacity = other._capacity - _capacity;
	other._capacity -= _capacity;

	//swap size
	other._size += _size;
	_size = other._size - _size;
	other._size -= _size;

	//swap data
	int* temp = other._data;
	other._data = _data;
	_data = temp;

	temp = nullptr;
}

/*
* push_back - append a value to the end of the vector. if the vector's capacity is not enaugh,
* than it will allocate more memory.
*/
void IntegerVector::push_back(const int& value) {

	if (_size == _capacity) {

		if (_capacity == 0) {

			_capacity = 2;
			_data = new int[_capacity];
		}

		else {
			//allocate more memory and copy data.
			_capacity = _capacity < 128 ? _capacity * 2 : _capacity * 1.5;
			int* newData = new int[_capacity];
			copy_data(_data, &newData, _size);
			delete[] _data;
			_data = newData;
			newData = nullptr;
		}
	}

	*(_data + _size) = value;
	_size++;

}

/*
* clear - destroy all data
*/
void IntegerVector::clear() noexcept {

	_size = 0;
	_capacity = 0;
	if (_data)
		delete[] _data;
	_data = nullptr;
}

/*
* resize - change the size of the vector to newSize
*/
void IntegerVector::resize(size_t newSize) {

	if (newSize > _capacity) {
		//allocate more memory and copy data.
		_capacity = newSize < 128 ? newSize * 2 : newSize * 1.5;
		int* temp = _data;
		_data = new int[_capacity];
		copy_data(_data, &temp, _size);
		delete[] temp;
	}

	//initialize the remaining values to 0.
	for (; _size < newSize; _size++) {
		_data[_size] = 0;
	}

	_size = newSize;
}

void IntegerVector::resize(size_t newSize, const int& value = 0) {

	if (newSize > _capacity) {
		//allocate more memory and copy data.
		_capacity = newSize < 128 ? newSize * 2 : newSize * 1.5;
		int* temp = _data;
		_data = new int[_capacity];
		copy_data(_data, &temp, _size);
		delete[] temp;
	}
	//initialize  the remaining values to value.
	for (; _size < newSize; _size++) {
		_data[_size] = value;
	}
}

// copy_data - a private function that copy vectors data to another vector data.
void IntegerVector::copy_data(const int* a, int** b, const size_t& size) {

	for (size_t i = 0; i < size; i++) {
		*(*b + i) = *(a + i);
	}
}

/*
* operator== - compares std::vector of integers to IntegerVector object to compare results for tests purposes.
*/
bool IntegerVector::operator==(const std::vector<int>& other) const {

	//compare sizes
	if (_size != other.size()) return false;

	//compare values
	for (size_t i = 0; i < _size; i++) {
		if (_data[i] != other[i]) {
			return false;
		}
	}

	return true;
}

/*
* erase - erases data from position to the end of the vector.
* throws - out of range excepion if position is not a valid position.
*/
int& IntegerVector::erase(const size_t position) {

	if (position < 0) {
		throw std::out_of_range("cannot seek vector before begin.");
	}
	if (position > _size - 1) {
		throw std::out_of_range("cannot seek vector after end.");
	}
	for (size_t i = position; i < _size - 1; i++) {
		_data[i] = _data[i + 1];
	}
	_size--;
	return _data[_size - 1];
}

/*
* erase - erases data from first position to last position of the vector.
* throws - out of range excepion if first or last are not a valid position.
*/
int& IntegerVector::erase(const size_t first, const size_t last) {

	if (first < 0) {
		throw std::out_of_range("first position must be positive integer within vector size");
	}
	if (last > _size - 1) {
		throw std::out_of_range("last position exceeds vector size");
	}
	if (first > last) {
		throw std::out_of_range("last position must be greater or equal first position");
	}
	size_t dif = (last - first);
	for (size_t i = first; i + dif < _size; i++) {
		_data[i] = _data[i + dif];
	}
	_size -= dif;
	return _data[_size - 1];
}

/*
* insert - inserts length times the value to the vector.
* throws - out of range excepion if position is not a valid position.
*/
void IntegerVector::insert(size_t position, size_t length, const int& value) {

	if (position < 0) {
		throw std::out_of_range("position must be positive integer within vector size");
	}

	if (position > _size) {
		throw std::out_of_range("position exceeds vector size");
	}

	//if the poistion to insert value is the last position, than its simply push_back operation
	if (position == _size) {
		while (length-- > -1) {
			push_back(value);
		}
	}

	int* temp = _data;

	if (_size + length > _capacity) {
		//allocate more memory and copy previous data
		_capacity = (_size + length) > 128 ? (_size + length) * 2 : (_size + length) * 1.5;
		_data = new int[_capacity];
		copy_data(temp, &_data, position);
	}

	//insert length times value th position
	for (size_t i = position; i < position + length; i++) {
		*(_data + i) = value;
	}

	//copy the reamining values into the vector
	int* newData = _data + (position + length);
	copy_data((temp + position), &newData, _size - position);
	_size += length;

}